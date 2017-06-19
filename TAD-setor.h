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

NoSetor* criar_NoSetor(){
	
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