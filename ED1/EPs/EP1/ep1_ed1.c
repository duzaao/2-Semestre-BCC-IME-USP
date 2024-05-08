# include <stdio.h>
#include <stdlib.h>
#include <time.h> 





int main(){

long int res, res1 ;
float tempo = 0.0;
int i,j=0;
long int inicio;
int * vetor;
long int cont;


clock_t begin = clock();

scanf("%ld %ld", &res, &res1);

inicio = res;
cont = res;

vetor  = malloc(sizeof(int)*(res1-res+1));
while (res <= res1){

 for (i = 0; (res != 1); i++){
    
        if ((res https://www.linkedin.com/in/eduardofpacheco>= inicio)&&(res<=(inicio+j-1))&&(j!=0)){
            i = i + vetor[(res-inicio)];
            break;
        }

        if (res % 2 == 0) res /= 2;
        else res = 3*res +1;

    }
    
    vetor[j++] = i;
     cont++;
    res = cont;
}


clock_t end = clock();
 tempo += (double)(end - begin) / CLOCKS_PER_SEC;


for(i = 0; i<(res1- inicio+1);i++) printf("%d\n", vetor[i]);
printf("o programa rodou  em %f segundos\n",tempo);


 
    
    return 0;

}