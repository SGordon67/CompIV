all: LFSR.o PhotoMagic.o PhotoMagic


LFSR.o : LFSR.cpp LFSR.hpp
	g++ -Wall -c -std=c++0x LFSR.cpp
PhotoMagic.o : PhotoMagic.cpp LFSR.hpp
	g++ -Wall -c -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -std=c++0x -lsfml-graphics -lsfml-window -lsfml-system PhotoMagic.cpp


PhotoMagic : LFSR.o PhotoMagic.o
	g++ LFSR.o PhotoMagic.o -o PhotoMagic -L/opt/homebrew/Cellar/sfml/2.6.1/lib/ -lsfml-graphics -lsfml-window -lsfml-system

clean:
	\rm *.o *~ PhotoMagic