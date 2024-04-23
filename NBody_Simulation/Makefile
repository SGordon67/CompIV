all: main.o Body.o NBody

main.o : main.cpp Body.hpp
	g++ -Wall -c -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -std=c++0x main.cpp
Body.o : Body.cpp Body.hpp
	g++ -Wall -c -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -std=c++0x Body.cpp

NBody : main.o Body.o
	g++ main.o Body.o -o NBody -L/opt/homebrew/Cellar/sfml/2.6.1/lib/ -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

clean:
	\rm *.o *~ NBody output.txt