

#define MAX 50

typedef int TIPOCHAVE;

typedef struct list{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int nroElem;
}LISTA;

void incializarLista(LISTA* l){
    l->nroElem = 0;
}