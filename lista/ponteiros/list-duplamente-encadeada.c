#include <stdio.h>
#include <stdlib.h>

typedef struct No{
   int valor;
   struct No *prox;
   struct No *anterior;
}no;

typedef struct  lista{
    int tamanho;
    no *inicio;
    no *fim;
}Lista;

void lista_vazia(Lista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = -1;
}

int verifica_lista(Lista *lista) {
    if(lista->inicio == NULL)
        return 1;
    else
        return 0;
}

void insere_inicio(int num, Lista *lista) {
    if(verifica_lista(lista) == 1) {
        lista->inicio = malloc(sizeof(no));
        lista->inicio->valor = num;
        lista->inicio->prox = NULL;
        lista->inicio->anterior = NULL;
        lista->fim = lista->inicio;
    } else {
        no *novo = malloc(sizeof(no));
        novo->valor = num;
        novo->anterior = NULL;
        lista->inicio->anterior = novo;
        novo->prox = lista->inicio;
        lista->inicio = novo;
    }
    lista->tamanho++;
}

void insere_fim(int num, Lista *lista) {
    if(verifica_lista(lista) == 1) {
        lista->inicio = malloc(sizeof(no));
        lista->inicio->valor = num;
        lista->inicio->prox = NULL;
        lista->inicio->anterior = NULL;
        lista->fim = lista->inicio;
    } else {
        no *novo = malloc(sizeof(no));
        lista->fim->prox = novo;
        novo->anterior = lista->fim;
        novo->valor = num;
        novo->prox = NULL;
        lista->fim = novo;
    }
    lista->tamanho++;
}

void insere(int num, Lista *lista) { //dando pau ao inserir na posição 3 ++
    int posicao;
    printf("Informe a posição a inserir o número %d: ", num);
    scanf("%d", &posicao);

    if(posicao == 1)
        insere_inicio(num, lista);
    else if(posicao == lista->tamanho + 1)
        insere_fim(num, lista);
    else {
        no *atual;
        if ((lista->tamanho - posicao) <= posicao) {
            //do fim para a posicao
            atual = lista->fim;
            for (int i = lista->tamanho; i >= posicao; i--)
                atual = atual->anterior;
        } else {
            //do inicio para posicao
            atual = lista->inicio;
            for (int i = 0; i <= posicao; i++)
                atual = atual->prox;
        }
        no *novo = malloc(sizeof(no));
        no *anterior = atual->anterior;
        novo->valor = num;
        novo->prox = atual;
        novo->anterior = atual->anterior;
        atual->anterior = novo;
        anterior->prox = novo;
    }
    lista->tamanho++;
}

void remover(Lista *lista) {
    int posicao;
    printf("Informe a posição a remover: ");
    scanf("%d", &posicao);

    no *atual;
    if (posicao == 1){
        no *del = lista->inicio;
        lista->inicio = lista->inicio->prox;
        lista->inicio->anterior = NULL;
        free(del);
    }
    else if(posicao == lista->tamanho + 1){
        no *del = lista->fim;
        lista->fim = lista->fim->anterior;
        lista->fim->prox = NULL;
        free(del);
    } else {
        if ((lista->tamanho - posicao) <= posicao) {
            //do fim para a posicao
            atual = lista->fim;
            for (int i = lista->tamanho; i >= posicao; i--)
                atual = atual->anterior;
        } else {
            //do inicio para posicao
            atual = lista->inicio;
            for (int i = 0; i <= posicao; i++)
                atual = atual->prox;
        }
        no *del = atual;
        no *anterior = atual->anterior;
        no *proximo = atual->prox;
        anterior->prox = proximo;
        proximo->anterior = anterior;
        free(del);
    }
    lista->tamanho--;
}

void imprime(Lista lista) {
    int opcao;
    printf("<1> - Impressão padrão\n<2> - Impressão reversa\n");
    scanf("%d", &opcao);
    if(opcao == 1) {
        no *atual = lista.inicio;
        while (atual != NULL) {
            printf("%d, ", atual->valor);
            atual = atual->prox;
        }
    } else {
        no *atual = lista.fim;
        while(atual != NULL){
            printf("%d, ", atual->valor);
            atual = atual->anterior;
        }
    }

}

int main() {
    Lista lista;
    int num;

    lista_vazia(&lista);
    printf("Lista vazia: %d\n", verifica_lista(&lista));
    insere_inicio(10, &lista);
    insere_inicio(20, &lista);
    //insere_fim(500, &lista);
    //insere(100, &lista);
    insere_inicio(30, &lista);
    insere_inicio(40, &lista);
    insere(100, &lista);
    //insere_inicio(50, &lista);
    //remover(&lista);
    printf("Lista vazia: %d\n", verifica_lista(&lista));
    imprime(lista);

    return 0;
}
