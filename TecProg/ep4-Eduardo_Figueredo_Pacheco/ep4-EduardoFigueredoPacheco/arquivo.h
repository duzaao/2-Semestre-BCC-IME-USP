#ifndef _ARQ_
#define _ARQ_

#pragma once
#include <iostream>
#include <fstream>
#include <random>
#include "labirinto.h"
#include "fantasma.h"

using namespace std;

class arquivo {
    private:
    Labirinto *labirinto;
    Fantasma** F;
    int *posFantasma;

    public:

        /*!  \brief  Constructor: arquivo
         *  Uso: arq = arquivo(nome);
         *  Nesse Constructor é possível receber a classe arquivo
         */      
        arquivo(char*nome);

        /*!  \brief  Destructor: ~arquivo
        *  Uso: ~arquivo();
        *  Nessa função é possível destruir a classe arquivo
        */      
        ~arquivo();

        
        /*!  \brief  Função: getMapa
         *  Uso: mapa = getMapa();
         *  Nessa função é possível receber o próprio labirinto
         *  \return retorno: (Labirinto*) retorna o tabuleiro
         */            
        Labirinto* getMapa();

        /*!  \brief  Função: getFantasma
         *  Uso: F = getFantasma();
         *  Nessa função é possível receber os fantasmas
         *  \return retorno: (Fantasma**) retorna o ponteiro de ponteiros de fantasmas
         */        
        Fantasma** getFantasma();


};

#endif