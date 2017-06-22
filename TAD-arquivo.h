#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct noarquivo{
    char nome[40];
    unsigned long tam;
    NoSetor* setores;
    struct noarquivo* prox;
    struct noarquivo* ant;
}NoArquivo;

NoArquivo* criar_NoArquivo();
void adicionar_NoArquivo(NoArquivo* Arquivo, char* Nome, unsigned long tam);
NoArquivo* procurar_NoArquivo(NoArquivo* Arquivo, char* Nome);


NoArquivo* criar_NoArquivo(){
	
	NoArquivo* A = (NoArquivo*) malloc (sizeof(NoArquivo)) ;
	A->prox = A;
	A->ant = A;
	
	return A;
	
}

void adicionar_NoArquivo(NoArquivo* Arquivo, char* Nome, unsigned long tam){
	
  NoArquivo *Novo1 = (NoArquivo*)malloc(sizeof(NoArquivo));
  strcpy(Novo1->nome, Nome);
  Novo1->tam = tam ;

  Novo1->setores = criar_NoSetor(); // cria uma sentinela já
  
  Novo1->ant = Arquivo->prox->ant;
  Novo1->prox = Arquivo->prox;
  Arquivo->prox->ant = Novo1;
  Arquivo->prox = Novo1;
	
}

NoArquivo* procurar_NoArquivo(NoArquivo* Arquivo, char* Nome){
  NoArquivo* aux = Arquivo->prox;

  while(strcmp (aux->nome,Nome) != 0){

    aux = aux->prox;

  }

  return aux;

}

void apagar_NoArquivo(NoArquivo* Arquivo){
  NoArquivo *Aux = Arquivo->prox;
  Arquivo->prox->prox->ant = Arquivo->prox->ant; 
  Arquivo->prox = Arquivo->prox->prox;
  free(Aux);
}