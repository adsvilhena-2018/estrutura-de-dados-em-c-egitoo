#include <stdio.h>

typedef struct lista {
    int valor[100];
    int cabeca;
    int topo;
}Lista;

void cria_lista(Lista *lista) {
    lista->cabeca = -1;
    lista->topo = -1;
}

void insere_fim(int num, Lista *lista) {
    if(lista->topo == 99 && lista->cabeca == 0)
        printf("Lista cheia!");
    else {
        if (lista->topo == -1) {
            lista->topo++;
            lista->cabeca++;
            lista->valor[lista->topo] = num;
        } else {
            lista->topo++;
            lista->valor[lista->topo] = num;
        }
    }
}

int remove_inicio(Lista *lista) {
    int del = lista->valor[lista->cabeca];
    lista->cabeca++;
}

void imprime(Lista lista) {
    for(int i = lista.cabeca; i <= lista.topo;i++)
        printf("%d, ", lista.valor[i]);
}
int main() {
    Lista lista;

    cria_lista(&lista);

    insere_fim(10, &lista);
    insere_fim(20, &lista);
    insere_fim(30, &lista);
    insere_fim(40, &lista);
    insere_fim(50, &lista);
    imprime(lista);
    remove_inicio(&lista);
    remove_inicio(&lista);
    remove_inicio(&lista);
    insere_fim(60, &lista);
    printf("\n");
    imprime(lista);

    return 0;
}
