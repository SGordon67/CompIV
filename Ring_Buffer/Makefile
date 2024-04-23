all: test.o RingBuffer.o RB

test.o : test.cpp RingBuffer.hpp
	g++ -Wall -c -std=c++0x -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -I/opt/homebrew/Cellar/boost/1.84.0_1/include/ -lboost_unit_test_framework test.cpp
RingBuffer.o : RingBuffer.cpp RingBuffer.hpp
	g++ -Wall -c -std=c++0x -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -I/opt/homebrew/Cellar/boost/1.84.0_1/include/ -lboost_unit_test_framework RingBuffer.cpp

RB : test.o RingBuffer.o
	g++ test.o RingBuffer.o -o RB -L/opt/homebrew/Cellar/sfml/2.6.1/lib/ -L/opt/homebrew/Cellar/boost/1.84.0_1/lib/ -lsfml-system -lboost_unit_test_framework

clean:
	\rm *.o *~ RB