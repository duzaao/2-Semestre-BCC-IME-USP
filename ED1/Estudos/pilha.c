#include "aqui.h"
#include <stdlib.h> 

/* (*p).topo é o mesmo que p->topo */

/* cria uma pilha */
pilha * cria(){
  pilha * p = malloc(sizeof (pilha)); /*vetor alocado da pilha *p */
  p->max = 1; /* tamanho máximo da pilha 1*/
  p->topo = 0; /* aponta para uma posição nula */
  p->v = malloc(p->max * sizeof(item)); /*aloca o vetor dentro da pilha com tamanho max */

  /* se nao conseguiu alocar memoria */
  if (p->v == NULL)
    return NULL;
  return p;
}

int pilhaVazia(pilha * p){
  return (p->topo == 0); /* retorna se a pilha estiver vazia */
}


/* pega o elemento do topo da pilha */
item topoPilha(pilha * p){ 
  if (!pilhaVazia (p))  /* se a pilha não tiver vazia ele pega o elemento do topo */
    return p->v[p->topo-1]; /* retorna o vetor V [ultima posição] */
  return ERRO; /* retorna erro caso a pilha esteja vazia */
}


/* vai tirar um elemento da pilha e diminuir o amanho de topo */
item desempilha(pilha * p){
  item aux; /* item == char */
  if (!pilhaVazia(p)){ 
    p->topo=p->topo - 1;  /* topo-- */
    aux = p->v[p->topo]; /* salva a posição que vai ser excluida*/
    p->v[p->topo] = ERRO; /*coloca ERRO no lugar porque o topo sempre aponta para o ERRO*/
    return aux; /* retorna a posição excluida */
  }
  return ERRO; /* se a pilha ja tiver vazia ele retorna o erro */
}



/* da um free na pilha inteira */
void destroi(pilha * p){
  free(p->v);
  free(p);
} 


/* coloca um elemento X na pilha */
void empilha (pilha * p, item x){
  if (p->topo == p->max) /* se a pilha estiver cheia, faça um resize e multiplique seu tamanho por 2 */
    resize(p);
  p->v[p->topo] = x; /* mude a posição do topo de ERRO para o X*/
  p->topo++; /*faça TOPO++
  /* não sei se seria necessário, mas eu faria um p>v[p->topo] = ERRO */  
}


/* dobra o tamanho da pilha caso ela esteja full */
void resize(pilha * p){
  int i;
  item * w = malloc(2 * p->max * sizeof(item)); /* cria o item w com o tamanho dobrado*/
  /* transfere os dados */
  for (i = 0; i < p->max; i++) 
    w[i] = p->v[i];
  p->max = p->max * 2; /* multiplica o tamanho maximo por dois para o próximo resize */
  free (p->v); /* da um free e ja coloca p->v = w ; para concretizar o resize*/
  p->v = w;
}

