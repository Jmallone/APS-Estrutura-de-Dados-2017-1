#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"TAD-disco.h"
#include<math.h>

int main () {
  int k = 1 ;
  //Disco* Disk = disco_cria("Disco C", pow(1024,3)*k) ; /// 1:kB 2:MB 3:GB
  Disco* Disk = disco_cria("Disco C", 15) ; /// 1:kB 2:MB 3:GB
  /// Nao colocar o expoente maior que 3, mude a constante k ;

  char teste_a[]= {"a.txt"};
  char teste_b[]= {"b.txt"};
	char teste_c[]= {"c.txt"};
  
  /* --INICIO: DEBUG PROGRAMADOR*/
  printf("\nVerificando LIVRE: \n");
  ver_NoSetor(Disk->livres);
  printf ("\nNome: %s\n", Disk->nome);
  printf("\n Disco Grava Retorno: %d \n ", disco_grava(Disk, teste_a) );
  printf("\n Disco Grava Retorno2: %d \n ", disco_grava(Disk, teste_b) );
  printf("\n Disco Grava Retorno2: %d \n ", disco_grava(Disk, teste_c) );

  printf("\n Nome do Arquivo [ %s ] \n ",Disk->arquivos->nome );
  printf("\n Nome do Arquivo_Prox [ %s ] \n ",Disk->arquivos->prox->nome );
  printf("\n Nome do Arquivo_ANT [ %s ] \n ",Disk->arquivos->ant->nome );

  printf("\n");

  printf("\nVerificando LIVRE: \n");
  ver_NoSetor(Disk->livres);
  /* --FINAL: DEBUG PROGRAMADOR*/

  FILE* Arquivo= fopen("out.txt", "w+b");



  /* --INICIO: DEBUG PROGRAMADOR*/
  char escolha[10];
    Arquivo= fopen("out.txt", "w+b");
    printf("\n\nDeseja saber os Nos de qual Arquivo & recuperalos (out.txt)?: \n");
    scanf("%s", &escolha);
    system("cls");
    printf("\nNos do Arquivo: [%s] \n",escolha);
    ver_NoSetor(procurar_NoArquivo(Disk->arquivos, escolha)->setores);
    disco_recupera(Disk,escolha,Arquivo); // Recuperar o Arquivo e Escrever no FILE

    fclose(Arquivo);
  /* --FINAL: DEBUG PROGRAMADOR*/

}

