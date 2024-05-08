/* 

Escreva uma função 

void posfixa (char exp[]); 

que recebe uma string exp com uma expressão aritmética com 
operadores (A, B, etc), '+', '-', '*', '/', '(' e ')' e imprime
a expressão correspondente na notação posfixa. 

Exemplo: 

A + B * C                       ------> A B C * + 
A * (B + C) / D - E             ------> A B C + * D / + E -
(A + B) * (C - D) + (F - G) / H ------> A B + C D - * F G - H / + 

*/

#include <stdio.h>
#include <string.h> 
#include "pilha.h"
#define MAX 1000 

int operador (char c) {
  return (c == '(' || c == ')' || c == '+' || c == '-'
	   || c == '*' || c == '/');
}

int prec (char c) {
  if (c == '(') return 0;
  if (c == '+' || c == '-') return 1;
  return 2;
}
  
void posfixa (char exp[]) {
  pilha * pilhaOp = cria();
  char ctopo; 
  int i;
  for (i = 0; exp[i] != '\0'; i++){
    /* Se */
    if (exp[i] == ' ') continue; 
    if (!operador(exp[i]))
      printf("%c", exp[i]);
    else if (exp[i] == '(')
      empilha (pilhaOp, exp[i]);
    else if (exp[i] == ')'){
      ctopo = desempilha (pilhaOp);
      while (ctopo != '('){
	printf("%c", ctopo);
	ctopo = desempilha(pilhaOp);
      }
    }
    else { /* é +, -, *, ou / */
      while (!pilhaVazia(pilhaOp) &&
	     prec(topoPilha(pilhaOp)) >= prec(exp[i])){
	ctopo = desempilha(pilhaOp);
	printf("%c", ctopo);
      }
      empilha (pilhaOp, exp[i]);
    }
  }
  while (!pilhaVazia(pilhaOp)){
    ctopo = desempilha(pilhaOp);
    printf("%c", ctopo);
  }
  printf("\n");
  /* nao esquecer de destruir a pilha */
  destroi (pilhaOp); 
}


int main() {
  char seq[MAX];
  printf("Digite a sequência: ");
  scanf("%[^\n]", seq);
  posfixa (seq);
  return 0;
} 
