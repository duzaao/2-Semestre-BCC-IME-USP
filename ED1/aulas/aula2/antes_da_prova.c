#include<stdio.h>

int procuracor(int n, int **M, int *cores, int p, int c){

    int i, j;

    
    for(i=0;i<n;i++)
        if(M[p][i])
            if(cores[i] == c) return 0;
    
    

return 1;



}

int quatroCores(int n, int **M, int *cores, int cor){

    if(cor==n) return 1;
    int c, i;
    for(i=0;i<n;i++){
        for(c=1;c<5;c++){

            if(procuracor(n,M,*cores,i,c)){
                cores[cor] = c;
                if(quatroCores(n,M,cores,cor+1)) return 1;
                cores[cor] = 0;
            }

        }
    }


    return 0;
}


void intercala(int p, int q, int r, int v[]){

int *A, *B, n1, n2, i,k =0, j;

n1 = q - p +1;
n2 = r-q;

for(i = 0; i< n1; i++){
A[i] = v[p+i];
}
for(i = 0; i< n1; i++){
B[i] = v[q+1+i];
}


i = 0; 
j = 0;
k = p;
while (i< n1 && j<n2){
    if(A[i] < B[i]){
        v[k++] = A[i++];
    }
    else v[k++] = B[j++];
}

while (i< n1){
v[k++] = A[i++];
}
while (j<n2){
v[k++] = B[j++];
}

free(A);
free(B);

}

void mergesort(int p, int r, int v[]){
    int q;
    if(p<r){
        q = (p+r)/2;
        mergesort(p,q,v);
        mergesort(q+1,r,v);
        intercala(p,q,r,v);
    }
}


void troca( int V[], int i, int j){
    int aux = V[i];
    V[i] = V[j];
    V[j] = aux;
}


int particiona(int ini, int fim, int V[]){
        int p = V[fim];
        int i, j;


        for(j=ini;i<fim;j++){
            if(V[j] <= p){
                troca(V,i,p);
                i++;
            }
        }

        troca(V,i,fim);
        return i;
}


int particiona2(int ini, int fim, int V[]){

    int i, j, x = V[ini];
    i = ini;
    j = fim +1;

while(1){
        while(V[++i] < x)
            if(i == fim) break;

        

        while(V[--j] < x)
            if(ini == j) break;

        if(i>=j) break;

        troca(V,i,j);


}
troca(V,j,ini);
return j;
}



void quickSort(int ini, int fim, int V[]){
int x;
    if(ini<fim){
       x =  particiona(ini,fim,V);
       quickSort(ini,x-1,V);
       quicksort(x+1, fim,V);
    }
}