#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"TAD-disco.h"
#include<math.h>

int main () {
  int k = 1 ;
  //Disco* Disk = disco_cria("Disco C", pow(1024,3)*k) ; /// 1:kB 2:MB 3:GB
  //Disco* Disk = disco_cria("Disco C", 219086) ; /// 1:kB 2:MB 3:GB
  Disco* Disk = disco_cria("Disco C", 15) ; /// 1:kB 2:MB 3:GB
  /// Nao colocar o expoente maior que 3, mude a constante k ;

  char teste_a[]= {"a.txt"};
  char teste_b[]= {"b.txt"};
  char teste_c[]= {"c.txt"};
	char teste_d[]= {"a_img.jpg"};
  
  /* --INICIO: DEBUG PROGRAMADOR*/
  printf("\nVerificando LIVRE: \n");
  ver_NoSetor(Disk->livres); 
  /* --FINAL: DEBUG PROGRAMADOR*/

  
  printf ("\nNome: %s\n", Disk->nome);
  printf("\n Retorno ARQ[%s]: %d \n ",teste_a, disco_grava(Disk, teste_a) );
  printf("\n Retorno ARQ[%s]: %d \n ",teste_b, disco_grava(Disk, teste_b) );
  printf("\n Retorno ARQ[%s]: %d \n ",teste_c, disco_grava(Disk, teste_c) );
  //printf("\n Retorno ARQ[%s]: %d \n ",teste_d, disco_grava(Disk, teste_d) );

  printf("\nTAM DISCO LIVRE: %d \n",Disk->espacoLivre );
   disco_remove(Disk, "a.txt" );
   disco_remove(Disk, "b.txt" );
  printf("\nTAM DISCO LIVRE: %d \n",Disk->espacoLivre );

 /* --INICIO: DEBUG PROGRAMADOR*/

  printf("\n Nome do Arquivo_ANT [ %s ] \n ",Disk->arquivos->ant->nome );
  printf("\n Nome do Arquivo [ %s ] \n ",Disk->arquivos->nome );
  printf("\n Nome do Arquivo_Prox [ %s ] \n ",Disk->arquivos->prox->nome );

  printf("\n");

 

  printf("\nVerificando LIVRE2: \n");
  ver_NoSetor(Disk->livres);
   /*--FINAL: DEBUG PROGRAMADOR*/




  /* --INICIO: DEBUG PROGRAMADOR */

  char escolha[10];
  char escolha_save[10];
    printf("\n\nNos do Arquivo & Recuperalos: \n");
    scanf("%s", &escolha);

    printf("\n\nNome de Saida?: \n");
    scanf("%s", &escolha_save);

    system("cls");
    printf("\nNos do Arquivo: [%s] \n",escolha);
    ver_NoSetor(procurar_NoArquivo(Disk->arquivos, escolha)->setores);

    FILE* Arquivo= fopen(escolha_save, "w+b");
    disco_recupera(Disk,escolha,Arquivo); // Recuperar o Arquivo e Escrever no FILE

    fclose(Arquivo);
   /*--FINAL: DEBUG PROGRAMADOR*/

}

