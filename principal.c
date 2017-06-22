#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"TAD-disco.h"
#include<math.h>

void arquivo_adicionar(Disco* Disk){

  char escolha[50];
  printf("\n\nQual arquivo quer Adicionar em Disco: \n");
  scanf("%s", &escolha);
  printf("\n Retorno ARQ[%s]: %d \n ",escolha, disco_grava(Disk, escolha) );

}

void arquivo_recuperar(Disco* Disk){

  char escolha[50];
  char escolha_save[50];
    printf("\n\nQual Arquivo Recuperar: \n");
    scanf("%s", &escolha);

    printf("\n\nNome de Saida?: \n");
    scanf("%s", &escolha_save);

    FILE* Arquivo= fopen(escolha_save, "w+b");
    printf("\n Retorno ARQ = %d \n", disco_recupera(Disk,escolha,Arquivo)); // Recuperar o Arquivo e Escrever no FILE

    //fclose(Arquivo);

}

void arquivo_listar(Disco* Disk){ // Colocar essa função dentro de dentro de Disco.h

  printf("\nArquivos em Disco:");
  ver_NoArquivo(Disk->arquivos);
  printf("\n");
}

void arquivo_detalhe(Disco* Disk){
    char escolha[10];
    printf("\n\nQual Arquivo visualizar em detalhe: \n");
    scanf("%s", &escolha);
    NoArquivo* auxArq = procurar_NoArquivo(Disk->arquivos, escolha);
    printf("Nome [%s] \n", auxArq->nome);
    printf("Tamanho [%d] \n", auxArq->tam);

}

void livre_ver(Disco* Disk){ // Colocar essa função dentro de dentro de Disco.h
  
 
  printf("\nIntervalo Disponivel Livre em Disco: \n");
  ver_NoSetor(Disk->livres);

}

void arquivo_ver(Disco* Disk){
  char escolha[10];
  printf("\n\nQual Arquivo Ver os Setores: \n");
  scanf("%s", &escolha);
  system("cls");
  printf("\nNos do Arquivo: [%s] \n",escolha);
  ver_NoSetor(procurar_NoArquivo(Disk->arquivos, escolha)->setores);// Colocar a maioria das funçoes no disco.h

}

void deletar_arquivo(Disco* Disk){
  char escolha[10];
  printf("\n\nQual Arquivo Deseja Remover: \n");
  scanf("%s", &escolha);
  disco_remove(Disk, escolha );

}

void disco_estatistica(Disco* Disk){
  printf("\n Nome do Disco [%s]",Disk->nome );
  printf("\n Tamanho: [%d]",Disk->tamDisco );
  printf("\n Espaco Livre: [%d]",Disk->espacoLivre );
  printf("\n Quantidade de Arquivos: [%d] \n",Disk->qtdeArquivos );


}


int main () {

  Disco* Disk = disco_cria("Disco C", 20) ; /// 219086 902094

  int escolha = 0;
  int rodando = 1;
  while(rodando){
    printf("\nEscolha uma Opcao:");
    printf("\n 1- Adicionar Arquivos");
    printf("\n 2- Recuperar um Arquivo");
    printf("\n 3- Listar Arquivos");
    printf("\n 4- Detalhe do Arquivo");
    printf("\n 5- Ver Setores Livres");
    printf("\n 6- Ver Setores de um Arquivo");
    printf("\n 7- Deletar um Arquivo");
    printf("\n 8- Estatisticas do Disco\n");
    printf("\n 9- Sair\n");

    scanf("%d",&escolha);
    system("cls");
    switch ( escolha ) {
    case 1:
        arquivo_adicionar(Disk);
      break;
    case 2:
        arquivo_recuperar(Disk);
      break;
    case 3:
      arquivo_listar(Disk);
      break;
    case 4:
       arquivo_detalhe(Disk);
      break;
    case 5:
        livre_ver(Disk);
      break;
    case 6:
       arquivo_ver(Disk);
      break;
    case 7:
       deletar_arquivo(Disk);
      break;
    case 8:
       disco_estatistica(Disk);
      break;
    case 9:
        rodando = 0;
      break;
    default:
        printf("\n ESCOLHA UMA OPCAO VALIDA! \n");
      break;
    }

  }
}

