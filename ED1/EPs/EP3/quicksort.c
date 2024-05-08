#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

long int cont = 0;
void troca (char* v[], int i, int j){
  char* aux;
   aux = v[j];
   v[j] = v[i];
   v[i] = aux;
}

/* Verifica se A<=B e retorna 1 se é menor ou 0 se não é menor */
int comparaString(char *A , char *B){
  int i, j=0;
  int x, y,z;
  cont++;
  x= strlen(A);
  y= strlen(B);
  if(x<y) z = x;
  else z = y;
  for (i = 0; i< z;i++){
    if(A[i]==B[i]) {j++;continue;}
    if(A[i]<B[i]) return 1;
    return 0;
  }
  if(j==z){
    if(x>y) return 0;
  }
  return 1;
  
}


int particiona (char* v[], int ini, int fim) {
  int i, j;
  char* pivo;

  pivo = v[fim];
  i = ini;
  for (j = ini; j < fim; j++){
    if (comparaString(v[j],pivo)){
      troca(v, i, j);
      i++;
    } 
  }
  troca(v, i, fim);

  return i;
}

void quicksort (char* v[], int ini, int fim) {
  int x;

  if (ini < fim){
    x = particiona(v, ini, fim);
    quicksort(v, ini, x - 1);
    quicksort(v, x + 1, fim);
  }
}



int main(int argc, char** argv) {
  int i, n,j;
  char ** v;
  double start, stop, elapsed;


   n = atoi(argv[1]);
  v = malloc (n * sizeof(char*));
  
  for (j = 0; j < n; j++){
    v[j] = malloc(sizeof(char)*11);
    i=scanf("%s", v[j]);
  }
    start = (double) clock () / CLOCKS_PER_SEC;

  quicksort(v, 0, n - 1);

    stop = (double) clock () / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("Tempo: %f\n",elapsed);
    printf("Comparações: %ld\n",cont);
  for (i = 0; i < n; i++){
    free(v[i]);
  }
  free(v);
  return 0;
}

