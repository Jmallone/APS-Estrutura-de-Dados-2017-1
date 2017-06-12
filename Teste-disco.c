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

  {
  
  printf ("Nome: %s\n", Disk->nome);
  
  printf ("Verificando NoSetor\n") ;
    printf ("Endereco [Disk->livres->prox->inicio] %d\n", Disk->livres->prox->inicio) ;
    printf ("Endereco [Disk->livres->prox->inicio] %d\n", Disk->livres->prox->fim) ;
	printf ("Tamanho do Arquivo [Disk->arquivos->prox->tam] %d\n", Disk->arquivos->prox->tam) ;
/*	
  printf ("Endereco [Disk->livres->prox] %p\n", Disk->livres->prox) ;
  printf ("Endereco [Disk->livres->ant] %p\n", Disk->livres->ant) ;
  printf ("Valor [Disk->livres->inicio] %d\n", Disk->livres->inicio) ;
  printf ("Valor [Disk->livres->fim] %d\n\n", Disk->livres->fim) ;


  printf ("Endereco [Disk->livres->prox->prox] %p\n", Disk->livres->prox->prox) ;
  printf ("Endereco [Disk->livres->prox->ant] %p\n", Disk->livres->prox->ant) ;
  printf ("Valor [Disk->livres->prox->inicio] %d\n", Disk->livres->prox->inicio) ;
  printf ("Valor [Disk->livres->prox->fim] %d\n", Disk->livres->prox->fim) ;
  */
  }

  /// r ( leitura - Arq deve existir )
  /// w ( escrita/remove )
  /// a ( escrita/add )
  /// + ( /leitura - combine com algum outro anterior )
  /// b ( /binário - combine com algum outro anterior )
 
  char nomeArquivo[] = {"a.txt"};
	unsigned long* SizeFile = Tamanho_arquivo(nomeArquivo);
  printf("\nTamanho: %d \n",SizeFile);


  return 0 ;
}
