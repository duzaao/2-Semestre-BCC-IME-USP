#include "fila.h"

typedef struct cel {
  char* chave;
  struct cel * esq;
  struct cel * dir; 
  int* pos_linhas; /* quais linhas aparece */
  int* qtd_vez_na_linha;
  int qtd_linhas; /* quantas linhas diferentes ela aparece */
  int qtd_vzs; /* a quantidade de vezes que aparece*/
  int linhaAnterior;
} no;

int contaNo (no *raiz);
int altura (no *raiz);
int ehDescendente (no *x, no *y);

void inordem (no *raiz);
void preordem (no *raiz);
void posordem (no *raiz);
void folhasDescendentes (no *x);
void largura (no *raiz);
