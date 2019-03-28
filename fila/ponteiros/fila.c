#include <stdio.h>
#include <stdlib.h>


typedef struct No{
    int valor;
    struct No *prox;
}no;

typedef struct lista{
    int tamanho;
    no *inicio;
    no *fim;
}Lista;

void lista_vazia(Lista *lista) {
    lista->inicio = NULL;
    lista->tamanho = 0;
}

void insere_fim(Lista *lista) {
    int num;
    printf("Informe o valor a enfileirar: ");
    scanf("%d", &num);

    if(lista->inicio == NULL) {
        lista->inicio = malloc(sizeof(no));
        lista->inicio->prox = NULL;
        lista->inicio->valor = num;
        lista->fim = lista->inicio;

    } else {
        no *atual = lista->inicio;
        while(atual->prox != NULL)
            atual = atual->prox;

        no *novo = malloc(sizeof(no));
        atual->prox = novo;
        novo->prox = NULL;
        novo->valor = num;
        lista->fim = novo;
    }
    lista->tamanho++;
}

void remover(Lista *lista) {
    if(lista->inicio == NULL)
        printf("Lista vazia");
    else {
        no *del = lista->inicio;
        printf("Removendo primeira posição...");
        lista->inicio = lista->inicio->prox;
        free(del);
        lista->tamanho--;
    }
}

void imprime(Lista lista) {
    no *atual = lista.inicio;

    while(atual != NULL) {
        printf("%d, ", atual->valor);
        atual = atual->prox;
    }
}

void menu(Lista lista) {
    int opcao, bool = 1;
    do {
        printf("\nInforme a opção:\n<1> Criar lista vazia\n<2> Enfileirar\n<3> Desenfileirar\n<4> Exibir lista\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                lista_vazia(&lista);
                break;
            case 2:
                insere_fim(&lista);
                break;
            case 3:
                remover(&lista);
                break;
            case 4:
                imprime(lista);
        }
    }while(bool == 1);
}

int main() {
    Lista lista;
    lista_vazia(&lista);
    menu(lista);

    return 0;
}
