#include "labirinto.h"
#include <cassert>
    char Labirinto::getPosicao(int x,int y){
        return mapa[y][x];
    }
    int Labirinto::get_bolinhas(){
        return this->quantidade_bolinhas;
    }
    int Labirinto::get_fantasmas(){ 
        return this->quantidade_fantasmas;
    }

    void Labirinto::setPosicao(int y, int x, char c){ 

        this->mapa[y][x] = c;
    }

    //Labirinto::Labirinto() {}

    Labirinto::Labirinto(char** mapa, int altura, int largura, int numeroBolinhas, int numeroFantasmas){

        assert(mapa!= 0);
        this->colunas = largura;
        this->linhas = altura;
        this->quantidade_bolinhas = numeroBolinhas;
        this->quantidade_fantasmas = numeroFantasmas;
        this->mapa = mapa;
        
    }

    int Labirinto::getLinhas(){
        return this->linhas;
    }
    int Labirinto::getColunas(){
        return this->colunas;
    }

    char** Labirinto::getMapa(){
            return this->mapa;
    }
