#include <stdio.h>
#include <stdlib.h>

typedef struct listagem {
    int vetor[1000];
    int ultimo;
}lista;

void flvazia(lista *plista) {
    plista->ultimo = -1;
}

void imprime(lista *plista) {
    for(int i = 0; i <= plista->ultimo; i++)
        printf("%d, ", plista->vetor[i]);
}

void inserefim(int num, lista *plista) {
    printf("Informe o número a inserir no fim da lista: ");
    scanf("%d", &num);
    plista->ultimo++;
    plista->vetor[plista->ultimo] = num;
}

void insere(int num, int posicao, lista *plista) {
    printf("Informe o número a inserir: ");
    scanf("%d", &num);
    printf("Informe a posição: ");
    scanf("%d", &posicao);
    for(int i = plista->ultimo; i >= posicao - 1; i--) {
        plista->vetor[i + 1] = plista->vetor[i];
    }
    plista->ultimo++;
    plista->vetor[posicao - 1] = num;

}

int remover(int posicao, int del, lista *plista) {
    del = plista->vetor[posicao];
    printf("Informe a posição a remover: ");
    scanf("%d", &posicao);
    for(int i = posicao - 1; i < plista->ultimo; i++)
        plista->vetor[i] = plista->vetor[i + 1];
    plista->ultimo--;
    return del;
}
int vazia(lista *plista) {
    if(plista->ultimo == -1)
        printf("Lista vazia!");
    else
        printf("Lista não está vazia!");

}

void menu(int num, int posicao, int del, lista *plista) {
    int bool = 1;
    int opcao;
    do{
        printf("\nInforme a opção desejada:\n1 - Criar lista vazia\n2 - Inserir um valor na posição desejada\n3 - Inserir "
               "um valor no fim da lista\n4 - Retirar um valor da lista\n5 - Checar se a lista está vazia\n6 - Imprimir\n");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                flvazia(plista);
                break;
            case 2:
                insere(num, posicao, plista);
                break;
            case 3:
                inserefim(num, plista);
                break;
            case 4:
                remover(posicao, del, plista);
                break;
            case 5:
                vazia(plista);
                break;
            case 6:
                imprime(plista);
                break;
        }

    }while(bool == 1);
}
int main() {
    int num, posicao, del;
    lista l;
    lista *plista = &l;

    flvazia(plista);
    menu(num, posicao, del, plista);

    return 0;
}
