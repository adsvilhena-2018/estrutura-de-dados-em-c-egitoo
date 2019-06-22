#include<stdlib.h>
#include<stdio.h>

typedef struct arvoreBinaria {
    int valor;
    struct arvoreBinaria *dir, *esq;
}raiz;

void inserir(raiz **arvore, int valor)
{
    raiz *aux = NULL;
    if(!*arvore) {
        aux = (raiz*)malloc(sizeof(raiz));
        aux->esq = aux->dir = NULL;
        aux->valor = valor;
        *arvore = aux;
    }

    if(valor < (*arvore)->valor) {
        inserir(&(*arvore)->esq, valor);
    }

    else if(valor > (*arvore)->valor)
    {
        inserir(&(*arvore)->dir, valor);
    }
}

void imprimir(raiz *arvore)
{
    if(arvore) {
        imprimir(arvore->esq);
        printf("%d, ",arvore->valor);
        imprimir(arvore->dir);
    }
}

void derrubar(raiz *arvore)
{
    if(arvore) {
        derrubar(arvore->esq);
        derrubar(arvore->dir);
        free(arvore);
    }
}


void main() {
    raiz *arvore = NULL;

    inserir(&arvore, 111);
    inserir(&arvore, 2);
    inserir(&arvore, 167);
    inserir(&arvore, 1050);
    inserir(&arvore, 1);
    inserir(&arvore, 13);
    inserir(&arvore, 666);
    inserir(&arvore, -250);

    imprimir(arvore);

    derrubar(arvore);
}
