// Scott Gordon

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "Body.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    // setup the music and play
    sf::Music music;
    if (!music.openFromFile("data/song.ogg")) return -1;
    music.play();

    // setup all the font information
    sf::Font font;
    if (!font.loadFromFile("data/font.ttf")){return -1;}
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    //text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    double time = stod(argv[1]);
    double dtime = stod(argv[2]);

    // variable definitions
    float numBody, URadius;
    cin >> numBody >> URadius;
    vector<unique_ptr<Body>> vec;

    // load the background image and get the dimentions
    sf::Texture texture;
    if (!texture.loadFromFile("images/starfield.jpg")) return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    int tempW = sprite.getTexture()->getSize().x * sprite.getScale().x;
    int tempH = sprite.getTexture()->getSize().y * sprite.getScale().y;

    // get the scale and offset of the universe
    float scale = (((sprite.getTexture()->getSize().x)/2) * (sprite.getScale().x/URadius));
    sf::Vector2f offset = sf::Vector2f(tempW/2, tempH/2);
    // create the bodies in a loop, scaling them and putting them into a vector
    for( int i = 0; i < numBody; i++){
        vec.push_back(unique_ptr<Body>(new Body()));
        cin >> *vec[i];
        (*vec[i]).give(scale, offset);
    }

    // create the window and necessary variables
    sf::RenderWindow window(sf::VideoMode(tempW, tempH), "Planets");
    int t = 0;
    string outputText = " ";

    // open the window and create display loop
    while (t <= time && window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
            window.close();
        }
        // display the background image
        window.draw(sprite);

        // calculate forces on the planets
        for( int i = 0; i < numBody; i++){
            for( int j = 0; j < numBody; j++){
                if(i != j){
                    (*vec[i]).calcForce(*vec[j]);
                }
            }
        }
        // move the planets
        for( int i = 0; i < numBody; i++){
            (*vec[i]).step(dtime);
        }
        // ready the body with the right textures and then draw
        for( int i = 0; i < numBody; i++){
            (*vec[i]).beforeDraw();
            window.draw(*vec[i]);
            (*vec[i]).afterDraw();
        }
        // display the time, display window, increment time by given value
        text.setString("time: " + to_string(t));
        window.draw(text);
        window.display();
        t += dtime;
    }

    // outputting to file (not necessary but it's cool to continue universe
    ofstream file;
    file.open("output.txt");
    file << numBody << endl;
    file << URadius << endl;
    for( int i = 0; i < numBody; i++){
        file << "" << (*vec[i]).getx() << " " << (*vec[i]).gety() << " " << (*vec[i]).getdx() << " " << (*vec[i]).getdy() << " " << (*vec[i]).getMass() << " ";
        for(unsigned int j = 6; j < (*vec[i]).getText().length(); j++){
            file << ((*vec[i]).getText()[j]);
        }
        file << endl;
    }
    file.close();

    // printing output: literally the same as code above but for std output instead of file
    cout << numBody << endl;
    cout << URadius << endl;
    for( int i = 0; i < numBody; i++){
        cout << "" << (*vec[i]).getx() << " " << (*vec[i]).gety() << " " << (*vec[i]).getdx() << " " << (*vec[i]).getdy() << " " << (*vec[i]).getMass() << " ";
        for(unsigned int j = 6; j < (*vec[i]).getText().length(); j++){
            cout << ((*vec[i]).getText()[j]);
        }
        cout << endl;
    }
}