#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
    struct No *anterior;
}no;

typedef struct lista {
    int tamanho;
    no *inicio;
    no *fim;
}Lista;

void lista_vazia(Lista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

int verifica_vazia(Lista *lista) {
    if(lista->inicio == NULL)
        return 1;
    else
        return 0;
}

void insere_inicio(int num, Lista *lista) {
    if(verifica_vazia(lista) == 1) {
        lista->inicio = malloc(sizeof(no));
        lista->inicio->valor = num;
        lista->fim = lista->inicio;
        lista->inicio->anterior = lista->fim;
        lista->fim->prox = lista->inicio;
    }
    else {
        no *novo = malloc(sizeof(no));
        novo->valor = num;
        novo->prox = lista->inicio;
        lista->inicio->anterior = novo;
        novo->anterior = lista->fim;
        lista->fim->prox = novo;
        lista->inicio = novo;
    }
    lista->tamanho++;
}

void insere_fim(int num, Lista *lista) {
    if(verifica_vazia(lista) == 1)
        insere_inicio(num, lista);
    else {
        no *novo = malloc(sizeof(no));
        novo->valor = num;

        novo->prox = lista->inicio;
        novo->anterior = lista->fim;
        lista->fim->prox = novo;
        lista->fim = novo;
    }
    lista->tamanho++;
}

void insere(int num, int posicao, Lista *lista) {
    if(posicao == 1)
        insere_inicio(num, lista);
    else if(posicao == lista->tamanho + 1)
        insere_fim(num, lista);
    else {
        no *novo = malloc(sizeof(no));
        novo->valor = num;
        no *atual = lista->inicio;

        for(int i = 0; i <= posicao - 2; i++)
            atual = atual->prox;

        no *anterior = atual->anterior;
        anterior->prox = novo;
        novo->anterior = anterior;
        novo->prox = atual;
        atual->anterior = novo;
        lista->tamanho++;
    }
}

void remover(int posicao, Lista *lista) {
    if(posicao == 1) {
        no *del = lista->inicio;
        no *proximo = lista->inicio->prox;
        proximo->anterior = lista->fim;
        lista->fim->prox = proximo;
        lista->inicio = proximo;
        free(del);
    }
    else if(posicao == lista->tamanho) {
        no *del = lista->fim;
        no *anterior = lista->fim->anterior;
        anterior->prox = lista->inicio;
        lista->inicio->anterior = anterior;
        free(del);
    }
    else {
        no *atual = lista->inicio;

        for(int i = 0; i <= posicao - 2; i++)
            atual = atual->prox;

        no *proximo = atual->prox;
        no *anterior = atual->anterior;

        proximo->anterior = anterior;
        anterior->prox = proximo;
        free(atual);
    }
    lista->tamanho--;
}

void imprime(Lista lista) {
    no *atual = lista.inicio;
    do{
        printf("%d, ", atual->valor);
        atual = atual->prox;
    }while(atual != lista.inicio);
    printf("\n");
}

int main() {
    int num, posicao;
    Lista lista;
    lista_vazia(&lista);
    insere_inicio(10, &lista);
    insere_inicio(20, &lista);
    insere_fim(100, &lista);
    insere_fim(150, &lista);
    insere_inicio(30, &lista);
    insere(200, 1, &lista);
    printf("\nTamanho: %d\n", lista.tamanho);
    imprime(lista);
    remover(2, &lista);
    imprime(lista);
    return 0;
}
