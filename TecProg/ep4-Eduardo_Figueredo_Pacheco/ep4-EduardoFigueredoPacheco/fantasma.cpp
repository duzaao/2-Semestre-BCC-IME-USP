#include "fantasma.h"

Fantasma::Fantasma(Labirinto* labirinto,int x, int y) : Personagem(labirinto,x,y,'F',0){
}




int Fantasma::move_fantasma(char caractere){ /* Nessa função é possível mudar a posição do pacman a partir de um parametro caractere que repreenta a proxima posição a ser seguida pelo pacman */

            int proximo_y = this->y;
            int proximo_x = this->x;



            
            if(eh_parede(caractere)) return 0;
            if (caractere == ESQUERDA){

                    proximo_x--;  
            }
            else if (caractere == CIMA){
                
                    proximo_y--;
            }
            else if (caractere == BAIXO){
                
                    proximo_y++;
            }
            else if (caractere == DIREITA){
                
                    proximo_x++;
            }
            

            
            if(labirinto->getMapa()[this->x][this->y] == 'C')
            labirinto->setPosicao(mod(this->y,labirinto->getLinhas()),mod(this->x,labirinto->getColunas()),'C');
                else if(getElemento()!= 'F')
                    labirinto->setPosicao(mod(this->y,labirinto->getLinhas()),mod(this->x,labirinto->getColunas()),getElemento());
            setElemento(labirinto->getPosicao(mod(proximo_y,labirinto->getLinhas()),mod(proximo_x,labirinto->getColunas())));
            labirinto->setPosicao(mod(proximo_y,labirinto->getLinhas()),mod(proximo_x,labirinto->getColunas()),this->tipo);
            set_posicao(mod(proximo_y,labirinto->getLinhas()),mod(proximo_x,labirinto->getColunas()));
            return 1;
}


void Fantasma::moveAleatorio(){
    char direcaoFantasma[4];
    direcaoFantasma[0] = 'w';
    direcaoFantasma[1] = 'a';
    direcaoFantasma[2] = 's';
    direcaoFantasma[3] = 'd';

    random_device aleatorio;
    unsigned semente = aleatorio();
    default_random_engine gerador(semente);

    uniform_int_distribution<int> distrI(0, 3);

    while(!move_fantasma(direcaoFantasma[distrI(gerador)])){
        if(move_fantasma(direcaoFantasma[distrI(gerador)]))
            break;
    }
    
}

char Fantasma::getElemento(){
    return this->elementoAnterior;
}

void Fantasma::setElemento(char elemento){
    this->elementoAnterior = elemento;
}

int Fantasma::contaCaminhos(){ /* até então nao utilizado */

    int caminhos = 0;
    int proximo_x, proximo_y;
    proximo_x = this->x;
    proximo_y = this->y;
    printf("proxX = %d, proxY = %d, getLinhas = %d, getCol = %d", proximo_x, proximo_y,labirinto->getLinhas(),labirinto->getColunas());
        if(labirinto->getMapa()[mod(proximo_y,labirinto->getLinhas())][mod(proximo_x-1,labirinto->getColunas())] == '.'){
            caminhos++;
        }
    
    
    
        if( labirinto->getMapa()[mod(proximo_y,labirinto->getLinhas())][mod(proximo_x+1,labirinto->getColunas())]  == '.'){
            caminhos++;
        }
    

        if( labirinto->getMapa()[mod(proximo_y-1,labirinto->getLinhas())][mod(proximo_x,labirinto->getColunas())]  == '.'){
            caminhos++;
        }
    
    
        if( labirinto->getMapa()[mod(proximo_y+1,labirinto->getLinhas())][mod(proximo_x,labirinto->getColunas())]  == '.'){
            caminhos++;
        }
        
    return caminhos;
}