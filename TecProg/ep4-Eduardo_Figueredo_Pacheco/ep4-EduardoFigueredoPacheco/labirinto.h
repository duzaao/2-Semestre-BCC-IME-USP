#ifndef _LAB_
#define _LAB_

#pragma once
#include <iostream>
#include <fstream>
#include <random>

using namespace std;

class Labirinto{
    private:

        char** mapa;
        int linhas;/* essa variável guarda a quantidade de linhas no labirinto*/
        int colunas;/* essa variável guarda a quantidade de colunas no labirinto*/
        int quantidade_bolinhas; /* essa variável guarda a quantidade de "dots" no labirinto*/
        int quantidade_fantasmas; /* essa variável guarda a quantidade de fantasmas do labirinto */
        
    public:



        //Labirinto(); 
        Labirinto(char** mapa, int altura, int largura, int quantidade_bolinhas,int quantidade_fantasmas); 

        /*!  \brief  Função: getPosicao
         *  Uso: c = getPosicao( x, y);
         *  \param x : (int) Essa função recebe um número referente a posição x (colunas do tabuleiro)
         *  \param y: (int) Essa função recebe um número referente a posição y (linhas do tabuleiro)   
         * \return retorno: (char) Retorna o caractere daquela posição no labirinto
         */
        char getPosicao(int x,int y); 



        /*!  \brief  Função: get_bolinhas
         *  Uso: x = get_bolinhas();
         *  
         * \return retorno: (int)  Retorna a quantidade de fantasmas no labirinto
         */
        int get_bolinhas(); 



        /*!  \brief  Função: get_fantasmas
         *  Uso: x = get_fantasmas();
         * Retorna a quantidade de fantasmas no labirinto 
         * \return retorno: (int)
         */        
        int get_fantasmas(); 


        /*!  \brief  Função: setPosicao
         *  Uso: setPosicao(x, y, c);
         *  \param x : (int) Essa função recebe um número referente a posição x (colunas do tabuleiro)
         *  \param y : (int) Essa função recebe um número referente a posição y (linhas do tabuleiro)  
         *  \param c : (char) Essa função recebe um caractere que será colocado naquela posição do tabuleiro 
         *  Nessa função é possível colocar um caractere e atualizar o mapa
         */               
        void setPosicao(int x, int y, char c);


        /*!  \brief  Função: getLinhas
         *  Uso: x = getLinhas();
         *  Nessa função é possível saber a quantidade de linhas do tabuleiro
         *  \return retorno: (int) retorna a quantidade de linhas do tabuleiro
         */                  
        int getLinhas();


        /*!  \brief  Função: getColunas
         *  Uso: x = getColunas();
         *  Nessa função é possível saber a quantidade de colunas do tabuleiro
         *  \return retorno: (int) Retorna a quantidade de colunas do tabuleiro
         *          
         */          
        int getColunas();

        /*!  \brief  Função: getMapa
         *  Uso: mapa = getMapa();
         *  Nessa função é possível receber o próprio labirinto
         *  \return retorno: (char**) retorna o tabuleiro
         */            
        char** getMapa();

};

#endif