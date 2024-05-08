#include <stdio.h>
#include <stdlib.h>
#include "aqui.h"


int ** alocamatriz (int linha, int coluna){

int i;
int ** mat = malloc(sizeof(int *)*linha);
for (i = 0; i< linha; i++) mat[i] = malloc(sizeof(int) * coluna);
return (mat);
}

void liberamatriz (int **mat, int linha){
    int i;
    for (i = 0; i< linha; i++) free (mat);
}

void imprimeMatriz( int **mat, int linha, int coluna){

    int i, j;
    for (i = 0; i<linha; i++){
        for (j=0; j<coluna; j++){

            if(mat[i][j] == 1){
                printf("R");
            }
            else printf(" ");
            printf("\n");
        }
    }
    
    printf("\n");

}

int posicaoLivre (int **mat, int n, int linha, int coluna){

int livre =1, i, j;

/* utilizado para verificar as diagonais*/
for(i = 0; i<linha; i++){

    j = coluna - linha + i;
    if( j >= 0 && mat[i][j] == 1) livre = 0;
    j = coluna + linha - i;
    if (j < n && mat[i][j] == 1) livre = 0;

}

return livre;
}

void nRainhas (int n, int flag){

    pilha * pos = cria();


}