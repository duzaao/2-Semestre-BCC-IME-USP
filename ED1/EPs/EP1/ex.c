# include <stdio.h>
#include <stdlib.h>
#include <time.h> 





int main(){

    long int res, res1 ;
    int i;
    long int cont;
    float tempo = 0.0;



    scanf("%ld %ld", &res, &res1);


    cont = res;

    clock_t begin = clock();

    while (res <= res1){

        for (i = 0; (res != 1); i++){
        
            if (res % 2 == 0) res /= 2;
            else res = 3*res +1;

        }
        cont++;
        res = cont;
    }

    clock_t end = clock();
    tempo += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("o programa rodou  em %f segundos\n",tempo);

    
    
    return 0;

}