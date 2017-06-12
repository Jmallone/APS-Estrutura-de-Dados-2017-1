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
    FALSE = 0,
    TRUE = 10
}Boolean;

typedef enum{
    SUCESSO = 0,
    ESPACO_INSUFICIENTE,
    ARQUIVO_INEXISTENTE
}TipoRetorno;

Disco* disco_cria(char* nome, unsigned long tamanho);
TipoRetorno disco_grava(Disco* d, char* nomeArquivo); //nome arquivo deve conter o caminho absoluto ou relativo do arquivo
TipoRetorno disco_remove(Disco* d, char* nome); //somente o nome do arquivo sem o caminho
TipoRetorno disco_recupera(Disco* d, char* nome, FILE* arquivoFisico);
unsigned long *Tamanho_arquivo(char *nomeArquivo);

///Implementações

unsigned long* Tamanho_arquivo(char* nomeArquivo) {
  if (nomeArquivo == NULL) return(unsigned long*) -1;
  /// r ( leitura - Arq deve existir )
  /// w ( escrita/remove )
  /// a ( escrita/add )
  /// + ( /leitura - combine com algum outro anterior )
  /// b ( /binário - combine com algum outro anterior )
  char modo[3] = "rb";
  //char nomeArquivo[100] = {"C:\\Users\\Daniel A\\Desktop\\APS\\arquivo_teste.jpg"};

  FILE* Arquivo = fopen(nomeArquivo, modo);

  if (Arquivo == NULL) return (unsigned long*)-1;

  /// Calculado o tamanho do arquivo
  /// fseek(Arquivo,NumBytes,inicio) ;
  fseek(Arquivo,0,SEEK_END);
  /// int ftell(Arquivo) ; retorna a posição do ponteiro no arquivo
  int tamArquivo = ftell(Arquivo);
  fclose(Arquivo) ;
  
  return (unsigned long*) tamArquivo;
}

Disco* disco_cria(char* nome, unsigned long tamanho){
  Disco *d = (Disco*)malloc(sizeof(Disco));
  

  d->disco = (void*)malloc(tamanho) ;

  d->livres = criar_NoSetor();//Ja cria a Sentinela
  
  adicionar_NoSetor(d->livres, 0, tamanho);//vereficar se tem que colocar tamanho-1

  d->arquivos = criar_NoArquivo();

  d->tamDisco = d->espacoLivre = tamanho ;
  
  d->espacoOcupado = d->qtdeArquivos = 0 ;
  
  strcpy(d->nome, nome);

  return d ;
}

TipoRetorno disco_grava(Disco* d, char* nomeArquivo){
	
	unsigned long* SizeFile = Tamanho_arquivo(nomeArquivo);
	if( *SizeFile > ( (d->tamDisco) - (d->espacoOcupado) )) return 1; //Verifica se existe espaço
	
	
	
	
	
	
}


