#include <stdlib.h>
#include <stdio.h>
#include "aqui.h"


int pilhaVazia (pilha *p){

    if (p->topo == 0) return 1;
    return 0; 
}

void empilha(pilha *p, item x){

    if(p->topo == p->max) resize(p); 
    p->v[p->topo++] = x;
}

item topoPilha (pilha *p){

    if (!pilhaVazia(p)){

        return p->v[p->topo - 1];
    }
    return ERRO;
}

pilha cria(){
    pilha *p;
    p->max = 1;
    p->topo = 0;
    p->v = malloc(sizeof(int)*(p->max));

    return *p;
}

item desempilha(pilha *p){
    if (!pilhaVazia(p)){
    p->v[--p->topo] = ERRO;
    p->max--;
    return p->topo; 
    }
    return ERRO;
}




int main(){


}