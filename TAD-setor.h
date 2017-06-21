#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct nosetor{
    unsigned long inicio;
    unsigned long fim;
    struct nosetor* prox;
    struct nosetor* ant;
}NoSetor;

NoSetor* criar_NoSetor();
void adicionar_NoSetor(NoSetor* Setores, unsigned long inicio, unsigned long fim);
void editar_NoSetor(NoSetor* Setores, unsigned long inicio, unsigned long fim);
void apagar_NoSetor(NoSetor* Setores);

NoSetor* criar_NoSetor(){ //Sentinela
	
	NoSetor* s = (NoSetor*)malloc(sizeof(NoSetor));
	s->prox = s;
	s->ant = s;
	
	return s;
	
}

void adicionar_NoSetor(NoSetor* Setores, unsigned long inicio, unsigned long fim){
	
  NoSetor *Novo1 = (NoSetor*)malloc(sizeof(NoSetor));
  Novo1->inicio = inicio ;
  Novo1->fim = fim ;

  
  Novo1->ant = Setores->prox->ant;
  Novo1->prox = Setores->prox;
  Setores->prox->ant = Novo1;
  Setores->prox = Novo1;
  
	
}

void editar_NoSetor(NoSetor* Setores, unsigned long inicio, unsigned long fim){

  Setores->prox->inicio = inicio ;
  Setores->prox->fim = fim ;

}

void apagar_NoSetor(NoSetor* Setores){
  NoSetor *Aux = Setores->prox;
  Setores->prox->prox->ant = Setores->prox->ant; 
  Setores->prox = Setores->prox->prox;
  free(Aux);
}

/* Usado Pelo Programador para DEBUG -NO OFFICIAL-*/
void ver_NoSetor(NoSetor* Setores){
  NoSetor *Aux = Setores->prox;

  while( !(Aux == Setores) ){
    printf(" [ %d, %d ],", Aux->inicio, Aux->fim);
    Aux = Aux->prox;
  }
 
}
