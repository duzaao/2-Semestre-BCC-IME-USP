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



int main (){

    int i=1, j;
    char**M;
    char *palavra;
    int size = 10;
    FILE *entrada;
    entrada = fopen ("arquivo.txt", "r");

    byte *texto = readText(entrada);
   
        M = malloc(sizeof(char*)*1000);
        for(i=0;i<100;i++){
         M[i] = malloc(sizeof(char)*256);
        }
        
    for(j=0;j<i;j++){
        printf("%s",M[j]);
    }
    return 0;
}