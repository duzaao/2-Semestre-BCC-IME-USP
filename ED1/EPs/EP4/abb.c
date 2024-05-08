/* Árvores de Busca Binária */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.h"


/* Verifica se A<=B e retorna 1 se é menor ou 0 se não é menor e -1 se é igual */
int comparaString(char *A , char *B){
  int i, j=0;
  int x, y,z;
  x= strlen(A);
  y= strlen(B);
  if(x<y) z = x;
  else z = y;
  for (i = 0; i< z;i++){
    if(A[i]==B[i]) {j++;continue;}
    if(A[i]<B[i]) return 1;
    return 0;
  }
  if(x==y) return -1;
  if(j==z){
    if(x>y) return 0;
  }
  return 1;
  
}


/* Busca um elemento na árvore de busca binária

no * busca (no * raiz, int x); 

*/

no * busca (no * raiz, char* x){
  if (raiz == NULL || comparaString(x, raiz->chave)==-1)
    return raiz;
  if (comparaString(x, raiz->chave)==1)
    return busca (raiz->esq, x);
  return busca (raiz->dir, x);
}


int procura(no* raiz, char*x){
  if(raiz==NULL) return 0;
    if (comparaString(x, raiz->chave)==-1)
    return 1;
  if (comparaString(x, raiz->chave)==1)
    return procura (raiz->esq, x);
  return procura (raiz->dir, x);
}      

no * maximo (no * raiz){
  if (raiz == NULL || raiz->dir == NULL)
    return raiz;
  return maximo(raiz->dir);
} 

no * minimo (no * raiz){
  if (raiz == NULL || raiz->esq == NULL)
    return raiz;
  return minimo(raiz->esq);
} 

/* Insere um elemento em uma ABB, devolve a raiz da árvore 
   com o elemento inserido

no * insere (no * raiz, int x); 

*/ 

no * insereABB (no * raiz, char* x, int linha){
  int i;
  if (raiz == NULL){
    raiz = malloc (sizeof(no));
    raiz->pos_linhas = malloc(sizeof(int)*100000);
    raiz->qtd_vez_na_linha = malloc(sizeof(int)*100000);
    for(i=0;i<100000;i++) raiz->qtd_vez_na_linha[i] = 0;

    raiz->chave = x;
    raiz->qtd_vzs = 1;
    raiz->qtd_linhas = 1;
    raiz->qtd_vez_na_linha[linha] = 1;
    raiz->pos_linhas[0] = linha;
    raiz->linhaAnterior = linha;
    raiz->dir = raiz->esq = NULL;
    return raiz;
  }
  if(comparaString(x, raiz->chave)==1){
    raiz->esq = insereABB (raiz->esq, x, linha);
  }
  if(comparaString(x, raiz->chave)==0){
    raiz->dir = insereABB (raiz->dir, x, linha);
  }
    if(comparaString(x, raiz->chave)==-1){
    raiz->dir = insereABB (raiz->dir, x, linha);
  }
  return raiz;
}



no * removeABB (no * raiz, char* x){
  no * y; 
  if (raiz == NULL)
    return NULL;
  if (x < raiz->chave)
    raiz->esq = removeABB(raiz->esq, x);
  else if (x > raiz->chave)
    raiz->dir = removeABB(raiz->dir, x);
  else{
    if (raiz->esq == NULL){
      y = raiz->dir;
      free(raiz);
      raiz = y;     
    }
    else if (raiz->dir == NULL){
      y = raiz->esq;
      free(raiz);
      raiz = y;
    }
    else{
      y = minimo(raiz->dir);
      raiz->chave = y->chave;
      raiz->dir = removeABB(raiz->dir, y->chave);
      /* nao precisa de free, a recursao cuida */
    }
  }
  return raiz;
}

