#include<stdio.h>

void maxHeap(int *vetor, int tamanho, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < tamanho && vetor[esq] < vetor[maior])
        maior = esq;

    if (dir < tamanho && vetor[dir] < vetor[maior])
        maior = dir;

    if (maior != i) {
        int aux = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = aux;

        maxHeap(vetor, tamanho, maior);
    }
}

void ordena(int vetor[], int tamanho) {

    for (int i = tamanho / 2 - 1; i >= 0; i--)
        maxHeap(vetor, tamanho, i);

    for (int i=tamanho-1; i>=0; i--) {
        int temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;

        maxHeap(vetor, i, 0);
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
