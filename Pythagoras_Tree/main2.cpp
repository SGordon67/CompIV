// Scott Gordon

#include <SFML/Graphics.hpp>
#include "PTree.hpp"
#include <math.h>
#include <iostream>
using namespace std;

void pTree(sf::Color color, bool left, int depth, double length,float x, float y, double angle, sf::RenderTarget& target);
int main()
{
    // variables for the square
    int depth;
    double length;
    double angle = 0;

    // collect input
    cout << "Enter the value for N: ";
    cin >> depth;
    cout << "Enter the value for L: ";
    cin >> length;

    // set appropriate variables
    double width = (6*length);
    double height = (4*length);
    float X = ((width/2)-(length));
    float Y = height;
    sf::Color color;
    color.r = 255;
    color.g = 0;
    color.b = 0;
    color.a = (255/2);
    cout << endl;

    // create window for program
    sf::RenderWindow window(sf::VideoMode(width, height), "Tree");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear();
        // call the recursive function (will draw the tree)
        pTree(color, true, depth, length, X, Y, angle, window);
        window.display();
    }
    return 0;
}
// recursive function
// takes color, depth, length, x and y coordinates, angle of rotation, and window
// the bool is to tell wether it belongs to the left or right side of the tree
void pTree(sf::Color color, bool left, int depth, double length,float x, float y, double angle, sf::RenderTarget& target){
// if depth passes 0, stop recurring
if(depth<0){ return; }

// create the part of the tree based on parameters
PTree part = PTree(color, left, length, x, y, angle, target);

// get the values for where the next blocks will be placed
float RX = part.getRX();
float RY = part.getRY();
float LX = part.getLX();
float LY = part.getLY();

// change color
color.r += 100;
color.g += 50;
color.b += 20;

// recur the left then the right sides of the tree
pTree(color, true, (depth-1), (length*(sin(.523599))), LX, LY, angle-60, target);

pTree(color, false, (depth-1), (length*(sin(1.0472))), RX, RY, angle+30, target);

return;
}