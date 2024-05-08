#include <stdio.h>
#include <string.h>
#include "pilha2.h"
#include <stdlib.h>

/* Entendendo o Código: 
--> primeiro acha-se alguma posição '0' no tabuleiro 
--> verifica-se se há a possibilidade de colocar na linha (se tiver, é colocada)
--> verifica-se se há a possibilidade de colocar na coluna (se tiver, é colocada)
--> se não tiver uma das duas, é desempilhada a anterior e colocada outra de acordo com o seu modo
 - modo 0 para linhas e 1 para colunas
*/

typedef struct{

    char *posicoes;
    int linhas;
    int colunas;

} matriz;

void print_tab(matriz *tab);
int backtracking(matriz *tabuleiro, int m, int n ,int linha, int coluna, char **M, int numero_palavras, int* tamanho, pilha *p, int *nao_usadas, int *bck_lin,int *bck_col);
void escrever_tab( matriz *tabuleiro, int lin, int coluna, char c);
char retorna(matriz *tabuleiro, int lin, int col);
char **Palavras(int n);
int *TamanhoDasPalavras(char **M,int n);
int match(char *espaco, char *palavra);
int LugaresVazios_linha(matriz *tabuleiro, int m, int n ,int linha, int coluna, char **M, int numero, int* tamanho, item s, pilha*p,int *nao_usadas,int ultima);
int LugaresVazios_coluna(matriz *tabuleiro, int m, int n ,int linha, int coluna, char **M, int numero, int* tamanho, item s, pilha *p,int *nao_usadas, int ultima);





/* coloca algum caractere no tabuleiro*/
void escrever_tab( matriz *tabuleiro, int lin, int coluna, char c){

    tabuleiro->posicoes[tabuleiro->colunas * lin + coluna] = c;
}

/* retorna qual o caractere daquela posição do tabuleiro*/
char retorna(matriz *tabuleiro, int lin, int col){

    return (tabuleiro->posicoes[tabuleiro->colunas * lin + col]);

}

/*faz uma matriz com palavras de diferentes tamanhos cada uma*/
char **Palavras(int n){

    int i;
    char **matriz_de_palavras = malloc(sizeof(char*)*n);
    for(i=0;i<n;i++){
        matriz_de_palavras[i] = malloc (sizeof(char)*256);
       scanf("%s", matriz_de_palavras[i]);
            
    }

    return matriz_de_palavras;

}

/* faz m vetor onde cada linha é o tamanho (strlen) de uma palavra*/
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


/*Nessa função eu passo ponto por ponto do tabuleiro que seja diferente de '*' e verifico tanto a linha em que a posição esta posicionada, quanto a coluna */
/* Se é possivel de colocar palavras presentes na Matriz de Palavras, essas são empilhadas e impressas no tabuleiro; Caso negativo, é chamada a função backtracking*/
int pos (matriz *tabuleiro, int m, int n ,int linha, int coluna, char **M, int numero, int* tamanho, item s, pilha*p,int *nao_usadas,int ultima, int *bck_lin,int *bck_col){
    int ok=0;
    if(LugaresVazios_linha(tabuleiro, m, n, linha,coluna,M,numero,tamanho,s, p,nao_usadas,0)) ok =1;
    else ok += backtracking(tabuleiro,m,n,linha,coluna,M,numero,tamanho,p,nao_usadas, bck_lin,bck_col);

    if(LugaresVazios_coluna(tabuleiro, m, n, linha,coluna,M,numero,tamanho,s,p,nao_usadas,0)) ok++;
    else ok += backtracking(tabuleiro,m,n,linha,coluna,M,numero,tamanho,p,nao_usadas, bck_lin,bck_col);

    if(ok == 2) return 1;
    return 0;

}


