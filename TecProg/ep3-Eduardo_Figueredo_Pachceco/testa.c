#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<assert.h>
#include"propriedadesnumericas.h"
#include"vetoraleatorio.h"

int main(){
   double start_1,start_2,start_3,start_4,start_5,start_6,start_7, stop, elapsed;
   double tmp_par=0,tmp_primo=0,tmp_cubo=0,tmp_fatorial=0,tmp_fibo=0,tmp_quadrado=0,tmp_cria=0;
   double min_par=10,min_primo=10,min_cubo=10,min_fatorial=10,min_fibo=10,min_quadrado=10,min_cria=10;
   double max_par=0,max_primo=0,max_cubo=0,max_fatorial=0,max_fibo=0,max_quadrado=0,max_cria=0;

    int i,j;
    long long *v = malloc(sizeof(long long)*40);
    
    for (i=0;i<10;i++){

    start_7 = (double) clock () / CLOCKS_PER_SEC;
    v=criaVetorAleatorio(i,10);
    stop = (double) clock () / CLOCKS_PER_SEC;
    elapsed = stop - start_7;
    tmp_cria += elapsed;
    if(min_cria>elapsed) min_cria = elapsed;
    if(max_cria<elapsed) max_cria = elapsed;

    for(j=0;j<40;j++){
    start_1 = (double) clock () / CLOCKS_PER_SEC;

    printf("\n\n ---> %lld\n",v[j]);
    printf("par: %d\n", eh_par(v[j])); 
    stop = (double) clock () / CLOCKS_PER_SEC;
    elapsed = stop - start_1;
    tmp_par += elapsed;
    if(min_par>elapsed) min_par = elapsed;
    if(max_par<elapsed) max_par = elapsed;

    start_2 = (double) clock () / CLOCKS_PER_SEC;
    printf("primo: %d\n",eh_primo(v[j]));
    stop = (double) clock () / CLOCKS_PER_SEC;
    elapsed = stop - start_2;
    tmp_primo += elapsed;
    if(min_primo>elapsed) min_primo = elapsed;
    if(max_primo<elapsed) max_primo = elapsed;

    start_3 = (double) clock () / CLOCKS_PER_SEC;
    printf("cubo: %d\n",ehCuboPerfeito(v[j]));
    stop = (double) clock () / CLOCKS_PER_SEC;
    elapsed = stop - start_3;
    tmp_cubo += elapsed;
    if(min_cubo>elapsed) min_cubo = elapsed;
    if(max_cubo<elapsed) max_cubo = elapsed;

    start_4 = (double) clock () / CLOCKS_PER_SEC;
    printf("fatorial: %d\n",ehFatorial(v[j]));
    stop = (double) clock () / CLOCKS_PER_SEC;
    elapsed = stop - start_4;
    tmp_fatorial += elapsed;
    if(min_fatorial>elapsed) min_fatorial = elapsed;
    if(max_fatorial<elapsed) max_fatorial = elapsed;

    start_5 = (double) clock () / CLOCKS_PER_SEC;
    printf("Fibo: %d\n",ehFibonacci(v[j]));
    stop = (double) clock () / CLOCKS_PER_SEC;
    elapsed = stop - start_5;
    tmp_fibo += elapsed;
    if(min_fibo>elapsed) min_fibo = elapsed;
    if(max_fibo<elapsed) max_fibo = elapsed;

    start_6 = (double) clock () / CLOCKS_PER_SEC;
    printf("quadrado: %d\n",ehQuadradoPerfeito(v[j]));
    stop = (double) clock () / CLOCKS_PER_SEC;
    elapsed = stop - start_6;
    tmp_quadrado += elapsed;
    if(min_quadrado>elapsed) min_quadrado = elapsed;
    if(max_quadrado<elapsed) max_quadrado = elapsed;
 
    }
    }

printf("\n\n\n --------- TEMPO MÉDIO, MÍNIMO E MÁXIMO DAS FUNÇÕES -----------\n\n\n");
printf("tempo cria : %f    M = %f     m = %f\n",tmp_cria/400,max_cria,min_cria);
printf("tempo cubo : %f    M = %f     m = %f\n",tmp_cubo/400,max_cubo,min_cubo);
printf("tempo fibonacci : %f    M = %f     m = %f\n",tmp_fibo/400,max_fibo,min_fibo);
printf("tempo par : %f    M = %f     m = %f\n",tmp_par/400,max_par,min_par);
printf("tempo primo : %f    M = %f     m = %f\n",tmp_primo/400,max_primo,min_primo);
printf("tempo quadrado : %f    M = %f     m = %f\n",tmp_quadrado/400,max_quadrado,min_quadrado);
printf("tempo fatorial: %f    M = %f     m = %f\n",tmp_fatorial/400,max_fatorial,min_fatorial);
return 0;
}