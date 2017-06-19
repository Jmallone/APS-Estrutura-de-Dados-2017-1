#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"TAD-disco.h"
#include<math.h>

int main () {
  int k = 1 ;
  //Disco* Disk = disco_cria("Disco C", pow(1024,3)*k) ; /// 1:kB 2:MB 3:GB
  Disco* Disk = disco_cria("Disco C", 10) ; /// 1:kB 2:MB 3:GB
  /// Nao colocar o expoente maior que 3, mude a constante k ;


  
  printf ("Nome: %s\n", Disk->nome);
  

  printf ("Verificando NoSetor\n") ;
  printf ("Endereco [Disk->livres->prox->inicio] %d\n", Disk->livres->prox->inicio) ;
  printf ("Endereco [Disk->livres->prox->fim] %d\n", Disk->livres->prox->fim) ;

	char teste[]= {"a.txt"};
  printf("\n Disco Grava Retorno: %d \n ", disco_grava(Disk, teste) );

  printf("\n Nome do Arquivo [ %s ] \n ",Disk->arquivos->nome );
  printf("\n Nome do Arquivo2 [ %s ] \n ",Disk->arquivos->prox->nome );
  printf ("Tamanho do Arquivo [Disk->arquivos->prox->prox->tam] %d\n", Disk->arquivos->prox->tam) ;
  printf ("\nINICIO do 1 setor de Arquivo %d\n", Disk->arquivos->prox->setores->prox->inicio) ;
  printf ("\nFinal do 1 setor de Arquivo %d\n", Disk->arquivos->prox->setores->prox->fim) ;


  return 0 ;
}
