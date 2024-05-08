#include <stdio.h> 
#include <string.h>
#include "aqui.h"
#define max 1000

int operador (char c){

    return (c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/');
}


int prec (char c){

    if (c == '(') return 0;
    if (c == '+'|| c == '-') return 1;
    return 2;
}

void posfixa ( char exp[]){

    pilha *pilhaOp = cria();
    char ctopo;
    int i;
    for (i=0;exp[i]!= '\0'; i++){
        if (exp[i] == ' ') continue;
        if(!operador(exp[i])) printf("%c", exp[i]);
        else if (exp[i] == '(') empilha (pilhaOp, exp[i]);
        else if (exp[i] == ')'){

            ctopo = desmpilha (pilhaOp);
            while (ctopo != '('){
                printf("%c", ctopo);
                ctopo = desempilha(pilhaOp);
            }
        }

        else {
            while (!pilhaVazia && prec(topoPilha(pilhaOp)) >= prec(exp[i])){

                ctopo = desempilha(pilhaOp);
                printf("%c", ctopo);
            }

        empilha (pilhaOp, exp[i]);
        }
    }

    while (!pilhaVazia(pilhaOp)){

        ctopo = desempilha(pilhaOp);
        printf("%c",ctopo);
}

    printf("\n");
    destroi(pilhaOp);

}


int main(){




}
