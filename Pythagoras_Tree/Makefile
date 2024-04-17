all: main.o PTree.o main2.o PTree2.o ps1 ps1-2


main.o : main.cpp PTree.cpp PTree.hpp
	g++ -Wall -c -I/opt/homebrew/Cellar/sfml/2.6.1/include/ main.cpp -L/opt/homebrew/Cellar/sfml/2.6.1/lib/
PTree.o : PTree.cpp PTree.hpp
	g++ -Wall -c -I/opt/homebrew/Cellar/sfml/2.6.1/include/ PTree.cpp -L/opt/homebrew/Cellar/sfml/2.6.1/lib/

main2.o : main2.cpp PTree2.cpp PTree2.hpp
	g++ -Wall -c -I/opt/homebrew/Cellar/sfml/2.6.1/include/ main2.cpp -L/opt/homebrew/Cellar/sfml/2.6.1/lib/
PTree2.o : PTree2.cpp PTree2.hpp
	g++ -Wall -c -I/opt/homebrew/Cellar/sfml/2.6.1/include/ PTree2.cpp -L/opt/homebrew/Cellar/sfml/2.6.1/lib/


ps1 : main.o PTree.o
	g++ main.o PTree.o -o ps1 -L/opt/homebrew/Cellar/sfml/2.6.1/lib/ -lsfml-graphics -lsfml-window -lsfml-system
 
ps1-2 : main2.o PTree2.o
	g++ main2.o PTree2.o -o ps1-2 -L/opt/homebrew/Cellar/sfml/2.6.1/lib/ -lsfml-graphics -lsfml-window -lsfml-system

clean:
	\rm *.o *~ ps1 ps1-2