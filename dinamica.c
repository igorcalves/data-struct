#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#define MAX 50
typedef int TIPOCHAVE;



typedef struct {
	TIPOCHAVE chave;
}REGISTRO;

typedef struct aux{
	REGISTRO reg;
	struct aux* prox;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
	ELEMENTO A[MAX];
	int inicio;
	int dispo;
}LISTA;


void incializarLista(LISTA* l){
	l->inicio = NULL;
}

int tamanho (LISTA* l){
	PONT end = l->inicio;
	int tam = 0;
	
	while(end != NULL){
	tam++;
	end = end->prox;
	}
	return tam;
}


void exibirLista(LISTA* l){
	PONT end = l->inicio;
	printf("Lista: \" ");
	while(end != NULL){
		printf("%i ", end->reg.chave);
		end = end->prox;
	}
	printf("\"\n");
}

PONT buscaSequencial(LISTA * l, TIPOCHAVE ch){
	PONT pos = l->inicio;
	while(pos != NULL ){
		if(pos->reg.chave == ch) return pos;
		pos = pos->prox;
	}
	return NULL;
}

PONT buscaSeqOrd(LISTA* l, TIPOCHAVE ch){
	PONT pos = l->inicio;
	while (pos != NULL && pos->reg.chave < ch) pos = pos->prox;
	if(pos != NULL  && pos ->reg.chave == ch) return pos;
	return NULL;
}
PONT buscaSequencialExc(LISTA* l, TIPOCHAVE ch, PONT* ant) {
    *ant = NULL;
    PONT atual = l->inicio;
    
    while ((atual != NULL) && (atual->reg.chave < ch)) {
        *ant = atual;
        atual = atual->prox;
    }
    
    if ((atual != NULL) && (atual->reg.chave == ch)) return atual;
    return NULL;
}

bool inserirElemListaOrd(LISTA* l, REGISTRO reg){
	TIPOCHAVE ch = reg.chave; 
	PONT ant, i;
	i = buscaSequencialExc(l,ch, &ant);
	if(i !=NULL) return false;
	i=(PONT) malloc(sizeof(ELEMENTO));
	i->reg = reg;
	if(ant == NULL) {
		i-> prox = l->inicio;
		l->inicio = i;
	}else {
		i->prox = ant->prox;
		ant->prox = i;
	}
	return true;
}	

bool excluirElemLista(LISTA * l, TIPOCHAVE ch){
	PONT ant, i;
	i = buscaSequencialExc(l,ch, &ant);
	if(i == NULL) return false;
	if(ant == NULL) l->inicio = i->prox;
	else ant ->prox = i->prox;
	free(i);
	return true;
}

void reinicializarLista(LISTA* l){
	PONT end = l->inicio;
	while (end != NULL){
		PONT apagar = end;
		end = end->prox;
		free(apagar);
	}
	l->inicio = NULL;
}

int main() {
    LISTA lista;
    incializarLista(&lista); // Inicializa a lista

    REGISTRO reg1 = {10};
    REGISTRO reg2 = {20};
    REGISTRO reg3 = {30};

    // Inserindo elementos na lista
    inserirElemListaOrd(&lista, reg2);
    inserirElemListaOrd(&lista, reg1);
    inserirElemListaOrd(&lista, reg3);

    // Exibindo a lista
    printf("Lista após inserção:\n");
    exibirLista(&lista);

    // Buscando um elemento
    int chaveBusca = 20;
    PONT encontrado = buscaSequencial(&lista, chaveBusca);
    if (encontrado != NULL) {
        printf("Elemento %d encontrado.\n", chaveBusca);
    } else {
        printf("Elemento %d não encontrado.\n", chaveBusca);
    }

    // Excluindo um elemento
    int chaveExclusao = 10;
    if (excluirElemLista(&lista, chaveExclusao)) {
        printf("Elemento %d excluído.\n", chaveExclusao);
    } else {
        printf("Elemento %d não encontrado para exclusão.\n", chaveExclusao);
    }

    // Exibindo a lista após exclusão
    printf("Lista após exclusão:\n");
    exibirLista(&lista);

    // Reinicializando a lista
    reinicializarLista(&lista);

    // Exibindo a lista após reinicialização
    printf("Lista após reinicialização:\n");
    exibirLista(&lista);

    return 0;
}
