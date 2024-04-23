// Scott Gordon

#ifndef Body_INCLUDE
#define Body_INCLUDE
#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Body : public sf::Drawable
{
    private:

    //variables for each planets information
    float x, y, dx, dy, mass;
    float fx,fy;
    float ax, ay;
    float scale;
    float offx, offy;
    sf::Sprite sprite;
    sf::Texture texture;
    string text;

    // draw function
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    public:
    double static constexpr G = 6.67e-11;
    void give(float scale, sf::Vector2f offset);
    void step(double time);
    void calcForce(Body &c);
    void beforeDraw();
    void afterDraw();

    float getx();
    float gety();
    float getdx();
    float getdy();
    float getMass();
    string getText();

    // constructor and overloaded istream operator
    Body();
    friend istream & operator >> (istream &in, Body &b);
};
#endif