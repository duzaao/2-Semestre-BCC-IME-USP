#include "arquivo.h"

arquivo::~arquivo(){
    free(getMapa());
}

arquivo::arquivo(char*nome){
    std::fstream arq;
    char **mapa;
    int linhas,colunas;
    int numero_bolinhas=0, numero_fantasmas=0;
    int i,l=0;

    mapa = (char**) malloc (256 * sizeof( char*) );
    for(int i =0 ; i < 256 ; i++ )
        mapa[i] = (char*) malloc( sizeof (char) * 256 );
    posFantasma = (int*) malloc (sizeof(int)*2*256);

    arq.open(nome,std::ios::in);
    if(!arq) cout << "Erro na tentativa de abrir o arquivo " << endl;



    for(linhas = 0; arq.getline(mapa[linhas],256);linhas++){
        for(colunas = 0; mapa[linhas][colunas] != '\0';colunas++){
            
            if(mapa[linhas][colunas] == '.') numero_bolinhas++;
            else if(mapa[linhas][colunas] == 'F') {
                posFantasma[l++] = colunas;
                posFantasma[l++] = linhas;  
                numero_fantasmas++;

            }

        }
    }

    F = new Fantasma*[numero_fantasmas];
    

    this->labirinto = new Labirinto(mapa,linhas,colunas,numero_bolinhas,numero_fantasmas);
   l=0;
    for(i=0;i<numero_fantasmas;i++){
        F[i] = new Fantasma(labirinto,posFantasma[l++],posFantasma[l++]);
        F[i]->setElemento('.');
    }


    
}   

Labirinto* arquivo::getMapa(){
    return this->labirinto;
}

Fantasma** arquivo::getFantasma(){
    return this->F;
}