/*Na função de verificação do espaço vazio na linha ele vai pegar toda a linha (mesmo que envolva casas anteriores à posição dada) e vai salvar em uma string*/
/* Essa string com os lugares é chamada de PALAVRA*/
/* um exemplo de palavra é 'ca00' */
/*Depois é verificado se existe alguma palavra que caiba nesse espaço de PALAVRA*/
/*Para isso foi utilizada a função match, que verificaria que 'casa' cabe em 'ca00' */
/* caso não exista uma palavra que caiba, ele faz o backtracking*/
int LugaresVazios_linha(matriz *tabuleiro, int m, int n ,int linha, int coluna, char **M, int numero, int* tamanho, item s, pilha*p,int *nao_usadas,int ultima){

    
    int x = coluna;
    int y; /*serve pra salvar o numero de x*/
    char *palavra = malloc(sizeof(char)*256); /*Nesse vetor de char ficará o espaço de cada palavra; ex: C000*/
    int i=0; 
    int cont = 0;
    int ok = 0; /* utilizado para saber se é possível colocar alguma palavra do banco de palavras na posição "PALAVRA"*/
    int k;

                   
    if(m== 0 && n == 0) {
        free(palavra);
        return 0;
    }
    
    /* aqui pega-se a primeira casa livre da linha para começar a colocar a palavra */
    while (x>=0 && tabuleiro->posicoes[tabuleiro->colunas * linha + x] != '*'){ 
        if(x>0){
        if (tabuleiro->posicoes[tabuleiro->colunas * linha + --x] != '*')continue;
        else  {x++;break;}
        }break;
    }

    if(x<0) x = 0;
    y = x;
    /* aqui verifica-se o tamanho de casas livres na linha partindo do começo, medido anteriromente */
    while(x<(n) && tabuleiro->posicoes[tabuleiro->colunas * linha + x] != '*'){
        palavra[i++] = tabuleiro->posicoes[tabuleiro->colunas * linha + x];
       cont++;
        x++;
    }

    palavra[i] = 0; /*strings terminam com 0 /feito para evitar erros/ */
    if(i< 2) ok =1;/* se o espaço é pequeno não há necessidade de testar palavras*/
        
   /* k = ultima é utilizado para evitar repetições nos casos de backtracking, daí a palavra testada é a próxima */
    for(k = ultima; k < numero; k++){
        /*Se existir uma palavra de mesmo tamanho e que caiba perfeitamente no espaço, emplilha-se e coloca-se essa palavra no tabuleiro*/
        if(tamanho[k] == cont && match(palavra,M[k]) && !ok){

             
            ok =1;
            

            if(nao_usadas[k]){ /* é empilhado se não foi utilizada ainda e é impresso no tabuleiro */
            for(i = 0; i< tamanho[k];i++){
                
                if(nao_usadas[k]){
                free(s);
                s = malloc(sizeof(estado));
                s->space = palavra;
                s->ultima_palavra = k;
                s->coord_col = coluna;
                s->coord_lin = linha;
                s->modo = 0;
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



    


/* FIM do FILA*/


if(ok>0) return 1;
return 0; 
}

/*Na função de verificação do espaço vazio na coluna ele vai pegar toda a coluna (mesmo que envolva casas anteriores à posição dada) e vai salvar em uma string*/
/* Essa string com os lugares é chamada de PALAVRA*/
/* um exemplo de palavra é 'ca00' */
/*Depois é verificado se existe alguma palavra que caiba nesse espaço de PALAVRA*/
/*Para isso foi utilizada a função match, que verificaria que 'casa' cabe em 'ca00' */
/* caso não exista uma palavra que caiba, ele faz o backtracking*/
int LugaresVazios_coluna(matriz *tabuleiro, int m, int n ,int linha, int coluna, char **M, int numero, int* tamanho, item s, pilha *p,int *nao_usadas, int ultima){

    int x = linha;
    char *palavra = malloc(sizeof(char)*256);
    int y;
    int i = 0;
    int cont = 0;
    int ok = 0;
    int k;



    /* aqui pega-se a primeira casa livre da linha para começar a colocar a palavra */
    while (x>=0 && tabuleiro->posicoes[tabuleiro->colunas * x + coluna] != '*'){ 
        if(x>0){
        if (tabuleiro->posicoes[tabuleiro->colunas * (--x) + coluna] != '*')continue;
        else  {x++;break;}
        }  break;
    }

    if(x<0) x = 0;
    y = x;

/* aqui verifica-se o tamanho de casas livres na linha partindo do começo, medido anteriromente */
    while(x<(m) && tabuleiro->posicoes[tabuleiro->colunas * x + coluna] != '*'){
        palavra[i++] = tabuleiro->posicoes[tabuleiro->colunas * x + coluna];
       cont++;
        x++;
        
    }
    palavra[i] = 0;

    if(i<2) ok =1; /* se o espaço é pequeno não há necessidade de se testar palavras*/
    
   for(k = ultima; k < numero; k++){
        /*Se existir uma palavra de mesmo tamanho e que caiba perfeitamente no espaço, emplilha-se e coloca-se essa palavra no tabuleiro*/
        if(tamanho[k] == cont && match(palavra,M[k]) && !ok){
           
               /*printf(" COLUNA: %s\n", M[k] );*/
            ok =1;
            if(nao_usadas[k]){ /* se ainda não foi usada, é empilhada e impressa no tabuleiro*/
               


                for(i = 0; i< tamanho[k];i++){


                    if(palavra[i] == '0'){
                        escrever_tab(tabuleiro,y++,coluna,M[k][i]);
                    }
                    else y++;
                    
                }
                if(nao_usadas[k]) { 
                    free(s);
                    s = malloc(sizeof(estado));
                    s->coord_col = coluna;
                    s->coord_lin = linha;                    
                    s->space = palavra;
                    s->ultima_palavra = k;
                    s->modo = 1;
                    empilha(p,s);

                }nao_usadas[k] = 0;
            }
            

            break;
        }
    }





if(ok) return 1; 
return 0;

}

/* Printa o tabuleiro inteiro no terminal */
void print_tab(matriz *tab){
    int i,j; 
    for( i=0;i< tab->linhas ;i++){
        for(j = 0; j<tab->colunas; j++){
            printf("%c ", retorna(tab, i, j));
        }
        printf("\n");
    }
}


/* essa função desempilha e manipula os valores desempilhados para continuar a procura do tabuleiro completo */
/* Utiliza-se a ideia de backtracking para achar uma solução a "força", ou seja, vamos tentar ir voltando e procurando uma solução para o tabuleiro */
/* Como foi visto pela 'pos' que não há como colocar alguma palavra (seja ela na horizontal ou vertical), sabe-se que tem que tirar alguma */
/* Então, a função backtracking tira uma palavra e chama a função linha ou coluna para trntar encaixar outra palavra, diferente da anterior */
int backtracking(matriz *tabuleiro, int m, int n ,int linha, int coluna, char **M, int numero_palavras, int* tamanho, pilha *p, int *nao_usadas,int *bck_lin,int *bck_col){
    int i;
    item x;
    if(pilhaVazia(p)){return 0;}
    x = desempilha(p);
    *bck_lin = x->coord_lin;
    *bck_col = x->coord_col;

    nao_usadas[x->ultima_palavra] = 1;
    if(x->modo == 0){
        
        /*Aqui é retirada a palavra inteira e colocado aquela "PALAVRA" da função acima, por ex:*/
        /* Se antes estava casa, com o backtracking é colocado no tabuleiro 'ca00' */
        for(i = 0; i < strlen(M[x->ultima_palavra]); i++){
            escrever_tab(tabuleiro,x->coord_lin,x->coord_col+i,x->space[i]);
        }
        free(x->space);
        /* É chamada a função LuugaresVazios_linha com a questão de se enviar qual foi a ultima palavra usada e, para assim, não se repetir a palavra retirada*/
        return LugaresVazios_linha(tabuleiro, m, n, x->coord_lin,x->coord_col,M,numero_palavras,tamanho,x, p,nao_usadas,x->ultima_palavra+1);
    }
    else {

        /* Aqui é retirada a palavra inteira e colocado aquela "PALAVRA" da função acima, por ex:*/
        /* Se antes estava casa, com o backtracking é colocado no tabuleiro 'ca00' */
        for(i = 0; i < strlen(M[x->ultima_palavra]); i++){
            escrever_tab(tabuleiro,x->coord_lin +i ,x->coord_col,x->space[i]);
        }
        free(x->space);
        if(x->ultima_palavra+1 == m) return 0;
        /* É retornada a função LugaresVazios_coluna com o detalhe de se enviar qual foi a ultima palavra para evitar repetições */
        return LugaresVazios_coluna(tabuleiro, m, n, x->coord_lin,x->coord_col,M,numero_palavras,tamanho,x, p,nao_usadas,x->ultima_palavra+1);
    }

}

int main(){

    int linhas=1,colunas=1,i,j; /*tamanho do tabuleiro, vai ser alterado a cada eitura*/
    int num_palavras; /* o número de palavras a ser lido a cada repetição */
    char **matriz_de_palavras; /* na qual serão savas as palavras a serem lidas */
    int *tamanho; /* armazena o tamanho de cada palavra; PS: nesse EP cada palavra pode ser representada por uma letra, referente à sua linha na MatrizDePalavras*/
    int f; /* utilizado na leitura*/
    int ok; /* utilizado no backtracking e verificação de se há solução para o tabuleiro */
    item s; 
    matriz tabuleiro; 
    pilha *p = cria();
    int *nao_usadas; /* vetor de 0 ou 1 no qual diz se as palavras foram utilizadas ou não */
    int ultima; /* o valor da ultima palavra empilhada */
    int bck_lin,bck_col; /* utilizado no backtracking */
    int auxiliar; /* utilizado para parar o programa quando não houver solução */ 
    int instancia = 1; /* utilizado no print */

    while(linhas != 0 && colunas != 0){

        while(!pilhaVazia(p)){ s = desempilha(p); free(s->space);free(s);} /* sempre desempilha a pilha utilizada anteriormente */

    scanf("%d %d", &linhas, &colunas);
            if(linhas == 0 && colunas == 0) return 0; /* acaba com o programa caso leia "0 0" */

    auxiliar = 1;

    tabuleiro.posicoes = malloc(sizeof(char)*linhas*colunas);
    tabuleiro.linhas = linhas;
    tabuleiro.colunas= colunas;

    /* lê o tabuleiro */
    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){
            scanf(" %d", &f);
            if(f != 0) escrever_tab(&tabuleiro,i,j,'*');
            else escrever_tab(&tabuleiro,i,j,'0');

        }
    }


    scanf("%d", &num_palavras);

    matriz_de_palavras = Palavras(num_palavras);


    tamanho = TamanhoDasPalavras(matriz_de_palavras,num_palavras);

   
    nao_usadas = malloc(sizeof(int)*num_palavras);
    for(i=0;i<num_palavras;i++) nao_usadas[i] = 1;
    s = NULL;
 
            
    /*Passa por cada posição do tabuleiro */
    for (i=0;i<linhas&&auxiliar;i++){
        for(j=0;j<colunas&&auxiliar;j++){

           
            if (retorna(&tabuleiro,i,j) != '*'){
                /* se alguma posição for "0" */

                ok = 0;
                ultima = 0;
                bck_lin =0;
                bck_col = 0;
                /* chama o 'pos' */
                ok = pos(&tabuleiro, linhas, colunas, i,j,matriz_de_palavras,num_palavras,tamanho,s, p,nao_usadas,ultima,&bck_lin,&bck_col);
                /* chama o 'pos' */
                
                /* caso o 'pos' não dê certo, tenta-se desempilhar mais uma vez */
                if(!ok && !pilhaVazia(p)) ok += backtracking(&tabuleiro,linhas,colunas,i,j,matriz_de_palavras,num_palavras,tamanho,p,nao_usadas, &bck_lin,&bck_col);
                if(bck_col!=0){
                    j = bck_col;
                    j--;
                    if(j<0) j = 0;
                }
                if(bck_lin!=0){
                    i = bck_lin;
                    i--;
                    if(i<0) i = 0;
                }
                if (!ok){
                    auxiliar = 0;
                }        
            }

        }
    }


    
    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){

        if(retorna(&tabuleiro,i,j) == '0') ok = 0;
    }}

    printf("\nInstância %d: \n", instancia++);

    /* Se nao tem  nenhum '0' no tabuleiro e ele não foi totalmente preenchido, sabe-se que não há solução */
    if(pilhaVazia(p) || !ok || !auxiliar) printf("\n\nNão há solução \n\n");

    else { /* caso contrário, está tudo certo. */
        print_tab(&tabuleiro);
    } 
    printf("\n\n");
    /* São realizados todos os frees dos mallocs dados anteriormente durante o programa*/
    for(i=0;i<num_palavras;i++)  free(matriz_de_palavras[i]);
    free(matriz_de_palavras);
    free(nao_usadas);
    free(tabuleiro.posicoes);
    free(tamanho);
    

    }
    return 0;
}