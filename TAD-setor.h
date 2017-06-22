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
NoSetor* setorTolivre(NoSetor* au2, NoSetor* au); //Deus me Perdoe

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

NoSetor* setorTolivre(NoSetor* au2, NoSetor* au){
  NoSetor* aux2 = au2->prox;
  NoSetor* aux = au;
  NoSetor* auxReturn = aux->ant;

  while( aux2->inicio < aux->inicio ){

    aux2 = aux2->prox;

  }

  aux->prox = aux2;
  aux->ant = aux2->ant;
  aux2->ant->prox = aux;
  aux2->ant = aux;

  if(aux->ant->fim == aux->inicio && !(aux->ant == au2) ){
    
    aux->inicio = aux->ant->inicio;
    apagar_NoSetor(aux->ant->ant);
  }

  if(aux->prox->inicio == aux->fim && !(aux->prox == au2)){ //Verifica se nao esta Olhando o Sentinela
    aux->fim = aux->prox->fim;
    apagar_NoSetor(aux);

  }
  return auxReturn;
}