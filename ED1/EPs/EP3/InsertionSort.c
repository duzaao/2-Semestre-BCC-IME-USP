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
    cont++;
  if(x<y) z = x;
  else z = y;
  for (i = 0; i< z;i++){
    if(A[i]==B[i]) {j++;continue;}
    if(A[i]<B[i]) return 1;
    return 0;
  }
  if(j==z){
    if(x>y||x==y) return 0;
  }
  return 1;
  
}



void insertionSort (char* A[], int n) {
  int i, j;
  char* chave;
  /* a cada iteração, teremos o vetor A[1..i] ordenado */
  /* começamos de A[i], porque obviamente o vetor em A[0..0] está 
     trivialmente ordenado */
     
  for (i = 1; i < n; i++) {
    chave = A[i];
    j = i - 1;

    while (j >= 0 && comparaString(chave,A[j])) {
      A[j + 1] = A[j];
      j = j - 1;
    }
    A[j + 1] = chave;
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
    i=scanf("%s",v[j]);
  }
  
    start = (double) clock () / CLOCKS_PER_SEC;

  insertionSort(v, n);
  
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
