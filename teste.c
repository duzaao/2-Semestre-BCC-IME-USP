#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef unsigned char byte;

byte *readText (FILE *infile)
{
   int n = 0, size = 128, ch;
   byte *line;
   line = malloc (size + 1);
   while ((ch = getc (infile)) != '\0' && ch != EOF) {
      if (n == size) {
         size *= 2;
         line = realloc (line, size + 1);
      }
      if(ch == '\n') ch =' ';
      line[n++] = ch;
   }
   if (n == 0 && ch == EOF) {
      free (line);
      return NULL;
   }
   line[n] = '\0';
   line = realloc (line, n + 1);
   return line;
}

/* essa função recebe a opção escrita em string pela função lugaresVazios e a compara com palavras do banco de palavras menores ou iguais àquela*/
int match(char *palavra1, char *palavra2){

    int i = 0;
    for (i = 0; i< strlen(palavra2); i++) {
        if (palavra1[i] == palavra2[i] || palavra1[i] == palavra2[i]-32 || palavra1[i]-32 == palavra2[i] )
            continue;
        
        return 0;
    }
    
    return 1;
}

int main (){

    int i=1, j, k;
    char**M;
    int *TAM,*repete;
    int repetida;
    int tamanho, chave=3;
    char *palavra;
    int size = 10;
    FILE *entrada;
    entrada = fopen ("arquivo.txt", "r");

    byte *texto = readText(entrada);
   
       M = malloc(sizeof(char*)*1000);
       TAM = malloc(sizeof(int)*1000);
       repete = malloc(sizeof(int)*1000);
        for(i=0;i<100;i++){
         M[i] = malloc(sizeof(char)*256);
         repete[i] = 1;
        }
            palavra = strtok(texto," ");
        if(palavra != NULL){
        strcpy(M[0],palavra);
        TAM[0] = strlen(palavra);
        }
        i=1;
        while(palavra != NULL){
            
            palavra = strtok(NULL, " ");
            if(palavra==NULL) continue;
            tamanho = strlen(palavra); /*pega o tamanho de cada palavra*/
            repetida = 0;
            for(k=0;k<i;k++){
                if(tamanho==TAM[k]){
                    if(match(palavra,M[k])){
                        repete[k]++;
                        repetida = 1;
                        break; 
                    }
                }
            }
            if(repetida) continue;
            M[i]=palavra; /* adiciona uma palavra somente se ela for nova*/
            TAM[i] = tamanho; /*salva o tamanho da palavra somete se ela for nova*/
            i++;
            
        }
    for(j=0;j<(i-1);j++){
        if(repete[j]==chave) printf("%s\n", M[j]);
    }
    return 0;
}