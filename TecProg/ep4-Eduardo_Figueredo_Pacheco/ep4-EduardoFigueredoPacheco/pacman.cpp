#include "pacman.h"
    
    Pacman::Pacman(Labirinto*labirinto,int x, int y):Personagem(labirinto,y,x,'C',1){
    }

    Pacman::~Pacman(){
        
    }
 
    void Pacman::somaBolinhas(int proximo_x, int proximo_y){
            if(labirinto->getPosicao(mod(proximo_y,labirinto->getLinhas()), mod(proximo_x,labirinto->getColunas())) == '.'){
                
                bolinhasPac = bolinhasPac+1;
            }
    }

    int Pacman::ganhou(){ /* Utilizado para verificar quando o usuário vence o jogo */
        if ( bolinhasPac >= (labirinto->get_bolinhas()-1) ) return 1;
        return 0;
    }

        void Pacman::zeraBolinhas(){
            this->bolinhasPac = 0;
        }

        int Pacman::getBolinhas(){
            return this->bolinhasPac;
        }
