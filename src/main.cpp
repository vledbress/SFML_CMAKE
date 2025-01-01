#include "../inc/Screen.h"
#include "../inc/Image.h"


int main() {
    
    Screen screen(consts::WIDTH, consts::HEIGHT);
    screen.setFps(consts::FPS);

    screen.regCallBack(sf::Event::Closed, [&](sf::Event e) {
        screen.window().close();
    });
    
    Image img(50, 50, 300, 300, "res/img/ilka.jpg");

    while (screen.isOpen()) {
        screen.processEvents();
        screen.window().clear(sf::Color::White);
        img.draw(screen);
        screen.window().display();
    }
    return 0;
}
