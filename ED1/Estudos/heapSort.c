#include<stdlib.h>
#include<stdio.h>


void troca (int v[], int i, int j){
  int aux;
   aux = v[j];
   v[j] = v[i];
   v[i] = aux;
}



void  constroiHeap (int m, int v[])
{
   for (int k = 1; k < m; ++k) {                   
      // v[1..k] é um heap
      int f = k+1;
      while (f > 1 && v[f/2] < v[f]) {  // 5
         troca (v,f/2,f);               // 6
         f /= 2;                        // 7
      }
   }
}


void peneira (int m, int v[])
{ 
   int p = 1, f = 2, x = v[1];
   while (f <= m) {
      if (f < m && v[f] < v[f+1]) ++f;
      if (x >= v[f]) break;
      v[p] = v[f];
      p = f, f = 2*p;
   }
   v[p] = x;
}


void heapsort (int n, int v[])
{
   constroiHeap (n, v);
   for (int m = n; m >= 2; --m) {
      troca (v,1,m); 
      peneira (m-1, v);
   }
}

int main(){
    int n, i, j=0;
    int *v;
    scanf("%d",&n);
    v = malloc(sizeof(int)*n);
    for(i=n; i>0;i--){
        v[j] = i;
        j++;
    }
    printf("\nANTES: ");
    for(i=0;i<n;i++) printf("%d ", v[i]);
    printf("\nDEPOIS: ");
    heapsort(n,v);
    
    for(i=1;i<=n;i++) printf("%d ", v[i]);

}