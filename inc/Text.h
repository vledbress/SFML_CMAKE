#pragma once
#include "Screen.h"




class FText {
private:
	sf::Font _font;
	sf::Text _text;
public:
	FText(int x, int y, unsigned int chsize, const std::string& path, const std::string& msg);

	void draw(Screen& screen);

	sf::Text& text(){return _text;}
};


