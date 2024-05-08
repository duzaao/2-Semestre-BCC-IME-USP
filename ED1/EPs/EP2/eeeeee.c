#include <stdio.h>
#include <string.h>
#include "pilha2.h"
#include <stdlib.h>


typedef struct{

    char *posicoes;
    int linhas;
    int colunas;

} matriz;

void print_tab(matriz *tab);
int backtracking(matriz *tabuleiro, int m, int n ,int linha, int coluna, char **M, int numero_palavras, int* tamanho, pilha *p, int *nao_usadas);
void escrever_tab( matriz *tabuleiro, int lin, int coluna, char c);
char retorna(matriz *tabuleiro, int lin, int col);
char **Palavras(int n);
int *TamanhoDasPalavras(char **M,int n);
int match(char *espaco, char *palavra);
int LugaresVazios_linha(matriz *tabuleiro, int m, int n ,int linha, int coluna, char **M, int numero, int* tamanho, item s, pilha*p,int *nao_usadas,int ultima);
int LugaresVazios_coluna(matriz *tabuleiro, int m, int n ,int linha, int coluna, char **M, int numero, int* tamanho, item s, pilha *p,int *nao_usadas, int ultima);






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

int pos (matriz *tabuleiro, int m, int n ,int linha, int coluna, char **M, int numero, int* tamanho, item s, pilha*p,int *nao_usadas,int ultima){
    int ok;
    if(LugaresVazios_linha(tabuleiro, m, n, linha,coluna,M,numero,tamanho,s, p,nao_usadas,0)) ok =1;
    else ok += backtracking(tabuleiro,m,n,linha,coluna,M,numero,tamanho,p,nao_usadas);

    if(LugaresVazios_coluna(tabuleiro, m, n, linha,coluna,M,numero,tamanho,s,p,nao_usadas,0)) ok++;
    else ok += backtracking(tabuleiro,m,n,linha,coluna,M,numero,tamanho,p,nao_usadas);

    if(ok == 2) return 1;
    return 0;

}

int LugaresVazios_linha(matriz *tabuleiro, int m, int n ,int linha, int coluna, char **M, int numero, int* tamanho, item s, pilha*p,int *nao_usadas,int ultima){

    
    int x = coluna;
    int y; /*serve pra salvar o numero de x*/
    char *palavra = malloc(sizeof(char)*256);
    int i=0;
    int cont = 0;
    int ok = 0;
    int k;

                   

    
    while (x>=0 && tabuleiro->posicoes[tabuleiro->colunas * linha + x] != '*'){ 
        if (tabuleiro->posicoes[tabuleiro->colunas * linha + --x] != '*')continue;
        else  {x++;break;}
    }

    if(x<0) x = 0;
    y = x;
    while(x<(n) && tabuleiro->posicoes[tabuleiro->colunas * linha + x] != '*'){
        palavra[i++] = tabuleiro->posicoes[tabuleiro->colunas * linha + x];
       cont++;
        x++;
    }
    
   /*
                
                s.space = palavra;
                s.coord_col = (coluna - y);
                s.coord_lin = linha;
                s.modo = 0;
                s.possiveis = 0;

*/
                /*chute */
    if(strlen(palavra) < 2) {ok =1;printf("TA INDO");}
        
   
    for(k = ultima; k < numero; k++){
printf("\n\nACHANDO ERRO :%s\n", M[k]);
        if(tamanho[k] == cont && match(palavra,M[k]) && !ok){

             
            printf("\nLINHA : %s  ", M[k] );
            ok =1;
            

            if(nao_usadas[k]){
            for(i = 0; i< tamanho[k];i++){
                
                if(nao_usadas[k]){
                s = malloc(sizeof(estado));
                s->space = palavra;
                s->ultima_palavra = k;
                s->coord_col = coluna;
                s->coord_lin = linha;
                s->modo = 0;
                printf("\nEMPILHA: %s",M[k]);

                empilha(p,s); /**/
                }
                nao_usadas[k] = 0;
                
                
                if(palavra[i] == '0'){
                 escrever_tab(tabuleiro,linha,y++,M[k][i]);
                 
                }
                else y++;
            }
                
            

           /* empilha(&p,s);*/
            
            break;
            } /* nao escreve se ela ja estiver la */
        }
    }



    

printf("\n");
                         /**/
    print_tab(tabuleiro);
                     /**/
    if(!ok&&!pilhaVazia(p)){
        printf("%s",palavra);
        ok = backtracking(tabuleiro,m,n,linha,coluna,M,numero,tamanho,p,nao_usadas);}
       
        printf("\n");                 /**/
    print_tab(tabuleiro);
                     /**/

/* FIM do FILA*/

if(ok>0) return 1;
return 0; 
}

