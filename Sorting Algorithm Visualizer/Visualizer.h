#pragma once
#include "MainHeader.h"
#include "Block.h"

class Visualizer
{
public:
	Visualizer(sf::Vector2i screensize, int arraysize);

	int arraySize;
	int sortingSpeed;
	std::string m_algorithm;

	void update();
	void draw(sf::RenderWindow& window);
	void randomize();
	void initBlocks();
	void initArray();
private:
	std::vector<int> m_rngarray;
	sf::Vector2f blocksize;
	std::vector<Block> m_blocklist;
	sf::Vector2i m_screensize;
	void bubblesort(int& outer, int& inner, bool& sorted);
};

