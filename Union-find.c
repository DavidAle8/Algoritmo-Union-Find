#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int ITEM;

typedef struct estrutura{
	
	ITEM item;
	struct estrutura *prox;
	struct estrutura *MeuRepresentante;
	
}NO;

typedef struct{
	
	NO *cabeca;
	NO *cauda;
	long tamanho;
	
}CONJUNTO;

void inicializar (CONJUNTO *l){
	
	l->cabeca = NULL;
	l->cauda = NULL;
	l->tamanho = 0;
}

long tamanho(CONJUNTO *l){

    return l->tamanho;
}

NO *MakeSet(CONJUNTO *l, ITEM item){
	
	NO *no = (NO*)malloc(sizeof(NO));
	
	if (no == NULL){
		
		printf("Não foi possível alocar memória para o nó!!\n");
        exit(EXIT_FAILURE);
	}

	no->item = item;
	no->prox = NULL;
	   
	if (l->cabeca == NULL){
		
		l->cabeca = no;
		l->cauda = no;
		no->MeuRepresentante = l->cabeca;
		l->tamanho++;
	}
	
	return no;
}

NO* Find(NO *no) {
	
    return no->MeuRepresentante;
}

void Union(CONJUNTO *a, CONJUNTO *b){

	NO *RepresentanteA = Find(a->cabeca);
	NO *RepresentanteB = Find(b->cabeca);
	
	if (RepresentanteA == RepresentanteB){
		printf("Os elementos selecionados já estão unidos!");
		exit(EXIT_FAILURE);
	}
	
	if (tamanho(a) >= tamanho(b)){
		
		//RepresentanteB = RepresentanteA;
		
		RepresentanteB->MeuRepresentante = RepresentanteA;
	//	RepresentanteA->prox = b->cabeca;
	    a->tamanho += b->tamanho;
	    a->cauda->prox = b->cabeca;
	    a->cauda = b->cauda;
	    b->tamanho = 0;
	    free(b);
	}
	
	else{
		
		//RepresentanteA = RepresentanteB;
		
		RepresentanteA->MeuRepresentante = RepresentanteB;
	//	RepresentanteB->prox = a->cabeca;
  		b->tamanho += a->tamanho;
	    b->cauda->prox = a->cabeca;
	    b->cauda = a->cauda;
	    a->tamanho = 0;
	    free(a);	
	}		
}

int main(){
	
	return 0;
}
