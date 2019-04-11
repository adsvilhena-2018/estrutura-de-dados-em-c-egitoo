#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int valor;
    struct No *prox;
    struct No *anterior;
}no;

typedef struct lista {
    no *inicio;
    no *fim;
}Lista;

void cria_vazia(Lista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
}


void insere_fim(int num, Lista *lista) {
    if(lista->fim == NULL){
        lista->inicio = malloc(sizeof(no));
        lista->inicio->valor = num;
        lista->inicio->prox = NULL;
        lista->inicio->anterior = NULL;
        lista->fim = lista->inicio;

    }
    else {
        no *novo = malloc(sizeof(no));
        lista->fim->prox = novo;
        novo->anterior = lista->fim;
        novo->valor = num;
        novo->prox = NULL;
        lista->fim = novo;
    }

}

void remove_fim(Lista *lista) {
    no *del = lista->fim;
    lista->fim = lista->fim->anterior;
    lista->fim->prox = NULL;
    free(del);
}

void imprime(Lista lista) {
    no *atual = lista.inicio;
    while(atual != NULL) {
        printf("%d, ", atual->valor);
        atual = atual->prox;
    }

}

int main() {
    Lista lista;
    cria_vazia(&lista);

    insere_fim(10, &lista);
    insere_fim(20, &lista);
    insere_fim(30, &lista);
    insere_fim(40, &lista);
    insere_fim(50, &lista);
    imprime(lista);
    remove_fim(&lista);
    remove_fim(&lista);
    remove_fim(&lista);
    insere_fim(50, &lista);
    printf("\n");
    imprime(lista);
    return 0;
}
