#include <stdio.h>
#include <stdlib.h>
#include "pilha2.h"



int x(){

char frase[256];
pilha *p = cria();
int i =0;

for(i=0;1; i++){
    scanf("%[^\n]", &frase[i]);
    if(frase[i]==' ' || frase[i] == '\0'){
    while(!pilhaVazia(p)){ printf("%c", desempilha(p));} printf(" ");}
    else
    empilha(p,frase[i]);
    if(frase[i] == '\0') break;

}
return 0;

}





















int main(){

int i = 0; 
int num;
int res;
int numero_invertido=0;
int pos=1;

pilha *p = cria();

scanf("%d", &num);
res = num;


while (res != 0){

    empilha(p,res%10);
    res /= 10;
    i++;
}

for(;i>0; i--){

numero_invertido += pos*desempilha(p);
pos*=10;

}

if(numero_invertido == num) printf ("SIM");
return 0;

}