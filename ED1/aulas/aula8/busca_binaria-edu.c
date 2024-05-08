#include <stdio.h>



int buscaBinaria(int v[], int ini, int fim, int x){

int meio = (ini + fim) / 2;
if(ini>fim) return -1;
if(v[meio] == x) return meio;
if (x > v[meio]) return buscaBinaria(v,meio+1,fim,x);
return buscaBinaria(v,ini,meio-1,x);

}

/* chamar a função com a lista, o inicio, o fim, e o valor a ser buscado */
/* colocar meio */
/*verifica se o começo n é maior q o fim */
/* verifica se v[meio] é igual a x */
/* sendo esse o vetor : */
/* [][][][][][][meio][][][][x][][] */
/* se x é maior que v[meio] ----> return buscaBinaria(v,meio+1,fim,x); */
/* se x é menor que v[meio] ----> return buscaBinaria(v,ini,meio-1,x); */