/* caso o espaço seja maior ou igual a 2 a função retorna uma string com as possibilidades, tipo " a or": podendo dar match com "calor"*/
int LugaresVazios_coluna(matriz *tabuleiro, int m, int n ,int linha, int coluna, char **M, int numero, int* tamanho, item s, pilha *p,int *nao_usadas, int ultima){

    int x = linha;
    char *palavra = malloc(sizeof(char)*256);
    int y;
    int i = 0;
    int cont = 0;
    int ok = 0;
    int k;



 
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


    if(strlen(palavra)<2) ok =1;
    
   for(k = ultima; k < numero; k++){
        if(tamanho[k] == cont && match(palavra,M[k]) && !ok){
           
               printf(" COLUNA: %s\n", M[k] );
               ok =1;
            
            if(nao_usadas[k]){


                for(i = 0; i< tamanho[k];i++){


                    if(palavra[i] == '0'){
                        escrever_tab(tabuleiro,y++,coluna,M[k][i]);
                    }
                    else y++;
                    
                }
                if(nao_usadas[k]) {
                    s = malloc(sizeof(estado));
                    s->coord_col = coluna;
                    s->coord_lin = linha;                    
                    s->space = palavra;
                    s->ultima_palavra = k;
                    s->modo = 1;
                    printf("\nEMPILHA: %s\n",M[k]);
                    empilha(p,s);

                }nao_usadas[k] = 0;
            }
            
            
            break;
        }
    }





if(ok) return 1; 
return 0;
/*if(!ok&&!pilhaVazia(p)) ok = backtracking(tabuleiro,m,n,linha,coluna,M,numero,tamanho,p,nao_usadas);
return ok;*/


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



int backtracking(matriz *tabuleiro, int m, int n ,int linha, int coluna, char **M, int numero_palavras, int* tamanho, pilha *p, int *nao_usadas){
    int i;
    item x;
    if(pilhaVazia(p)){return 0;}
    x = desempilha(p);


    printf("\nDESEMPILHOU a palavra %s\n",M[x->ultima_palavra]);

    nao_usadas[x->ultima_palavra] = 1;
    if(x->modo == 0){

        for(i = 0; i < strlen(M[x->ultima_palavra]); i++){
            escrever_tab(tabuleiro,x->coord_lin,x->coord_col+i,x->space[i]);
        }
        return LugaresVazios_linha(tabuleiro, m, n, linha,coluna,M,numero_palavras,tamanho,x, p,nao_usadas,x->ultima_palavra+1);
    }
    else {

        for(i = 0; i < strlen(M[x->ultima_palavra]); i++){
            escrever_tab(tabuleiro,x->coord_lin +i ,x->coord_col,x->space[i]);
        }
        if(x->ultima_palavra+1 == m) return 0;
        return LugaresVazios_coluna(tabuleiro, m, n, linha,coluna,M,numero_palavras,tamanho,x, p,nao_usadas,x->ultima_palavra+1);
    }

}

int main(){

    int linhas,colunas,i,j;
    int num_palavras;
    char **matriz_de_palavras;
    int *tamanho;
    int f;
    int ok;
    item s;
    matriz tabuleiro;
    pilha *p = cria();
    int *nao_usadas;
    int ultima;



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

   
    nao_usadas = malloc(sizeof(int)*num_palavras);
    for(i=0;i<num_palavras;i++) nao_usadas[i] = 1;
    s = NULL;
 
            

    for (i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){

           
            if (retorna(&tabuleiro,i,j) != '*'){


                ok = 0;
                ultima = 0;
                ok = pos(&tabuleiro, linhas, colunas, i,j,matriz_de_palavras,num_palavras,tamanho,s, p,nao_usadas,ultima);
    
                if (!ok){

                    printf("\n\nNÃO DEU!\n");
                    printf("tabuleiro : \n");
                     print_tab(&tabuleiro);
                    return 0;
                }        
            printf("\n+\n");
            }

        }
    }


       printf("tabuleiro : \n");
    print_tab(&tabuleiro);

    if(pilhaVazia(p) || !ok) printf("NÃO DEU!");
    else printf("TUUUUDO CERTO");
    return 0; 


}