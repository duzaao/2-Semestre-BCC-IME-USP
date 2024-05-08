ALL: ep4.cpp arquivo.o labirinto.o pacman.o personagem.o partida.o fantasma.o
	g++ -Wall -o ep4 ep4.cpp arquivo.o labirinto.o pacman.o personagem.o partida.o fantasma.o

arquivo.o: arquivo.cpp arquivo.h
	g++ -Wall -c -o arquivo.o arquivo.cpp 

labirinto.o: labirinto.cpp labirinto.h
	g++ -Wall -c -o labirinto.o labirinto.cpp


personagem.o: personagem.cpp personagem.h
	g++ -Wall -c -o personagem.o personagem.cpp 

pacman.o: pacman.cpp pacman.h
	g++ -Wall -c -o pacman.o pacman.cpp 

partida.o: partida.cpp partida.h
	g++ -Wall -c -o partida.o partida.cpp 

fantasma.o: fantasma.cpp fantasma.h
	g++ -Wall -c -o fantasma.o fantasma.cpp 

tests: ep4.cpp arquivo.o labirinto.o pacman.o personagem.o partida.o fantasma.o
	  g++ -DTESTES -o ep4 ep4.cpp arquivo.o labirinto.o pacman.o personagem.o partida.o fantasma.o -lgtest -lpthread

doc: doxygen doxyfile