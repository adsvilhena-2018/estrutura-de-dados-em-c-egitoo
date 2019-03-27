#include <stdio.h>
#include <stdlib.h>


typedef struct No{
    int valor;
    struct No *prox;
}no;

typedef struct lista{
    int tamanho;
    no *inicio;
}Lista;

void lista_vazia(Lista *lista) {
    lista->inicio = NULL;
    lista->tamanho = 0;
}

void insere_inicio(Lista *lista) {
    int num;
    printf("Informe o valor a inserir no início da lista: ");
    scanf("%d", &num);

    if(lista->inicio == NULL) {
        lista->inicio = malloc(sizeof(no));
        lista->inicio->prox = NULL;
        lista->inicio->valor = num;
    } else {
        no *novo = malloc(sizeof(no));
        novo->valor = num;
        novo->prox = lista->inicio;
        lista->inicio= novo;
    }
    lista->tamanho++;
}

void insere_fim(Lista *lista) {
    int num;
    printf("Informe o valor a inserir no fim da lista: ");
    scanf("%d", &num);

    if(lista->inicio == NULL) {
        lista->inicio = malloc(sizeof(no));
        lista->inicio->prox = NULL;
        lista->inicio->valor = num;
    } else {
        no *atual = lista->inicio;
        while(atual->prox != NULL)
            atual = atual->prox;

        no *novo = malloc(sizeof(no));
        atual->prox = novo;
        novo->prox = NULL;
        novo->valor = num;
    }
    lista->tamanho++;
}

void insere(Lista *lista) {
    int num, posicao;
    printf("Informe um número a inserir: ");
    scanf("%d", &num);
    printf("Informe a posição: ");
    scanf("%d", &posicao);

    no *novo = malloc(sizeof(no));
    no *atual = lista->inicio;

    if(posicao > 0 && posicao <= lista->tamanho + 1) {
        if (posicao == 1) {
            novo->prox = lista->inicio;
            lista->inicio = novo;
            novo->valor = num;
        } else {
            for (int i = 0; i < posicao - 2; i++)
                atual = atual->prox;
            novo->valor = num;
            novo->prox = atual->prox;
            atual->prox = novo;
        }
    }
    else {
        printf("Erro! Informe uma posição entre 1 e %d\n" , lista->tamanho + 1);
        insere(lista);
    }
    lista->tamanho++;
}

void remover(Lista *lista) {
    int posicao;
    printf("Informe a posição a remover: ");
    scanf("%d", &posicao);

    no *novo = malloc(sizeof(no));
    no *atual = lista->inicio;

    if(posicao == 1){
        no *del = lista->inicio;
        lista->inicio = lista->inicio->prox;
        free(del);
    }else{
        for(int i = 0; i < posicao - 2; i++)
            atual = atual->prox;
        no *del = atual->prox;
        atual->prox = atual->prox->prox;
        free(del);
    }
    lista->tamanho--;
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
        printf("\nInforme a opção:\n<1> Criar lista vazia\n<2> Inserir no começo da lista\n<3> Inserir no fim da lista\n"
               "<4> Inserir em uma posição específica\n<5> Remover uma posição específica\n<6> Exibir lista\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                lista_vazia(&lista);
                break;
            case 2:
                insere_inicio(&lista);
                break;
            case 3:
                insere_fim(&lista);
                break;
            case 4:
                insere(&lista);
                break;
            case 5:
                remover(&lista);
                break;
            case 6:
                imprime(lista);
        }
    }while(bool == 1);
}

int main() {
    Lista lista;
    menu(lista);

    return 0;
}
