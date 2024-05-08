#include <stdio.h>
#include <stdlib.h>
#include "aqui.h"

int main(){

    item c;
    int i;

    pilha* p = cria();

    for(i = 0; c != '.'; i++){
        scanf("%c", &c);
        empilha(p, c);
    }
    i--;
    for(;i>=0;i--){

        printf("%c", desempilha(p));
    }
    return 0;
}