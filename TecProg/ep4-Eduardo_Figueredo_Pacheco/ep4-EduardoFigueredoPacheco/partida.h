#pragma once
#include <iostream>
#include <fstream>
#include <random>
#include "personagem.h"
#include "labirinto.h"
#include "pacman.h"
#include "fantasma.h"
#include "arquivo.h"

class Partida {
    protected:

        Labirinto* labirinto;
        Pacman* usuario;
        Fantasma** F;
        arquivo *arq;
        int acabou;
        

    public:


   /*!  \brief  Constructor: Partida
    *  Uso: usuario = Partida();
    *  Nesse Constructor é possível receber a classe Partida
    */      
    Partida(char *nome);

    ~Partida();


   /*!  \brief  Função: getAcabou
    *  Uso: c = getAcabou();
    * Nessa função é possível receber o resultado da variavel "acabou"
    * \return retorno: Retorna (int) o resultado da variavel "acabou" e é utilizado como argumento de parada do loop principal
    */
    int getAcabou();


   /*!  \brief  Função: setAcabou
    *  Uso: c = setAcabou(x);
    *  \param x : (int) Essa função recebe um numero que indica se o jogo acabou ou não; (int) 1 para se o jogo acabou porque o fantasma achou o Pacman, (int) 2 se o Pacman colheu todas as bolinhas, e (int) 0 caso o jogo não tenha acabado
    * Nessa função é possível mudar a posição da variavel "acabou" que é usada como variável de parada do loop principal do jogo 
    */
    void setAcabou(int x);



   /*!  \brief  Função:  sentido_Pacman
    *  Uso: entido_Pacman();
    *  Nessa função é utilizada para de fato garantir que o fantasma se mova e que se contem os pacdots caso ele passe por um 
    */
    void sentido_Pacman();



   /*!  \brief  Função: imprimeMapa
    *  Uso: imprimeMapa();
    * Nessa função é possível imprimir o mapa 
    */
    void imprimeMapa();



   /*!  \brief  Função: sentido_Fantasma
    *  Uso: sentido_Fantasma();
    *  Essa função garante o movimento dos fantasmas 
    */
    void sentido_Fantasma();


    int get_pacdots();

    Labirinto* getLab_partida();
    Pacman* getPacman_partida();
    Fantasma** getFantasma_partida();

};


