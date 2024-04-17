// Scott Gordon

#ifndef PTREE_INCLUDE
#define PTREE_INCLUDE
#pragma once
#include <SFML/Graphics.hpp>

class PTree : public sf::Drawable
{
    private:
    int x;
    int y;
    float RX, RY, LX, LY;
    double length;
    sf::ConvexShape box;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    public:
    PTree(sf::Color color, bool left, double length, float x, float y, int angle, sf::RenderTarget& target);
    float getRX();
    float getRY();
    float getLX();
    float getLY();
};
#endif