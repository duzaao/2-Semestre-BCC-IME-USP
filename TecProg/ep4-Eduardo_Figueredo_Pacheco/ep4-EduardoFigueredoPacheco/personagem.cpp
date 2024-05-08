#include "personagem.h"
#include <cassert>
#define MORTO 0
#define VIVO 1

#define ESQUERDA 'a'
#define DIREITA 'd'
#define CIMA 'w'
#define BAIXO 's'


using namespace std;

        Personagem::Personagem(Labirinto* labirinto, int x, int y, char tipo, int status){ /* ta com um erro aq nada a ver cara */

            this->labirinto=labirinto;
            this->x=x;
            this->y=y;
            this->tipo= tipo;
            this->status=status;
            
        }
        
        Personagem::~Personagem(){
            status = MORTO;
        }
        int Personagem::getX(){
            return x;
        }
        int Personagem::getY(){
            return y;
        }
        void Personagem::set_posicao(int y, int x){ /* Essa função é responsável por atualizar a posição do personagem no mapa */
            this->x = x;
            this->y = y;
        }
        
        int Personagem::get_status(){ /* Essa função retorna o status do personagem */
            return status;
        }
        int Personagem::eh_parede(char direction){ /* Essa função é responsável por retornar (int) 1 caso o lugar que o usuário está se intensionando a ir seja inválido e (int) 0 caso eteja livre */
            
            if(direction==ESQUERDA){
                if(x-1<0) x = x*(-1);
                if(labirinto->getMapa()[y][x-1] == '*'){
                    return 1;
                }
            }
            
            else if(direction==CIMA){
                if(y-1<0) y = y*(-1);
                if( labirinto->getMapa()[y-1][x]  == '*'){
                    return 1;
                }
            }

            else if(direction==BAIXO){
                if( labirinto->getMapa()[y+1][x]  == '*'){
                    return 1;
                }
            }
            
            else if(direction==DIREITA){
                if( labirinto->getMapa()[y][x+1]  == '*'){
                    return 1;
                }
            }
            return 0;
        }

        int Personagem::mod(int numero, int delimitador){


            if(numero<0) return delimitador + numero;
            
            return numero % delimitador;
            
        }


        void Personagem::move_pers(char caractere){ /* Nessa função é possível mudar a posição do pacman a partir de um parametro caractere que repreenta a proxima posição a ser seguida pelo pacman */

            int proximo_y = this->y;
            int proximo_x = this->x;
           

            if(eh_parede(caractere)) return;
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

            
            labirinto->setPosicao(mod(this->y,5),mod(this->x,labirinto->getColunas()),' ');
            
            labirinto->setPosicao(mod(proximo_y,5),mod(proximo_x,labirinto->getColunas()),this->tipo);
            set_posicao(mod(proximo_y,5),mod(proximo_x,labirinto->getColunas()));
            

    }

        void Personagem::set_status(int status){
            this->status = status;
        }
