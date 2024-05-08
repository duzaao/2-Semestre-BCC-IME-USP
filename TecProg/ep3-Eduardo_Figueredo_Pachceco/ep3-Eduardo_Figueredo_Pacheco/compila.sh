#!/bin/bash


#primeiro é criado um arquivo objeto da biblioteca estática por meio do comando abaixo
gcc -c -o propriedadesnumericas.o propriedadesnumericas.c

#Caso for possível  criar o '.o', a biblioteca libpropriedadesnumericas.a será criada e ja estará pronta para ser utilizada
if [ $? == 0 ]; then
    ar -rcv libpropriedadesnumericas.a propriedadesnumericas.o > /dev/null 
fi


#Em seguida é criado um arquivo objeto da biblioteca dinâmica por meio do comando abaixo
gcc -c -fPIC -o vetoraleatorio.o vetoraleatorio.c

#Caso for possível  criar o '.o', a biblioteca libvetoraleatorio.so será criada e ja estará pronta para ser utilizada
if [ $? == 0 ]; then
    gcc -o /tmp/libvetoraleatorio.so -shared vetoraleatorio.o 
fi

#utilizado para compilar o programa utilizando a versão diâmica da sua biblioteca
gcc -Wall -o testa testa.c libpropriedadesnumericas.a -L/tmp -lvetoraleatorio

#utilizado para informar ao SO onde está a biblioteca a ser importada dinamicamente durante a execução.
export LD_LIBRARY_PATH=/tmp
doxygen Doxyfile
./testa 
