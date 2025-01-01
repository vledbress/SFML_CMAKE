#include "../inc/Image.h"


void Image::reScale(const sf::Vector2f& vec){
    sf::Vector2u textureSize = _texture.getSize();
    float scaleX = vec.x / (float)textureSize.x;
    float scaleY = vec.y / (float)textureSize.y;
    _sprite.setScale(scaleX, scaleY);
}
 
 

Image::Image(int x, int y, int width, int height, const std::string& path)  {
    _texture.loadFromFile(path);
    _sprite.setTexture(_texture);
    _sprite.setPosition(x, y);
    reScale({(float)width, (float)height});
}

void Image::draw(Screen& screen) {
    screen.window().draw(_sprite);
}

