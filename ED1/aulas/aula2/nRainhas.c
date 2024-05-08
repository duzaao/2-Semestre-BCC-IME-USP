
#include <stdio.h>
#include <stdlib.h> 
#include "pilha.h"


int ** alocaMatriz (int lin, int col) {
  int ** mat = malloc (lin * sizeof(int *));
  int i;
  for (i = 0; i < lin; i++)
    mat[i] = malloc (col * sizeof(int));
  return (mat);
}


void liberaMatriz (int ** mat, int lin){
  int i;
  for (i = 0; i < lin; i++) free(mat[i]);
  free (mat);
}


void imprimeMatriz (int **mat, int lin, int col) {
  int i, j;
  for (i = 0; i < lin; i++){
    for (j = 0; j < col; j++)
      if (mat[i][j] == 1)
	printf("R");
      else
	printf("*");
    printf("\n");
  }
  printf("\n");
}


int posicaoLivre (int **mat, int n, int lin, int col){
  int livre = 1, i, j;

  /* verifica as diagonais */
  for (i = 0; i < lin; i++){
    j = (col - lin) + i;
    if (j >= 0 && mat[i][j] == 1)
      livre = 0;
    j = (col + lin) - i;
    if (j < n && mat[i][j] == 1)
      livre = 0;
  }
  return livre;
} 


void nRainhas (int n, int flag, int k) {
  pilha * pos = cria();
  int ** tab = alocaMatriz (n, n);
  int total, valido,bispos, linha, col, i, j, ok;
  total = 0;
  
  for (i = 0; i < n; i++){
    for (j = 0; j < n; j++){
      tab[i][j] = 0;
    }
  }
  
  bispos = 0;
  col = 0;
  linha = 0;
  valido = 0;
  ok = 1;
  
  while (ok) {
    valido = 0;
    
    while (col < n && linha < n && bispos < k){
      if (posicaoLivre (tab, n, linha, col)) {
	empilha (pos, col);
  empilha ( pos , linha ) ;
	tab[linha][col] = 1;
  bispos++;
	col++;
	valido = 1;
      }
      else
        valido = 0;
	col++;
    if(col == n){
      linha++;
      col = 0;
    }      
    }


    if (bispos == k) {
      if (flag)
	imprimeMatriz (tab, n, n);
    }

    /* se configuracao nao eh valida */
    if (!valido || bispos==k){
      /* se ja testou todas as configuracoes possiveis */
      if (pilhaVazia (pos)) 
	break;
      else {
	bispos--;
	linha = desempilha(pos);
	col = desempilha(pos);
  
	tab[linha][col] = 0;
	col++;
  if(col == n){
    linha++;
    col = 0;
  }
      }
    }

   

  }
  destroi (pos);
  liberaMatriz (tab, n);
  printf("total = %d\n",total);
  
} 

int main() {
  int n, flag,k;
  printf ("Digite n e flag de impressao: ");
  scanf ("%d %d %d", &n, &flag, &k);
  nRainhas (n, flag,k);
  return (0);
} 
  
