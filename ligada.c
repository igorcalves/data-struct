	#include <stdio.h>
	#include <stdbool.h>

	#define MAX 50
	#define INVALIDO -1

	typedef int TIPOCHAVE;


	typedef struct {
		TIPOCHAVE chave;
	}REGISTRO;

	typedef struct{
		REGISTRO reg;
		int prox;
	}ELEMENTO;

	typedef struct{
		ELEMENTO A[MAX];
		int inicio;
		int dispo;
	}LISTA;

	void incializarLista(LISTA* l){
		int i;
		for(i=0; i<MAX-1; i++)
			l->A[i].prox = i + 1 ;
		l->A[MAX -1].prox = INVALIDO; // proximo valor do nó antes do maximo é 50 logo é invalido
		l->inicio = INVALIDO; // o inicio é invalido por que a lista esta vazia
		l ->dispo = 0; // primeira posição disponivel para inserir um registro
	}

	int tamanho (LISTA * l){
		int i = l->inicio;
		int tam = 0;
		while(i != INVALIDO){
			tam++;
			i = l->A[i].prox;
		}
		return tam;
	}

<<<<<<< HEAD
int buscaSequencialOrd(LISTA* l, TIPOCHAVE ch){
	int i = l->inicio;
	while(i != INVALIDO && l->A[i].reg.chave < ch)
		i = l->A[i].prox;
	if(i != INVALIDO && l->A[i].reg.chave == ch)
		return i;
	else return INVALIDO;
}

int obterNO(LISTA* l){
	int resultado = l->dispo;
	if(l->dispo != INVALIDO)
		l->dispo = l->A[l->dispo].prox;
	return resultado;
}

bool inserirElemListaOrd(LISTA* l, REGISTRO reg){
	if(l->dispo == INVALIDO) return false;
	int ant = INVALIDO;
	int i = l->inicio;

	TIPOCHAVE ch = reg.chave;

	while((i != INVALIDO)  && (l->A[i].reg.chave < ch)){
		ant = i;
		i = l->A[i].prox;
	}


	if(i !=INVALIDO && l->A[i].prox == ch) return false;

	i = obterNO(l);

	l->A[i].reg = reg;
	
	if(ant == INVALIDO){
		l->A[i].prox = l->inicio;
		l->inicio = i;
	}else{
		l->A[i].prox = l->A[ant].prox;
		l->A[ant].prox = i;
=======
	void exibirLista(LISTA* l){
		int i = l ->inicio;
		printf("Lista: \" ");
		while(i != INVALIDO){
			printf("%i ", l->A[i].reg.chave);
			i = l->A[i].prox;
		}
		printf("\"\n");
	}

	int buscaSequencialOrd(LISTA* l, TIPOCHAVE ch){
		int i = l->inicio;
		while(i != INVALIDO && l->A[i].reg.chave < ch)
			i = l->A[i].prox;
		if(i != INVALIDO && l->A[i].reg.chave == ch)
			return i;
		else return INVALIDO;
>>>>>>> 5e98191c79fa6e3973e8d24d2659bcf017a3c371
	}

	int obterNO(LISTA* l){
		int resultado = l->dispo;
		if(l->dispo != INVALIDO)
			l->dispo = l->A[l->dispo].prox;
		return resultado;
	}

	bool inserirElemListaOrd(LISTA* l, REGISTRO reg){
		if(l->dispo == INVALIDO) return false;


		int ant = INVALIDO;
		int i = l->inicio;

<<<<<<< HEAD
int main(){
    LISTA lista;
    incializarLista(&lista);
    
    REGISTRO r1 = {1};
    REGISTRO r2 = {4};
 	REGISTRO r3 = {3};
  
    inserirElemListaOrd(&lista, r1);
	inserirElemListaOrd(&lista, r2);
	inserirElemListaOrd(&lista, r3);
    
=======
		TIPOCHAVE ch = reg.chave;
>>>>>>> 5e98191c79fa6e3973e8d24d2659bcf017a3c371

		while((i != INVALIDO)  && (l->A[i].reg.chave < ch)){// se entrar nesse laço significa que NÃO estamos falando de um valor que está na posição de Inicio
			ant = i;
			i = l->A[i].prox;
		}

		if(i !=INVALIDO && l->A[i].prox == ch) return false;

		i = obterNO(l); // obtem lugar disponivel

		l->A[i].reg = reg; // adiciona na lista

		if(ant == INVALIDO){ // aqui definimos a primeira posição do array
			l->A[i].prox = l->inicio;// aqui teoricamente empurra os valores para frente determinando que o valor adicionado agora apronta para oque antes era o inicio
			l->inicio = i;
		}else{
			l->A[i].prox = l->A[ant].prox;
			l->A[ant].prox = i;
		}
		return true;
	} 

	void devolverNo(LISTA* l, int j){
		l->A[j].prox = l->dispo;
		l->dispo = j;
	}

	bool excluirElemLista(LISTA* l, TIPOCHAVE ch){
		int ant = INVALIDO;
		int i = l->inicio;
		while((i != INVALIDO) && (l->A[i].reg.chave < ch)){
			ant = i;
			i = l->A[i].prox;
		}
		if( i == INVALIDO || l->A[i].reg.chave != ch) return false;
		if(ant == INVALIDO) l->inicio = l->A[i].prox;
		else l->A[ant].prox = l->A[i].prox;
		devolverNo(l, i);
		return true;
	}


	void reinicializarLista(LISTA* l){
		incializarLista(l);
	}

	int main(){
		LISTA lista;
		incializarLista(&lista);
		
		
		REGISTRO r1 = {10};
		REGISTRO r2 = {25};
		REGISTRO r3 = {20};
		REGISTRO r4 = {26};
		
	
		
		inserirElemListaOrd(&lista, r1);
		
		inserirElemListaOrd(&lista, r2);
		inserirElemListaOrd(&lista, r3);
		

		exibirLista(&lista);  // Deve exibir: Lista: " 10 15 20 "

		printf("Tamanho da lista: %d\n", tamanho(&lista));  // Deve imprimir: Tamanho da lista: 3

		int busca = buscaSequencialOrd(&lista, 15);
		if (busca != INVALIDO)
			printf("Encontrado na posicao: %d\n", busca);  // Deve imprimir: Encontrado na posição: 1
		else
			printf("Nao encontrado\n");

		excluirElemLista(&lista, 15);
		exibirLista(&lista);  // Deve exibir: Lista: " 10 20 "

		return 0;
	}