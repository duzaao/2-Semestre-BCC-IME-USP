#include <stdio.h>
#include <stdlib.h>

int eh_primo(long int num){
    long int i;
    for (i=2;i*i<=num;i++) if (num%i==0) return 0; /* verifica se algum número menor que a raiz quadrada do nº inserido divide ele, caso contrário, sabe-se que esse numero é primo*/

    return 1; 
}

int main(){

    long int numero, procurando_num;
    int modo;
    long int i,j;

    scanf("%d %ld", &modo, &numero); /*read*/
    procurando_num = numero+1; /* já adiciona um porque não é necessário verificar se o proprio número é primo */

    if (modo == 0) {

        while(!eh_primo(procurando_num)) procurando_num++;   /* procura o proximo primo*/
        printf("%ld", procurando_num);   

    }

    else {

        for (i=2;i*i<=numero;i++){
            if((numero%i==0)){ /* procura o primeiro número que divide; que será primo obrigatoriamente */
                
                j = numero/i; /* divide e verifica se j é primo, se for, sabe-se que existem dois primos que multiplicados resultam naquele número */
                if(eh_primo(j)){
                    printf("%ld %ld", i,j); /*Write*/
                
                }
                break;
            
            }
        }

    }

return 0;
}
