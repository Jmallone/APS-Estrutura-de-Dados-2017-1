#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"TAD-setor.h"
#include"TAD-arquivo.h"

typedef struct{
    char nome[40];
    void* disco;
    NoSetor* livres;
    NoArquivo* arquivos;
    unsigned long tamDisco;
    unsigned long espacoLivre;
    unsigned long espacoOcupado;
    unsigned long qtdeArquivos;
}Disco;

typedef enum{
    SUCESSO = 0,
    ESPACO_INSUFICIENTE,
    ARQUIVO_INEXISTENTE
}TipoRetorno;

Disco* disco_cria(char* nome, unsigned long tamanho);
TipoRetorno disco_grava(Disco* d, char* nomeArquivo); //nome arquivo deve conter o caminho absoluto ou relativo do arquivo
TipoRetorno disco_remove(Disco* d, char* nome); //somente o nome do arquivo sem o caminho
TipoRetorno disco_recupera(Disco* d, char* nome, FILE* arquivoFisico);
unsigned long Tamanho_arquivo(char *nomeArquivo);

///Implementa��es

unsigned long Tamanho_arquivo(char* nomeArquivo) {
  char modo[3] = "rb";

  FILE* Arquivo = fopen(nomeArquivo, modo) ;
  fseek(Arquivo,0,SEEK_END);
  unsigned long tamArquivo = ftell(Arquivo);
  fseek(Arquivo,0,SEEK_SET); // * usando isso caso o ponteiro fique no final do arquivo. ai retorna para o inicio testar
  fclose(Arquivo) ;
  
  return  tamArquivo;
}

Disco* disco_cria(char* nome, unsigned long tamanho){

  Disco *d = (Disco*)malloc(sizeof(Disco));
  

  d->disco = (void*)malloc(tamanho) ;

  d->livres = criar_NoSetor();//Ja cria a Sentinela
  
  adicionar_NoSetor(d->livres, 0, tamanho);//Adiciona o Tamanho livre 




  d->arquivos = criar_NoArquivo();
   strcpy(d->arquivos->nome, "Sentinela");

  d->tamDisco = d->espacoLivre = tamanho ;
  
  d->espacoOcupado = d->qtdeArquivos = 0 ;
  
  strcpy(d->nome, nome);

  return d ;
}

TipoRetorno disco_grava(Disco* d, char* nomeArquivo){
	 
   unsigned long tamRes = 0;
   int tmp = 1 ;


	unsigned long SizeFile = Tamanho_arquivo(nomeArquivo);
	 printf("\n Tamanho dessa porra: %d \n", SizeFile);

  FILE* Arquivo = fopen(nomeArquivo, "rb") ;


	if( SizeFile > ( (d->tamDisco) - (d->espacoOcupado) )) return ESPACO_INSUFICIENTE; //Verifica se existe espa�o

  adicionar_NoArquivo(d->arquivos, nomeArquivo, SizeFile); //Cria uma struct Arquivo e Aloca dentro de Arquivos

  tamRes = SizeFile;

  while(tmp){

    adicionar_NoSetor(d->arquivos->prox->setores, 0, 0); // cria um n� em setores no Arquivos
    editar_NoSetor(d->arquivos->prox->setores, d->livres->prox->inicio, 0); // editar o n� de acordo com o diagrama

    if( ((d->livres->prox->fim) - (d->livres->prox->inicio)) >= tamRes ){ // Verifica se o n� que esta no livres tem espa�o suficiente para alocar os bits
      
      editar_NoSetor(d->arquivos->prox->setores, d->arquivos->prox->setores->prox->inicio, (d->arquivos->prox->setores->prox->inicio)+tamRes);

      if(d->livres->prox->inicio == d->arquivos->prox->setores->prox->inicio ){ // Verificar se � um N� no Livre que ainda esta 'virgem'
        
        d->livres->prox->inicio = d->arquivos->prox->setores->prox->fim;
       
        if(d->livres->prox->inicio == d->livres->prox->fim){// veririca se a capacidade do n� nao esta cheia
            /* Apagar N� no Livre, fazer essa fun��o*/
          apagar_NoSetor(d->livres);
        }

      }

      fread(d->disco+(d->arquivos->prox->setores->prox->inicio), (d->arquivos->prox->setores->prox->fim)-(d->arquivos->prox->setores->prox->inicio), 1, Arquivo);
      d->espacoLivre = d->espacoLivre - SizeFile;
      tmp = 0;
      
    }else{

      d->arquivos->prox->setores->prox->fim = d->livres->prox->fim;
      fread(d->disco+(d->arquivos->prox->setores->prox->inicio), (d->arquivos->prox->setores->prox->fim)-(d->arquivos->prox->setores->prox->inicio), 1, Arquivo);
      apagar_NoSetor(d->livres);
      
    }

  } 

  return SUCESSO;
}

TipoRetorno disco_recupera(Disco* d, char* nome, FILE* arquivoFisico){

  NoSetor *Aux = d->arquivos->prox->setores->ant;

  while(!(d->arquivos->prox->setores->prox == d->arquivos->prox->setores)){

    fwrite(d->disco+(d->arquivos->prox->setores->ant->inicio), (d->arquivos->prox->setores->ant->fim)-(d->arquivos->prox->setores->ant->inicio), 1, arquivoFisico);

    Aux->ant->prox = d->arquivos->prox->setores;
    d->arquivos->prox->setores->ant = Aux->ant;
    free(Aux);
    Aux = d->arquivos->prox->setores->ant;

  }

  return SUCESSO;
}