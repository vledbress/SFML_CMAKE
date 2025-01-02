#include "../inc/Screen.h"
#include "../inc/Image.h"
#include "../inc/Text.h"
#include "../inc/Button.h"
#include <iostream>


int main() {
    
    Screen screen(consts::WIDTH, consts::HEIGHT);
    screen.setFps(consts::FPS);

    screen.regCallBack(sf::Event::Closed, [&](sf::Event e) {
        screen.window().close();
    });

    screen.regCallBack(sf::Event::KeyPressed, [&](sf::Event e) {
        std::cout << e.key.code<< std::endl;
    });

    screen.regCallBack(sf::Event::KeyPressed, [&](sf::Event e) {
        if(e.key.code == sf::Keyboard::Escape) {
            screen.window().close();
        }
    });
    
    Image img(50, 50, 300, 300, "res/img/ilka.jpg");

    Button btn(300,300, 200, 50, "Giga peniszxsssss");
    btn.setColorFace(sf::Color::Yellow);

    while (screen.isOpen()) {
        screen.processEvents();
        screen.window().clear(sf::Color::White);
        img.draw(screen);
        btn.draw(screen);
        screen.window().display();
    }
    return 0;
}
