#include "partida.h"

    Partida::Partida(char nome[256]){


    arq = new arquivo((char*)nome);
    
    usuario = new Pacman(arq->getMapa(),arq->getMapa()->getLinhas()/2 , arq->getMapa()->getColunas()/2);
    usuario->zeraBolinhas();
    arq->getMapa()->setPosicao(arq->getMapa()->getLinhas()/2 , arq->getMapa()->getColunas()/2,'C');
    printf("getlinhas = %d\n",arq->getMapa()->getLinhas());
    printf("getcolunas = %d\n",arq->getMapa()->getColunas());

    labirinto = arq->getMapa();
    F = arq->getFantasma();


    }


    Partida::~Partida(){
        delete this->usuario;
        delete this->F;
        delete this->arq;
    }
    void Partida::sentido_Fantasma(){
        for(int i=0;i< labirinto->get_fantasmas(); i++ ){
            F[i]->moveAleatorio();
            if(F[i]->getElemento()=='C') setAcabou(1);
        }
    }

    void Partida::sentido_Pacman(){
        int proximo_x, proximo_y;
        char direcao;
        proximo_x = usuario->getX();
        proximo_y = usuario->getY();
        printf("x = %d   y= %d\n",proximo_x,proximo_y);
        cin >> direcao;

            if (direcao == ESQUERDA){
                
                    proximo_x--;  
            }
            else if (direcao == CIMA){
                
                    proximo_y--;
            }
            else if (direcao == BAIXO){
                
                    proximo_y++;
            }
            else if (direcao == DIREITA){
                
                    proximo_x++;
            }


        usuario->somaBolinhas(proximo_y, proximo_x);
        if(usuario->ganhou()) setAcabou(2);
        usuario->move_pers(direcao);
    }

    void Partida::imprimeMapa(){

        for(int i=0;i< labirinto->getLinhas() ;i++){
            for(int j=0;j< labirinto->getColunas();j++)
                cout << labirinto->getMapa()[i][j] << ' ';
            cout << endl;
            
        }
    }


    
    void Partida::setAcabou(int x){
        this->acabou = x;
    }
    int Partida::getAcabou(){ // Utilizado para verificar quando o usuário vence o jogo 
        return this->acabou;
    }
    //Pacman usuario = new Pacman(mapa->getMapa()->getLinhas,mapa->getMapa()->getColunas);


    int Partida::get_pacdots(){
        return usuario->getBolinhas();
    }

    Labirinto* Partida::getLab_partida(){
        return this->labirinto;
    }
    Pacman* Partida::getPacman_partida(){
        return this->usuario;  
    }
    Fantasma** Partida::getFantasma_partida(){
        return this->F;  
    }