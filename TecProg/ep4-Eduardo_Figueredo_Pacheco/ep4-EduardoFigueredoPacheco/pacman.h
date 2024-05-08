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

class Pacman: public Personagem {
    private:
        
        int bolinhasPac;
    public:



   /*!  \brief  Constructor: Pacman
    *  Uso: usuario = Pacman(labirinto,x, y);
    *  \param labirinto : (Labirinto*) Essa função recebe como parâmetro um ponteiro para o labirinto 
    *  \param x : (int) Essa função recebe como parâmetro um inteiro referente a posição do Pacman no mapa
    *  \param y : (int) Essa função recebe como parâmetro um inteiro referente a posição do Pacman no mapa
    *  Nesse Constructor é possível receber a classe Pacman
    */      
    Pacman(Labirinto * labirinto,int y, int x); 


    /*!  \brief  Destructor: ~Pacman
    *  Uso: ~Pacman();
    *  Nessa função é possível destruir a classe Pacman
    */      
    ~Pacman();
        

    /*!  \brief  Função: ganhou
    *  Uso: x = ganhou();
    * \return retorno: Retorna (int) 1 caso o jogo tenha acabado pois o pacman pegou todos os pacdots e (int) 0 caso contrário
    */
    int ganhou(); 


    /*!  \brief  Função: somaBolinhas
    *  Uso: somaBolinhas( x, y);
    *  \param proximo_y : Essa função recebe como parâmetro a próxima posição y do pacman para, se houver pacdot lá, que ele seja adicionado.
    *  \param proximo_x : Essa função recebe como parâmetro a próxima posição x do pacman para, se houver pacdot lá, que ele seja adicionado.
    * Nessa função é possível contar a mais, cada vez que o pacman passa por um pacDot 
    */
    void somaBolinhas(int proximo_y, int proximo_x);



    /*!  \brief  Função: zeraBolinhas
    *  Uso: zeraBolinhas();
    * Nessa função é possível zerar a quantidade de bolinhas coletadas pelo Pacman, para que ,então o jogo possa começar 
    */
    void zeraBolinhas();



    /*!  \brief  Função: getBolinhas
    *  Uso: c = getBolinhas();
    * Nessa função é possível saber quantas bolinhas foram coletadas
    * \return retorno: Retorna (int) o número de bolinhas coletadas pelo usuário (Pacman)
    */
    int getBolinhas();

};

