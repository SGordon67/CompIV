// Scott Gordon

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <string>
#include "Body.hpp"
using namespace std;

// constructor definition
Body::Body(){
    this->fx = 0;
    this->fy = 0;
};

float Body::getx(){ return this->x; }
float Body::gety(){ return this->y; }
float Body::getdx(){ return this->dx; }
float Body::getdy(){ return this->dy; }
float Body::getMass(){ return this->mass; }
string Body::getText(){ return this->text; }

// calculate the force on the particle
void Body::calcForce(Body &c){
    float r = sqrt(pow(((this->x)-c.x), 2) + pow(((this->y)-c.y), 2));
    float force = Body::G*(this->mass)*(c.mass)/(pow(r, 2));

    if((this->x) > c.x){ this->fx -= (force*((this->x)-c.x)/r); }
    else if((this->x) == c.x){ this->fx += 0; }
    else this->fx += (force*(c.x-(this->x))/r);

    if((this->y) > c.y){ this->fy -= (force*((this->y)-c.y)/r); }
    else if((this->y) == c.y){ this->fy += 0; }
    else this->fy += (force*(c.y-(this->y))/r);
}

// give appropriate values
void Body::give(float scale, sf::Vector2f offset){
    this->scale = scale;

    this->dx = -(this->dx);
    this->dy = -(this->dy);

    this->offx = offset.x;
    this->offy = offset.y;
}

// step function
void Body::step(double time){
    this->ax = ((this->fx)/(this->mass));
    this->ay = ((this->fy)/(this->mass));

    this->dx += ((this->ax)*(time));
    this->dy += ((this->ay)*(time));

    this->x += ((this->dx)*(time));
    this->y += ((this->dy)*(time));
}

// function to apply the right textures right before the objects are drawn
void Body::beforeDraw(){
    this->sprite.setPosition(sf::Vector2f((((this->x)*(this->scale))+(this->offx)),((this->y)*(this-> scale)+(this->offy))));
    this->texture.loadFromFile(this->text);
    this->sprite.setTexture(this->texture);
}
void Body::afterDraw(){
    this->fx = 0;
    this->fy = 0;
}


// input directly to the object
istream & operator >> (istream &in, Body &b){
    string temp;
    in >> b.x >> b.y >> b.dx >> b.dy >> b.mass >> temp;
    b.text = "images/" + temp;
    return in;
}

// draw the sprite
void Body::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite);
}