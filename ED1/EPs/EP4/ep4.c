
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.h"

void troca (char* v[], int i, int j){
  char* aux;
   aux = v[j];
   v[j] = v[i];
   v[i] = aux;
}


/*As principais funções utilizadas são:

procura(p,word);          que foi uma função que eu criei, parecida com a de busca, mas que retorna 1 se a palavra está presente na arvore e 0 cc
busca(p,word);            utilizado para pegar um nó da ABB
insereABB(p,word,linha);  que insere uma string na ABB, fazendo comparações de string por meio da função ComparaString(A,B);
inordem (p);              que é responsável pelos prints da arvore em ordem alfabetica, além do próprio indice remissivo.


*/
int main() {

    char* filename;
    FILE *arq;
    int k=0, i,j=0;
    int linha = 1;

    char * word = malloc(sizeof(char)*30);
    char* line = malloc(sizeof(char)*10000);
    /*indiceRem->max = 10000;*/

    no * p = NULL;
    no * x;
    filename = "input.txt";
    arq = fopen(filename,"r");


/*enquanto houver linhas no input.txt*/
while (fgets(line, 10000, arq))
{ 
        for(i=0;i<10000;i++){
            if((line[i]>='A' && line[i]<='Z')||(line[i]>='a'&&line[i]<='z')){
                 word[k++] = line[i];
            }
            else {
                word[k]='\0';
                if(procura(p,word)){ /*se a palavra ja foi adicionada na ABB */
                    x = busca(p,word);

                    for(j=0;j<x->qtd_linhas;j++)
                        if(x->pos_linhas[j] == linha ){ /* verifica se ela ja foi adicionada nessa mesma linha */
                            x->qtd_vez_na_linha[linha]++;
                            break;
                        } 
                        else if(x->linhaAnterior != linha){
                            x->pos_linhas[x->qtd_linhas++]=linha;
                            x->linhaAnterior = linha;
                        }
                    x->qtd_vzs++;
                 }
                else p = insereABB(p,word,linha);
                k=0;
                word = malloc(sizeof(char)*30);
            }
            if(line[i]=='\n'||line[i]=='\0') break;
        }
        k=0; linha++;

}

inordem (p); /*printa tudo o que for necessário */


free(line);



return 0;
    }