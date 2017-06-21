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

/*  printf ("Verificando NoSetor\n") ;

  printf ("Endereco [sentinela] %d\n", Disk->livres->inicio) ;
  printf ("Endereco [Sentinela] %d\n", Disk->livres->fim) ;

  printf ("Endereco [0] %d\n", Disk->livres->prox->inicio) ; 
  printf ("Endereco [0] %d\n", Disk->livres->prox->fim) ;
  //
  printf ("Endereco [1] %d\n", Disk->livres->prox->prox->inicio) ;
  printf ("Endereco [1] %d\n", Disk->livres->prox->prox->fim) ;
  //
  printf ("Endereco [Final] %d\n", Disk->livres->ant->inicio) ;
  printf ("Endereco [Final] %d\n", Disk->livres->ant->fim) ;*/

	char teste[]= {"a.txt"};
  

  printf("\n Disco Grava Retorno: %d \n ", disco_grava(Disk, teste) );

  printf("\n Nome do Arquivo [ %s ] \n ",Disk->arquivos->nome );
  printf("\n Nome do Arquivo_Prox [ %s ] \n ",Disk->arquivos->prox->nome );
  printf("\n Nome do Arquivo_ANT [ %s ] \n ",Disk->arquivos->ant->nome );

  printf("\n");

  printf ("Verificando NoSetorLIVRE\n") ;

  printf ("Endereco [sentinela] %d\n", Disk->livres->inicio) ;
  printf ("Endereco [Sentinela] %d\n", Disk->livres->fim) ;

  printf ("Endereco [0] %d\n", Disk->livres->prox->inicio) ; 
  printf ("Endereco [0] %d\n", Disk->livres->prox->fim) ;
  //
  printf ("Endereco [1] %d\n", Disk->livres->prox->prox->inicio) ;
  printf ("Endereco [1] %d\n", Disk->livres->prox->prox->fim) ;
  //
  printf ("Endereco [Final] %d\n", Disk->livres->ant->inicio) ;
  printf ("Endereco [Final] %d\n", Disk->livres->ant->fim) ;

  FILE* Arquivo = fopen("seven.txt", "w+b");

  disco_recupera(Disk,"a",Arquivo);


}

