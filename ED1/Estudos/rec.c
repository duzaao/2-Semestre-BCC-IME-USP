#include <stdio.h>

int rec (int n, int i){


    n = n / 10;
    if (n == 0) 
        return ++i;
    rec(n,++i);
}

double f(double x, double y) {
if (x >= y)
return ((x+y)/2);
return (f(f(x+2, y-1), f(x+1, y-2)));
}

int A(int m, int n){
    if (m != 0 && n == 0) return (A(m-1,1));
    if(m == 0 ) return (n+1);
    else return A(m-1,A(m,n-1));
}


int fusc (int n) {
if (n <= 1) return (1);
if (n % 2 == 0)
return (fusc(n / 2));
return (fusc((n-1)/2) + fusc((n+1)/2));
}

int misterio (int A[], int inic, int fim) {
int aux;
while (A[fim] % 2 == 0 && inic < fim)
fim --;
while (A[inic] % 2 == 1 && inic < fim)
inic++;
if (inic < fim){
aux = A[inic];
A[inic] = A[fim];
A[fim] = aux;
misterio(A, inic, fim);
}
}


int zzz(int n) {
int aux;
if (n <= 2)
return(1);
n--;
aux = zzz(n);
n--;
return (aux + zzz(n));
}


int euclides (int m, int n){

    int r = m%n;
    if(r == 0) return n;
    euclides(n,r);
}

int main(){

 
 printf("%d", euclides(14,54));
    return 0;
}