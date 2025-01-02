#include "../inc/Text.h"

FText::FText(int x, int y, unsigned int chsize, const std::string& path, const std::string& msg) : _font(), _text()
{
	_font.loadFromFile(path);
    _text.setFont(_font);
    _text.setString(msg);
    _text.setCharacterSize(chsize);
    _text.setFillColor(sf::Color::Black);
    _text.setPosition(x, y);
}

void FText::draw(Screen& screen)
{
    screen.window().draw(_text);
}
