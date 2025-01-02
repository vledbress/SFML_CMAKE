#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Screen.h"
#include "Text.h"


class Button {
private:
    sf::RectangleShape _body;
    sf::RectangleShape _face;
    //int offset = 1;
    FText _text;
//int x, int y, unsigned int chsize, const std::string& path, const std::string& msg);
public:
    Button(int x, int y, int w, int h, const std::string& text = "Click me!", 
    const std::string& font = "res/ttf/Font.ttf")
     : _body({(float)w, (float)h}), 
       _face({(float)(w -  2), (float)(h -  2)}), 
       _text(x, y, 20, font, text) 
    {

        _body.setOrigin({(float)w/2.f, (float)h/2.f});
        _body.setPosition({(float)x, (float)y});
        _body.setFillColor(sf::Color::Black);

        _face.setOrigin({((float)w - 2)/2.f, ((float)h - 2)/2.f});
        _face.setPosition({(float)x, (float)y});

        

        sf::FloatRect bounds = _text.text().getLocalBounds();
        float width = bounds.width;   // Ширина текста в пикселях
        float height = bounds.height; // Высота текста в пикселях

        _text.text().setOrigin({width/2.f, height/2.f});
        _text.text().setPosition({(float)x, (float)y});

    }

    void draw(Screen& screen){
        screen.window().draw(_body);
        screen.window().draw(_face);
        _text.draw(screen);
    }

    void setColorFace(const sf::Color& color) {
        _face.setFillColor(color);
    }
};