#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

long int cont = 0;

void CorrigeDescendo(char**vet, int raiz, int fundo);

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
    if(x>=y) return 0;
  }
  return 1;
  
}

void heapsort(char** vet, int n) {
	int i;
  

	for (i = (n / 2); i >= 0; i--) {
		CorrigeDescendo(vet, i, n - 1);
	}

	for (i = n-1; i >= 1; i--) {
		troca(vet,0,i);
		CorrigeDescendo(vet, 0, i-1);
	}
}

void CorrigeDescendo(char **vet, int raiz, int fundo) {
	int pronto, filhoMax;

	pronto = 0;
	while ((raiz*2 <= fundo) && (!pronto)) {
		if (raiz*2 == fundo) {
			filhoMax = raiz * 2;
		}
		else if (comparaString(vet[raiz * 2 + 1],vet[raiz * 2])) {
			filhoMax = raiz * 2;
		}
		else {
			filhoMax = raiz * 2 + 1;
		}

	if (comparaString(vet[raiz],vet[filhoMax])) {
		troca(vet,raiz,filhoMax); 
		raiz = filhoMax;
    }
	else {
      pronto = 1;
	}
  }
}

int main(int argc, char** argv){
    int n, i,j;
    char **vetor;
    double start, stop, elapsed;
    n = atoi(argv[1]); 
    vetor = malloc(sizeof(char*)*(n));
    j=n;
    for(i=0; i<j;i++){
      vetor[i] = malloc(sizeof(char)*11);
      n = scanf("%s",vetor[i]);
    }
    
    start = (double) clock () / CLOCKS_PER_SEC;
    
	heapsort(vetor,n);

  stop = (double) clock () / CLOCKS_PER_SEC;
  elapsed = stop - start;
  printf("Tempo: %f\n",elapsed);
  printf("Comparações: %ld\n",cont);
  for (i = 0; i < j; i++){
    free(vetor[i]);
  }
  free(vetor);
	return(0);
}