#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>




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


  
  x= strlen(A);
  y= strlen(B);
  if(x<y) z = x;
  else z = y;
  for (i = 0; i< z;i++){
    
    if(A[i]==B[i]) {j++;continue;}
    if(A[i]<B[i]) {return 1;}
    return 0;
  }
  if(j==z){
    
    if(x>y) return 0;
  }
  return 1;
  
}


void  intercala (int p, int q, int r, char* v[], long int *cont)  {
  int n1, n2;
  char ** A, ** B;                     
  int i, j, k;

   
  n1 = q - p + 1;
  n2 = r - q;
  
  A = malloc (n1 * sizeof (char*));      
  B = malloc (n2 * sizeof (char*));      

  for (i = 0; i < n1; i++){
    A[i] = v[p+i];
  }

  for (i = 0; i < n2; i++){
    B[i] = v[q+1 + i];
  }

  
  i = 0, j = 0;
  k = p;
  while (i < n1 && j < n2) {
      cont[0]++;       
    if (comparaString(A[i],B[j]))
      v[k] = A[i++];  
    else
      v[k] = B[j++];
    k++;
  }

  while (i < n1)
    v[k++] = A[i++];         
  while (j < n2)
    v[k++] = B[j++];


  free(A);
  free(B);
}




/* A função mergesort rearranja o vetor 
   v[p..r] em ordem crescente. */

void mergeSort (int p, int r, char* v[],long int *cont) {
  int q;
  
  if (p < r) {                 
    q = (p + r)/2;         
    mergeSort(p, q, v,cont);       
    mergeSort(q+1, r, v,cont);       
    intercala(p, q, r, v,cont);    
  }
  
}




int main(int argc, char** argv) {
  int i, n,j;
  char ** v;
  double start, stop, elapsed;
  long int *cont = malloc(sizeof(long int));
  cont[0] = 0;

  n = atoi(argv[1]); 
  
  v = malloc (n * sizeof(char*));
  
  for (j = 0; j < n; j++){
    v[j] = malloc(sizeof(char)*11);
    i=j;
    i=scanf("%s",v[j]);
  }
    start = (double) clock () / CLOCKS_PER_SEC;

    
  mergeSort(0, n-1, v,cont);
  
    stop = (double) clock () / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("tempo: %f\n",elapsed);
    printf("Comparações: %ld\n",cont[0]);
  for (i = 0; i < n; i++){
    free(v[i]);
  }
  free(v);
  return 0;
}
