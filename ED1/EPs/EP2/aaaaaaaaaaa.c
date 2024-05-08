#include <stdio.h>
#include <string.h>
#include "pilha2.h"
#include <stdlib.h>


typedef struct{

    char *posicoes;
    int linhas;
    int colunas;

} matriz;



void escrever_tab( matriz *tabuleiro, int lin, int coluna, char c){

    tabuleiro->posicoes[tabuleiro->colunas * lin + coluna] = c;
}

char retorna(matriz *tabuleiro, int lin, int col){

    return (tabuleiro->posicoes[tabuleiro->colunas * lin + col]);

}

char **Palavras(int n){

    int i;
    char **matriz_de_palavras = malloc(sizeof(char*)*n);
    for(i=0;i<n;i++){
        matriz_de_palavras[i] = malloc (sizeof(char)*256);
       scanf("%s", matriz_de_palavras[i]);
            
    }

    return matriz_de_palavras;

}

int *TamanhoDasPalavras(char **M,int n){

    int i;
    int *v = malloc(sizeof(int)*n);

    for(i=0; i < n ; i++){
        v[i] = strlen(M[i]);
    }

return v;
}



/* essa função recebe a opção escrita em string pela função lugaresVazios e a compara com palavras do banco de palavras menores ou iguais àquela*/
int match(char *espaco, char *palavra){

    int i = 0;
    for (i = 0; i< strlen(palavra); i++) {
        if (espaco[i] == palavra[i] || espaco[i] == '0')
            continue;
        
        return 0;
    }
    
    return 1;
}


int LugaresVazios_linha(matriz *tabuleiro, int m, int n ,int linha, int coluna, char **M, int numero, int* tamanho, estado s){

    
    int x = coluna;
    int y; /*serve pra salvar o numero de x*/
    char *palavra = malloc(sizeof(char)*256);
    int i=0;
    int cont = 0;
    int ok = 0;
    
    while (x>=0 && tabuleiro->posicoes[tabuleiro->colunas * linha + x] != '*'){ 
        if (tabuleiro->posicoes[tabuleiro->colunas * linha + --x] != '*')continue;
        else  {x++;break;}
    }

    if(x<0) x = 0;
    y = x;
    while(x<(m) && tabuleiro->posicoes[tabuleiro->colunas * linha + x] != '*'){
        palavra[i++] = tabuleiro->posicoes[tabuleiro->colunas * linha + x];
       cont++;
        x++;
    }
   
                /*chute*/
                s.space = palavra;
                s.coord_col = (coluna - y);
                s.coord_lin = linha;
                s.modo = 0;
                s.possiveis = 0;


                /*chute */

    for(s.ultima_palavra = 0; s.ultima_palavra < numero; s.ultima_palavra++){
        if(tamanho[s.ultima_palavra] == cont && match(palavra,M[s.ultima_palavra]) && s.nao_usadas[s.ultima_palavra]){
           
            for(i = 0; i< tamanho[s.ultima_palavra];i++){
                



                s.nao_usadas[s.ultima_palavra] = 0;
                

                if(palavra[i] == '0'){
                 escrever_tab(tabuleiro,linha,y++,M[s.ultima_palavra][i]);
                 ok =1;
                }
                else y++;
                
            }
            break;
        }
    }



if(ok) return 1;
return 0;

}

/* caso o espaço seja maior ou igual a 2 a função retorna uma string com as possibilidades, tipo " a or": podendo dar match com "calor"*/
int LugaresVazios_coluna(matriz *tabuleiro, int m, int n ,int linha, int coluna, char **M, int numero, int* tamanho, estado s){

    int x = linha;
    char *palavra = malloc(sizeof(char)*256);
    int y;
    int i = 0;
    int cont = 0;
    int k;
    int ok = 0;



 
    while (x>=0 && tabuleiro->posicoes[tabuleiro->colunas * x + coluna] != '*'){ 
        if (tabuleiro->posicoes[tabuleiro->colunas * (--x) + coluna] != '*')continue;
        else  {x++;break;}
    }

    if(x<0) x = 0;
    y = x;
    while(x<(m) && tabuleiro->posicoes[tabuleiro->colunas * x + coluna] != '*'){
        palavra[i++] = tabuleiro->posicoes[tabuleiro->colunas * x + coluna];
       cont++;
        x++;
    }
   
    
   for(k = 0; k < numero; k++){
        if(tamanho[k] == cont && match(palavra,M[k]) && s.nao_usadas[k]){
           
               

            for(i = 0; i< tamanho[k];i++){
                
                s.nao_usadas[k] = 0;
                if(palavra[i] == '0'){
                    escrever_tab(tabuleiro,y++,coluna,M[k][i]);
                    ok = 1;
                }
                else y++;
                
            }
            break;
        }
    }


if(ok) return 1;
return 0;


}


void print_tab(matriz *tab){
    int i,j; 
    for( i=0;i< tab->linhas ;i++){
        for(j = 0; j<tab->colunas; j++){
            printf("%c ", retorna(tab, i, j));
        }
        printf("\n");
    }
}


/* fazer função que tira palavra da lista*/

void backtracking(matriz *tabuleiro, int m, int n ,int linha, int coluna, char **M, int numero, int* tamanho, estado s, pilha *p){
    int i;

    s.nao_usadas[p->topo] = 1;
    if(s.modo == 0){
        for(i = 0; i < strlen(M[p->topo]); i++){
            if(s.ultima_palavra){}
        }
    }
    else {
        for(i = 0; i < strlen(M[p->topo]); i++){
        
        }
    }
    desempilha(p);

}

int main(){

    int linhas,colunas,i,j;
    int num_palavras;
    char **matriz_de_palavras;
    int *tamanho;
    int f;
    estado s;
    matriz tabuleiro;


   /* int a,b; dps jogar fora*/
    /*item s;
    pilha *p = cria();*/



    scanf("%d %d", &linhas, &colunas);

    tabuleiro.posicoes = malloc(sizeof(char)*linhas*colunas);
    tabuleiro.linhas = linhas;
    tabuleiro.colunas= colunas;

    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){
            scanf(" %d", &f);
            if(f != 0) escrever_tab(&tabuleiro,i,j,'*');
            else escrever_tab(&tabuleiro,i,j,'0');

        }
    }


    printf("\n escreva nº de palavras:");
    scanf("%d", &num_palavras);

    matriz_de_palavras = Palavras(num_palavras);


    tamanho = TamanhoDasPalavras(matriz_de_palavras,num_palavras);

  
    s.nao_usadas = malloc(sizeof(int)*num_palavras);
    for(i=0;i<num_palavras;i++) s.nao_usadas[i] = 1;

 
            

    for (i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){

           
            if (retorna(&tabuleiro,i,j) != '*'){
                     
            if(LugaresVazios_linha(&tabuleiro, colunas, linhas, i,j,matriz_de_palavras,num_palavras,tamanho,s)&&
            LugaresVazios_coluna(&tabuleiro, colunas, linhas, i,j,matriz_de_palavras,num_palavras,tamanho,s)) 
                continue;
            /*else recursão;*/

            }

        }
    }

       printf("tabuleiro : \n");
    print_tab(&tabuleiro);

/*
for(i = 0; i < strlen(espaco); i++){
    escrever_tab(&tabuleiro, a,b - start + i,matriz_de_palavras[a][i]);
}*/
    return 0; 


}