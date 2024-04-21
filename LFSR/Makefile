all: LFSR.o test.o ps2a

LFSR.o : LFSR.cpp LFSR.h
	g++ -Wall -c -std=c++0x -I/opt/homebrew/Cellar/boost/1.84.0_1/include/ LFSR.cpp
test.o : test.cpp LFSR.h
	g++ -Wall -c -std=c++0x -I/opt/homebrew/Cellar/boost/1.84.0_1/include/ -lboost_unit_test_framework test.cpp

ps2a : LFSR.o test.o
	g++ LFSR.o test.o -o ps1 -L/opt/homebrew/Cellar/boost/1.84.0_1/lib/ -lboost_unit_test_framework

clean:
	\rm *.o *~ ps2a