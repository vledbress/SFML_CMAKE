#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Screen.h"


class Image {
private:
    sf::Sprite _sprite;
    sf::Texture _texture;

    void reScale(const sf::Vector2f& vec);
public:
    Image(int x, int y, int width, int height, const std::string& path);

    void draw(Screen& screen);
};