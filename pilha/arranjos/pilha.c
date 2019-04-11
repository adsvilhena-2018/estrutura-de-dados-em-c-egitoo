#include <stdio.h>

typedef struct lista {
    int valor[100];
    int ultimo;
}Lista;

void cria_lista(Lista *lista){
    lista->ultimo = -1;
}

void insere_fim(int num, Lista *lista) {
    lista->ultimo++;
    lista->valor[lista->ultimo] = num;
}

int remove_fim(Lista *lista) {
    int del = lista->valor[lista->ultimo];
    lista->ultimo--;
    return del;
}

void imprime(Lista lista) {
    for(int i = 0; i <= lista.ultimo; i++)
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
    remove_fim(&lista);
    remove_fim(&lista);
    remove_fim(&lista);
    insere_fim(50, &lista);
    printf("\n");
    imprime(lista);

    return 0;
}
