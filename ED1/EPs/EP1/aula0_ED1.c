#include <stdio.h>
#include <stdlib.h>

typedef struct{
    double pr;
    double pi;
} complexo;

typedef struct{
    double x;
    double y;

} ponto;

typedef struct{
    ponto centro;
    double raio;
} circulo;

double perimetro(circulo c);
int dentro_ou_fora(circulo c, ponto p);

complexo soma (complexo x, complexo y){
    complexo s;
    s.pr = x.pr + y.pr;
    s.pi = x.pi + y.pi;
    return s;
}


            // PONTEIROS
            void troca(int *x, int *y){ 
                int aux = *y;
                *y = *x;
                *x = aux;
            }
            // PONTEIROS

int main(){

complexo x,y,z;

            //ponteiros
            int *px;
            px = &x;
            int x = 123;
            printf("%d %d", x, *px);

            double *r;
            double v[5] = {7.5,3.2,4.3,0.0,2.4};
            for (r = &v[0];  *r != 0.0;  r++);
            // ponteiros


    return 0;

}