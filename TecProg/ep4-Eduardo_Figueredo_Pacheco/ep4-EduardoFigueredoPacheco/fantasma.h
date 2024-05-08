#pragma once
#include <iostream>
#include <fstream>
#include <random>
#include "personagem.h"
#include "labirinto.h"

#define CIMA 'w' 
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'

using namespace std;

class Fantasma: public Personagem {
    private:
        char direção;
        char elementoAnterior;
    public:


        /*!  \brief  Função: Fantasma
         *  Uso: arq = Fantasma(labirinto,x, y);
         *  \param labirinto : (Labirinto*) Essa função recebe um ponteiro para o labirinto do jogo
         *  \param x : (int) Essa função recebe a posição de colunas do fantasma no mapa
         *  \param y : (int) Essa função recebe a posição de linhas do fantasma no mapa
         *  Nessa função é possível receber a classe Fantasma (constructor)
         */      
        Fantasma(Labirinto* labirinto,int x, int y);

        /*!  \brief  Destructor: ~Fantasma
         *  Uso: ~Fantasma();
         *  Nessa função é possível destruir a classe Fantasma
         */      
        ~Fantasma();

        /*!  \brief  Função: move_fantasma
         *  Uso: c = move_fantasma( x, y);
         *  \param caractere : (char) Essa função recebe um caractere 'wasd' referente a próxima direção do fantasma
         * Nessa função é possível mudar a posição do fantasma a partir de um parametro caractere que repreenta a proxima posição a ser seguida pelo pacman 
         * \return retorno: Retorna (int) 1 caso seja possível mover o fantasma para aquela posição no labirinto e (int) 0 caso contrário
         */
        int move_fantasma(char caractere);





        /*!  \brief  Função: moveAleatorio
         *  Uso: moveAleatorio();
         *  Essa função faz com que o movimento do fantasma seja aleatorizado
         */
        void moveAleatorio();


        /*!  \brief  Função: setElemento
         *  Uso: setElemento(elemento);
         *  \param x : (char) Essa função recebe um caractere referente a posição do mapa que será ocupada pelo fantasma
         */
        void setElemento(char elemento);



        /*!  \brief  Função: getElemento
         *  Uso: c = getElemento();
         * \return retorno: (char) Retorna o caractere que o fantasma está em cima, para evitar do fantasma modificar o labirinto
         */
        char getElemento();



        /*!  \brief  Função: contaCaminhos
         *  Uso: c = contaCaminhos();
         * \return retorno: (int) Retorna a quantidade de caminhos possíveis que o fantasma pode ir
         */
        int contaCaminhos();
};

