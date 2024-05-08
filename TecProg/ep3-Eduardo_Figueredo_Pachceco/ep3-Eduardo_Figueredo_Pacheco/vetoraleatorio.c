#include <stdlib.h>
#include <stdio.h>
#include "vetoraleatorio.h"

/* cria um vetor aleatório utilizando a função rand e fazendo com que os números sejam de tamanho maior 
 * fazendo a multiplicação de dois números aleatórios 
 */
long long *criaVetorAleatorio(int semente, int tamanho){

    long long int *vetor;
    int i,j;
    vetor = malloc(sizeof(long long int)*tamanho);
    srand(semente);
    for(i=0;i<tamanho;i++) vetor[i] = (long long)rand() * (long long)rand();
    return vetor;
}
