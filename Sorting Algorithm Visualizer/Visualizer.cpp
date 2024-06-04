#include "Visualizer.h"

Visualizer::Visualizer(sf::Vector2i screensize, int arraysize)
	: m_screensize(screensize),
	arraySize(arraysize)
{

	sortingSpeed = 1;

	initArray();
	randomize();
	initBlocks();
}

void Visualizer::initBlocks() {
	m_blocklist.clear();
	m_blocklist.resize(arraySize);
	blocksize = sf::Vector2f((m_screensize.x / arraySize), (m_screensize.y / arraySize) * -1);
	for (int i = 0; i < m_rngarray.size(); i++) {
		int j = m_rngarray[i];
		Block block(j, i, blocksize);
		block.setpos(sf::Vector2f((i * block.blocksize.x), m_screensize.y));
		m_blocklist[i] = block;
	}

	/*for (Block block : m_blocklist) {
		std::cout << "Block: "  << block.number << " Placement: " << block.placement << "\n";
	}*/
}

void Visualizer::initArray()
{
	m_rngarray.clear();
	m_rngarray.resize(arraySize);
	for (int i = 0; i < arraySize; i++) {
		m_rngarray[i] = i + 1;
	}
}

void Visualizer::randomize()
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::shuffle(m_rngarray.begin(), m_rngarray.end(), eng);
}

void Visualizer::update()
{
	static bool sorted = false;
	static int outer = 0;
	static int inner = 0;
	

	if (m_algorithm == "Bubble") {
		bubblesort(outer,inner,sorted);
	}
}

void Visualizer::draw(sf::RenderWindow& window)
{
	for (Block block : m_blocklist) {
		block.draw(window);
	}
}


void Visualizer::bubblesort(int& outer, int& inner, bool& sorted)
{
	if (sorted) {
		std::cout << "sorted!";
		return;
	}
	static int size = m_blocklist.size();

	m_blocklist[inner].setactive();
	if (outer < size - 1) {
		if (inner < size - outer - 1) {
			if (m_blocklist[inner].number > m_blocklist[inner + 1].number) {
				std::swap(m_blocklist[inner], m_blocklist[inner + 1]);
				std::swap(m_blocklist[inner].placement, m_blocklist[inner + 1].placement);


				m_blocklist[inner].updatepos(m_screensize);
				m_blocklist[inner + 1].updatepos(m_screensize);
				inner++;
			}
			else if(inner < size - outer -1){
				inner++;
			}
		}
		else {
			inner = 0;
			outer++;
		}
		
	}
	else {
		sorted = true;
	}


}


