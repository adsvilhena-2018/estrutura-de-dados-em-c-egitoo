#include<stdio.h>

void minHeap(int vetor[], int tamanho, int i) {
    int menor = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < tamanho && vetor[esq] > vetor[menor])
        menor = esq;

    if (dir < tamanho && vetor[dir] > vetor[menor])
        menor = dir;

    if (menor != i) {
        int aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;

        minHeap(vetor, tamanho, menor);
    }
}

void ordena(int vetor[], int tamanho) {

    for (int i = tamanho / 2 - 1; i >= 0; i--)
        minHeap(vetor, tamanho, i);

    for (int i=tamanho-1; i>=0; i--) {
        int temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;

        minHeap(vetor, i, 0);
    }
}

void imprime(int vetor[], int tamanho) {
    for(int i = 0; i < tamanho; i++)
        printf("%d, ", vetor[i]);
}


void main() {
    int vetor[] = {12, 11, 13, 5, 6, 99, 4, 556, 125};
    int tamanho = sizeof(vetor) / sizeof(int);

    ordena(vetor, tamanho);
    printf("Tamanho do vetor: %d\n\n.:Vetor organizado:.\n", tamanho);
    imprime(vetor, tamanho);
}
