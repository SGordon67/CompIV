// Scott Gordon

#include <SFML/Graphics.hpp>
#include <math.h>
#include "PTree.hpp"
#include <iostream>

//constructor
PTree::PTree(sf::Color color, bool left, double length, float x,
float y, int angle, sf::RenderTarget& target)
{
    // create the square
    box.setPointCount(4);
    box.setPoint(0, sf::Vector2f(0,0));
    box.setPoint(1, sf::Vector2f(length,0));
    box.setPoint(2, sf::Vector2f(length,length));
    box.setPoint(3, sf::Vector2f(0,length));
    box.setFillColor(color);

    // move the square and rotate based on right or left
    if(left){
        box.setOrigin(0,length);
        box.setPosition(sf::Vector2f(x,y));
        box.rotate(angle);
        RX = (box.getTransform().transformPoint(box.getPoint(1))).x;
        RY = (box.getTransform().transformPoint(box.getPoint(1))).y;
        LX = (box.getTransform().transformPoint(box.getPoint(0))).x;
        LY = (box.getTransform().transformPoint(box.getPoint(0))).y;
    }else{
        box.setOrigin(length,length);
        box.setPosition(sf::Vector2f(x,y));
        box.rotate(angle);
        RX = (box.getTransform().transformPoint(box.getPoint(1))).x;
        RY = (box.getTransform().transformPoint(box.getPoint(1))).y;
        LX = (box.getTransform().transformPoint(box.getPoint(0))).x;
        LY = (box.getTransform().transformPoint(box.getPoint(0))).y;
    }

    // draw the square
    target.draw(box);

}

// functions for retrieving the coordinates of the next squares
float PTree::getRX(){
    return(RX);
}
float PTree::getRY(){
    return(RY);
}
float PTree::getLX(){
    return(LX);
}
float PTree::getLY(){
    return(LY);
}


//method for drawing the object to the window
void PTree::draw(sf::RenderTarget& target, sf::RenderStates states)
const
{
    target.draw(box);
}