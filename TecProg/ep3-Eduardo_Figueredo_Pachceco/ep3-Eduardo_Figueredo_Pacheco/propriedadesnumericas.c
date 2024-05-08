#include<stdio.h>
#include<stdlib.h>
#include "propriedadesnumericas.h"

/* verifica-se o módulo 2 do número inserido, caso o resultado seja 0 se que esse número é par, caso seja 1, ele é ímpar */

int eh_par(long long num) {if(num%2) return 0; return 1;}

    /* verifica se algum número menor que a raiz quadrada do nº inserido divide ele, caso contrário, sabe-se que esse número é primo */
int eh_primo(long long num){
    long int i;
    if(i==0) return 0;
    for (i=2;i*i<=num;i++) if (num%i==0) return 0; 

    return 1; 
}

    /* Verifica-se todos os inteiros tais que x² = número inserido; ela retorna 1 se o número é um quadrado perfeito e 0 caso contrário */
int ehQuadradoPerfeito (long long num){
    long long i = 1;
    for(i=1;i*i<=num;i++){
        if(i*i == num) return 1;
    }
    return 0;
}

    /* Verifica-se todos os inteiros tais que x³ = número inserido; ela retorna 1 se o número é um cubo perfeito e 0 caso contrário */
int ehCuboPerfeito (long long num){
    long long i = 1;
    if(num<0) num*=-1;
    for(i=1;i*i*i<=num;i++){
        if(i*i*i == num) return 1;
    }
    return 0;
}

    /* Verifica se o número pertence a sequência de fibonacci fazendo com que o loop pare somente se for maior ou igual ao número inserido 
        pois no caso de ser igual, retorna-se 1 e se for maior, sabe-se que não pertece, logo retorna-se 0 */
int ehFibonacci(long long num){
    long long i=0,j=1,aux;
    while(j<=num){
        if(j == num) return 1;
        aux = j;
        j=i+j;
        i = aux;
    }
    return 0;
}

    /* Verifica se o número pode ser escrito com um número fatorial, fazendo com que o loop pare somente se for maior ou igual ao número inserido 
        pois no caso de ser igual, retorna-se 1. E se for maior, sabe-se que não pode ser escrito como x!, logo retorna-se 0 */
int ehFatorial(long long num){
    long long j=1, i = 1;
    while(j<=num){
        if(j == num) return 1;
        j = j*i;
        i++;
    }
    return 0;
}

