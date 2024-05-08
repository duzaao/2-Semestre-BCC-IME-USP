
#include <stdio.h>
#include <stdlib.h> 
#include "pilha.h"

/* Aloca a matriz dinamicamente*/ 
int ** alocaMatriz (int lin, int col) { /* utliza como entrada o número de linhas e de colunas */ 
  int ** mat = malloc (lin * sizeof(int *)); /*aloca as linhas primeiro como um vetor de ponteiros */
  int i;
  for (i = 0; i < lin; i++)
    mat[i] = malloc (col * sizeof(int)); /* para cada linha é alocado um vetor de colunas */
  return (mat); /* retorna a matriz alocada */
}



/* da um free no vetor de linhas e depois nos vetores de colunas (no for) */
void liberaMatriz (int ** mat, int lin){ /* chama a matriz e o número de linhas, que ja é o suficiente para percorrer o for e dar um free completo*/
  int i;
  for (i = 0; i < lin; i++) free(mat[i]); /*da um free em cada vetor de colunas */
  free (mat); /* da um free no vetor de vetores */
}



/* essa função imprime uma matriz */
void imprimeMatriz (int **mat, int lin, int col) { /* como argumentos estão o vetor de vetores, o tamanho de linhas e colunas */
  int i, j;
  for (i = 0; i < lin; i++){ 
    for (j = 0; j < col; j++)
      if (mat[i][j] == 1) 
	printf("R"); 
      else
	printf(" ");
    printf("\n"); /* importante para a quebra de linhas de uma matriz*/
  }
  printf("\n");
}



/* verifica se a posição[lin][col] está livre na matriz */
int posicaoLivre (int **mat, int n, int lin, int col){
  int livre = 1, i, j; /* chama livre de 1 e tenta verificar se não está livre, caso contrário, livre será 0 */
  for (i = 0; i < n; i++) /* esse for percorre a coluna [col] e a linha [lin] para verificar se está livre*/
    if (mat[lin][i] == 1 || mat[i][col] == 1) 
      livre = 0;
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




void nRainhas (int n, int flag) {
  pilha * pos = cria(); 
  int ** tab = alocaMatriz (n, n); /* cria a matriz do tabuleiro nxn */
  int valido, rainha, col, i, j, ok; 

/* coloca o tabuleiro como zero */
  for (i = 0; i < n; i++){
    for (j = 0; j < n; j++){
      tab[i][j] = 0;
    }
  }
  
  rainha = 0; /* utilizado para contar quantas rainhas */
  col = 0; 
  valido = 0;
  ok = 1;
  
  while (ok) {
    valido = 0;
    
    while (col < n && rainha < n){ /* enquanto não tiver percorrido todas as colunas e o número de rainhas for menor que n persista */
      if (posicaoLivre (tab, n, rainha, col)) {
        empilha (pos, col); /* empinha a posição e a coluna */
        tab[rainha][col] = 1; /*coloca 1 o lugar da rainha */
        rainha++; /* faz o rainha +1 */
        col++; 
        valido = 1;
            }
      else
	col++;      
    }

    /* se configuracao nao eh valida */
    if (!valido){
      /* se ja testou todas as configuracoes possiveis */
      if (pilhaVazia (pos)) 
	break;
      else {
	rainha--;
	col = desempilha(pos);
	tab[rainha][col] = 0;
	col++;
      }
    }

    /* se tem solucao */
    if (rainha == n) {
      printf("Tem solucao\n");
      if (flag)
	imprimeMatriz (tab, n, n);
      break;
    }
  }
  destroi (pos);
  liberaMatriz (tab, n);
} 

int main() {
  int n, flag;
  printf ("Digite n e flag de impressao: ");
  scanf ("%d %d", &n, &flag);
  nRainhas (n, flag);
  return (0);
} 
  
