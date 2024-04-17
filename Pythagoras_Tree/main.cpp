// Scott Gordon

#include <SFML/Graphics.hpp>
#include "PTree.hpp"
#include <math.h>
#include <iostream>
using namespace std;

void pTree(sf::Color color, bool left, int depth, double length,float x, float y, int angle, sf::RenderTarget& target);
int main()
{
    cout << "N is the number representing how many levels the recursion should process." << endl;
    cout << "L represents the size of the initial block." << endl;
    cout << "Recommended values are N = 10, and L = 150." << endl << endl;
    int depth;
    double length;
    cout << "Enter the value for N: ";
    cin >> depth;
    cout << "Enter the value for L: ";
    cin >> length;
    double width = (6*length);
    double height = (4*length);
    float X = ((width/2)-(length/2));
    float Y = height;

    sf::Color color;
    color.r = 255;
    color.g = 0;
    color.b = 0;
    color.a = (255/2);
    cout << endl;
    sf::RenderWindow window(sf::VideoMode(width, height), "Tree");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)window.close();
        }
        window.clear();
        pTree(color, true, depth, length, X, Y, 0, window);
        window.display();
    }
    return 0;
}
void pTree(sf::Color color, bool left, int depth, double length, float x, float y, int angle, sf::RenderTarget& target){
    if(depth<0){ return; }

    PTree part = PTree(color, left, length, x, y, angle, target);

    float RX = part.getRX();
    float RY = part.getRY();
    float LX = part.getLX();
    float LY = part.getLY();

    color.r += 100;
    color.g += 50;
    color.b += 20;

    pTree(color, false, (depth-1), (length/(sqrt(2))), RX, RY, angle+45, target);
    pTree(color, true, (depth-1), (length/(sqrt(2))), LX, LY, angle-45, target);

    return;
}