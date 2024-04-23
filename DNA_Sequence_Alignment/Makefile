all: main.o ED.o ED

main.o : main.cpp ED.hpp
	g++ -Wall -c -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -std=c++0x main.cpp
ED.o : ED.cpp ED.hpp
	g++ -Wall -c -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -std=c++0x ED.cpp

ED : main.o ED.o
	g++ main.o ED.o -O1 -o ED -L/opt/homebrew/Cellar/sfml/2.6.1/lib/ -lsfml-system

clean:
	\rm massif.out.* *.o *~ ED