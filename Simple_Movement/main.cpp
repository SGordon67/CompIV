//Scott Gordon

#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    int x = 210;
    int y = 210;
    sf::Texture texture;
    if (!texture.loadFromFile("sprite.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    //sf::Music music;
    //if (!music.openFromFile("Music.ogg"))
    // return EXIT_FAILURE;
    //music.play();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Up){
                    y-=10;
                }

                if(event.key.code == sf::Keyboard::Down){
                    y+=10;
                }

                if(event.key.code == sf::Keyboard::Left){
                    x-=10;
                }

                if(event.key.code == sf::Keyboard::Right){
                    x+=10;
                }

            }

        }

        window.clear();
        sprite.setPosition(x,y);
        window.draw(sprite);
        window.display();
    }

    return 0;
}