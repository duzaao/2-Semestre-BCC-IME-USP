#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/* Verifica se A<=B e retorna 1 se é menor ou 0 se não é menor */
int comparaString(char *A , char *B){
  int i, j;
  int x, y,z;
  x= strlen(A);
  y= strlen(B);
  if(x<y) z = x;
  else z = y;
  for (i = 0; i< z;i++){
    printf("%c e %c", A[i],B[i]);
    if(A[i]==B[i]) {printf("=\n");j++;continue;}
    if(A[i]<B[i]) {printf("<\n");return 1;}
    printf(">\n");return 0;
  }
  if(j==z){
    if(x>y) {    printf("AAAAAAAAAAAA");
return 0;} 
  }
  return 1;
  
}

int main(){
    char * A = malloc(sizeof(char)*10);
    char *B= malloc(sizeof(char)*10);;

    scanf("%s %s",A,B);
    printf("%d",comparaString(A,B));
return 0;
}