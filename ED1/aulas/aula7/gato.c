/* 

Faça uma função 

void labirinto (int **lab, int m, int n, pos gato, pos petisco); 

que receba um labirinto m x n (0 para vazio e -1 para parede), a
posição do gato e a posição do petisco. 

Você deve numerar as posições do labirinto a partir da posição do gato
com a distância do gato até aquela posição. Com isso, mostra o menor
caminho do gato até o petisco naquele labirinto.

entrada.in:

m n
x x x 
x x x 
x x x 
gl gc
pl pc

5 5
0   0  0  0 -1
0  -1 -1  0  0
-1  0  0  0 -1
0   0 -1 -1  0
0   0  0  0  0
0 0 
4 4

*/
#include <stdio.h> 
#include <stdlib.h>
#include "fila.h"

int diferente (pos x, pos y) {
  return (x.l != y.l || x.c != y.c); 
} 

void imprimeMatriz (int ** v, int m, int n){
  int i, j; 
  for (i = 0; i < m; i++){
    for (j = 0; j < n; j++)
      printf("%3d ", v[i][j]); 
    printf("\n");
  } 
}



void labirinto (int **lab, int m, int n, pos gato, pos petisco) {
  fila * caminho = criaFila ();
  int plinha[4] = {1, 0, -1, 0};
  int pcoluna[4] = {0, 1, 0, -1}; /* junta o vetor [0] para a primeira posição, [1] para a segunda...*/
  int d; 
  pos atual, prox; 

  insereFila (caminho, gato);
  lab[gato.l][gato.c] = 1;
  atual = removeFila(caminho);
  
	  
  while (diferente (atual, petisco)){    
    
    for (d = 0; d < 4; d++){
      prox.l = atual.l + plinha[d];
      prox.c = atual.c + pcoluna[d];
    
      if (prox.l >= 0 && prox.l < m &&
	  prox.c >= 0 && prox.c < n &&
	  lab[prox.l][prox.c] == 0){
	lab[prox.l][prox.c] = lab[atual.l][atual.c] + 1;
	insereFila (caminho, prox);
      }
    }    
    if (filaVazia (caminho)){
      printf("Não tem caminho do rato até o queijo\n");
      destroiFila (caminho); 
      return;
    }
    atual = removeFila(caminho);
  }
  imprimeMatriz (lab, m, n);
  destroiFila (caminho);
} 
    
int ** alocaMatriz (int m, int n) {
  int **a = malloc (m * sizeof (int *));
  int i;
  for (i = 0; i < m; i++){
    a[i] = malloc (n * sizeof (int));
  } 
  return a;
} 

void liberaMatriz (int ** a, int m) {
  int i; 
  for (i = 0; i < m; i++)
    free (a[i]);
  free (a); 
} 

int main()
{
  int **lab, m, n, i, j;
  pos gato, petisco;

  scanf ("%d %d ", &m, &n); 
  lab = alocaMatriz (m, n); 

  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      scanf("%d ", &lab[i][j]); 

  scanf("%d %d ", &gato.l, &gato.c);
  scanf("%d %d ", &petisco.l, &petisco.c); 
  labirinto (lab, m, n, gato, petisco); 
  liberaMatriz (lab, m);

  
  return 0;
} 
