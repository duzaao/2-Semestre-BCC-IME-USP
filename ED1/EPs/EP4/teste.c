#include <stdio.h>
#include <string.h>
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

char* strcopy(char* cpy){
    char* palavra = malloc(sizeof(char)*30);
    int i;
    for(i = 0; cpy[i]!= '\0';i++){
        palavra[i] = cpy[i]; 
    }
    palavra[i] = '\0';
}

int main(){

    char * A = "Abobora";
    char * B = "Abobora";
    printf("%s",strcopy(A));
}