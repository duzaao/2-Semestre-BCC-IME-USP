#pragma once
#include <iostream>
#include <fstream>
#include <random>
#include "labirinto.h"

#define MORTO 0
#define VIVO 1

#define ESQUERDA 'a'
#define DIREITA 'd'
#define CIMA 'w'
#define BAIXO 's'

using namespace std;

class Personagem {
    protected:
        int x;
        int y;
        int status;
        char tipo;
        Labirinto* labirinto;


    public:



        /*!  \brief  Constructor: Personagem
         *  Uso: usuario = Personagem(labirinto,x, y, char tipo, status);
         *  \param labirinto : (Labirinto*) Essa função recebe como parâmetro um ponteiro para o labirinto 
         *  \param x : (int) Essa função recebe como parâmetro um inteiro referente a posição do personagem no mapa
         *  \param y : (int) Essa função recebe como parâmetro um inteiro referente a posição do personagem no mapa
         *  \param tipo : (char) Essa função recebe como parâmetro um caractere referente ao tipo do personagem (se é fantasma ou pacman)
         *  \param status : (int) Essa função recebe como parâmetro um inteiro referente ao status do personagem
         *  Nesse Constructor é possível receber a classe Personagem
         */      
        Personagem(Labirinto* labirinto,int x, int y, char tipo, int status);


        /*!  \brief  Destructor: ~Personagem
        *  Uso: ~Personagem();
        *  Nessa função é possível destruir a classe Personagem
        */              
        ~Personagem();


        /*!  \brief  Função: getX
         *  Uso: x = getX();
         *  Essa função devolve a linha que se encontra aquele personagem no labirinto
         *  \return retorno: (int) retorna a posição da linha do personagem no mapa
         */  
        int getX(); 


        /*!  \brief  Função: getY
         *  Uso: x = getY();
         *  Essa função devolve a coluna que se encontra aquele personagem no labirinto
         *  \return retorno: (int) retorna a posição da coluna do personagem no mapa
         */  
        int getY(); 


        /*!  \brief  Função: set_posicao
         *  Uso: set_posicao( x,  y);
         *  \param x : (int) Essa função recebe um inteiro referente a posição da coluna do personagem no mapa
         *  \param y : (int) Essa função recebe um inteiro referente a posição da linha do personagem no mapa
         *  Essa função é responsável por atualizar a posição do personagem no mapa
         */  
        void set_posicao(int x, int y); 

       
        /*!  \brief  Função: get_status
         *  Uso: x = get_status();
         * Essa função retorna o status do personagem 
         *  \return retorno: (int) retorna o status do personagem
         */  
        int get_status(); 


        /*!  \brief  Função: eh_parede
         *  Uso: x = eh_parede(direction);
         *  \param direction : (char) Essa função recebe a direção que o personagem quer se mover 'wasd'
         *  Essa função é responsável por retornar se a posição que o personagem quer ir é valida ou não.
         *  \return retorno: (int) 1 caso o lugar que o usuário está se intensionando a ir seja inválido e (int) 0 caso eteja livre
         */  
        int eh_parede(char direction);


        /*!  \brief  Função: mod
         *  Uso: x = mod(numero, delimitador);
         *  Essa função impede do personagem sair do tabuleiro.
         * \param numero : (int) Essa função recebe um inteiro referente a posição que se deseja analisar
         * \param delimitador : (int) Essa função recebe um inteiro referente aos delimitadores do tabuleiro
         *  \return retorno: (int) retorna o módulo do número que estiver fora do tabuleiro, garantindo que sempre esteja dentro do tabuleiro
         */  
        int mod(int numero, int delimitador); 


        /*!  \brief  Função: set_status
         *  Uso: set_status(status);
         *  Essa função impede do personagem sair do tabuleiro.
         * \param status : (int) Essa função recebe um inteiro referente o status do personagem
         */  
        void set_status(int status);


        /*!  \brief  Função: move_pers
         *  Uso: move_pers(caractere);
         *  Essa função impede do personagem sair do tabuleiro.
         * \param caractere : (char) Essa função recebe um char referente a posição que se deseja movimentar o personagem
         */  
        void move_pers(char caractere);

};