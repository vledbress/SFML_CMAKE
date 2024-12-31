#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Simple SFML Project");

    sf::Texture text;
    text.loadFromFile("res/img/nose.png");

    sf::Sprite spr;
    spr.setTexture(text);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(spr);
        window.display();
    }

    return 0;
}
