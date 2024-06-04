#pragma once
#include "MainHeader.h"

class Block
{
public:
	Block();
	Block(int number, int placement, sf::Vector2f blocksize);
	int number;
	int placement;
	bool active;
	bool correct;
	bool sorted;

	sf::Vector2f blocksize;
	void draw(sf::RenderWindow& window);
	void setpos(sf::Vector2f position);
	void updatepos(sf::Vector2i screensize);
	void setactive();
	void setinactive();
	void setsorted();
	void setcorrect();
private:
	sf::RectangleShape rect;
};

