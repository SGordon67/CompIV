// Scott Gordon

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "LFSR.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    // variables for input
    string startImage = argv[1];
    string outImage = argv[2];
    string seed = argv[3];
    int tap = stoi(argv[4]);

    /*
    // collect input
    cout << "Enter a file name for input: " << endl;
    cin >> startImage;
    cout << "Enter a file name for output: " << endl;
    cin >> outImage;
    cout << "Enter a seed (1's and 0's): " << endl;
    cin >> seed;
    cout << "Enter a tap position: " << endl;
    cin >> tap;
    */

    // create the image, and a sprite of it
    sf::Image image;
    if (!image.loadFromFile(startImage)) return -1;
    sf::Texture texture1;
    texture1.loadFromImage(image);
    sf::Sprite sprite1;
    sprite1.setTexture(texture1);

    // Create the window for the first image
    sf::Vector2u size = image.getSize();
    sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Meow");


    // create LFSR to use in scrambling
    LFSR bloop = LFSR(seed, tap);
    int use = 0;

    // scramble the image
    sf::Color p;
    for (unsigned int i = 0; i < size.x; i++) {
        for (unsigned int j = 0; j < size.y; j++) {
            use = bloop.generate(16);
            p = image.getPixel(i, j);
            p.r = use ^ p.r;
            p.g = use ^ p.g;
            p.b = use ^ p.b;
            image.setPixel(i, j, p);
        }
    }

    // save new image to files
    image.saveToFile(outImage);

    // make a sprite out of the scrambled image
    sf::Texture texture2;
    texture2.loadFromImage(image);
    sf::Sprite sprite2;
    sprite2.setTexture(texture2);

    // create the window for the second image
    sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Meow");

    // Opening the windows and displaying the sprites.
    while (window1.isOpen() && window2.isOpen()) {
        sf::Event event;
        while (window1.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window1.close();
        }
        while (window2.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window2.close();
        }
        window1.clear();
        window1.draw(sprite1);
        window1.display();
        window2.clear();
        window2.draw(sprite2);
        window2.display();
    }

    return 0;
}