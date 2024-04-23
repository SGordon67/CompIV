// Scott Gordon

#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include "ED.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    sf::Clock clock;
    sf::Time t;

    string FVar;
    string TVar;
    cin >> FVar >> TVar;
    ED beep = ED(FVar, TVar);
    int eDistance = beep.OptDistance();
    string align = beep.Alignment();
    cout << "Edit distance = " << eDistance << endl;
    cout << align;

    t = clock.getElapsedTime();
    cout << "Execution time is " << t.asSeconds() << " seconds \n";
    cout << "Edit distance = " << eDistance << endl;
}