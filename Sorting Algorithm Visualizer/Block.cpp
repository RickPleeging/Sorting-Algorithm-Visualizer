#include "Block.h"

Block::Block() { number = 0; }

Block::Block(int number, int placement, sf::Vector2f blocksize)
	: number(number),
	blocksize(blocksize),
	placement(placement)
{
	active = false;
	correct = false;
	sorted = false;

	rect.setSize(sf::Vector2f(blocksize.x, blocksize.y * number));
	rect.setFillColor(sf::Color::White);

}

void Block::draw(sf::RenderWindow& window)
{
	window.draw(rect);
}

void Block::setpos(sf::Vector2f position)
{
	rect.setPosition(position);
}

void Block::updatepos(sf::Vector2i screensize)
{
	rect.setPosition(sf::Vector2f((placement * blocksize.x), screensize.y));
}

void Block::setactive()
{
	rect.setFillColor(sf::Color::Cyan);
}

void Block::setinactive()
{
	rect.setFillColor(sf::Color::White);
}
void Block::setcorrect() {
	rect.setFillColor(sf::Color::Yellow);
}

void Block::setsorted()
{
	rect.setFillColor(sf::Color::Green);
}
