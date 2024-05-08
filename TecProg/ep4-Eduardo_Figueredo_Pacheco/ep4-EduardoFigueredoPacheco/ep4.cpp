#include <iostream>
#include <fstream>
#include <random>
#include "partida.h"


/* retirar depois */
 #include "pacman.h"


#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'


#ifdef TESTES

TEST(TESTES_LAB,linhasMaiorQueZero){
    char nome[256] = "input.txt";
    Partida* jogo = new Partida(nome);
    EXPECT_GT(jogo->getLab_partida()->getLinhas(),0);
}

TEST(TESTES_LAB,ColunasMaiorQueZero){
        char nome[256] = "input.txt";
    Partida* jogo = new Partida(nome);
    EXPECT_GT(jogo->getLab_partida()->getColunas(),0);
}

#endif



int main(/*int argc, char **argv*/){
    #ifdef TESTES
     ::testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
    #endif
        
        Partida* jogo = new Partida("input.txt");
        jogo->setAcabou(0);
    
    while(!jogo->getAcabou()) {
        
        jogo->imprimeMapa();
        jogo->sentido_Pacman();
        jogo->sentido_Fantasma();
        
    }
        if(jogo->getAcabou() == 1) {

        jogo->imprimeMapa();
        cout << " \n\n\n\n\n\n\n\n******************************************************\n\n\n\n"<<"Game over! Pontos = " << jogo->get_pacdots() <<"\n\n\n\n******************************************************\n\n\n\n\n\n\n\n" << endl;
        }

        if(jogo->getAcabou() == 2) {

        jogo->imprimeMapa();
        cout << " \n\n\n\n\n\n\n\n******************************************************\n\n\n\n"<<"Congratulations! Pontos =  " << jogo->get_pacdots() <<" \n\n\n\n******************************************************\n\n\n\n\n\n\n\n" << endl;
        }
        
        delete jogo;

    return 0;
}

