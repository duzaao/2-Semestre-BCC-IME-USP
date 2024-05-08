#include<stdio.h>
#include<stdlib.h>

void intercala(int I, int M, int F, int V[]){

    int *A, *B;
    int n1, n2;
    int i, k = 0,j =0;


    n1 = M+1-I;
    n2 = F-M;

    A = malloc(sizeof(int)*n1);
    B = malloc(sizeof(int)*n2);

    for(i=0;i<n1;i++){
        A[i] = V[i];
    }
    for(i = n1 + 1; i<n2; i++){
        B[i] = V[i];
    }


    for(i=0; i<n1 && j<n2; i++){
        if(A[i] <= B[i]) V[k++] = A[i];
        else V[k++] = B[j++];
    }    

    while (i<n1) V[k++] = A[i++];
    while (i<n1) V[k++] = B[j++];

    free(A);
    free(B);

}

void merge(int I, int F, int V[]){
    int m;
    
    if(I<F){
        m = (I+F)/2;
        merge(I,m,V);
        merge(m+1,F,V);
        intercala(I,m,F,V);  
    }
}


  