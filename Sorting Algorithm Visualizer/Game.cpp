#include "Game.hpp"

Game::Game(const std::string& title)
    :   screenHeight(1000),
        screenWidth(1000),
        m_screensize(sf::Vector2i(screenWidth,screenHeight)),
        mWindow(sf::VideoMode(screenWidth,screenHeight), title),
        viz(m_screensize,screenWidth/6)
{
    viz.m_algorithm = "Bubble";

}

void Game::run() {
    while (mWindow.isOpen()) {
        processEvents();

        viz.update();

        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            mWindow.close();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
            }
        }

    }
}

void Game::render() {
    mWindow.clear();

    viz.draw(mWindow);

    //grid
    //for (int i = 0; i < viz.arraySize; i++) {
    //    sf::RectangleShape rect1(sf::Vector2f(1, m_screensize.y));
    //    sf::RectangleShape rect2(sf::Vector2f(m_screensize.x, 1));

    //    rect1.setFillColor(sf::Color::Red);
    //    rect2.setFillColor(sf::Color::Red);
    //    rect1.setPosition(sf::Vector2f((m_screensize.x / viz.arraySize)*i, 0));
    //    rect2.setPosition(sf::Vector2f(0, (m_screensize.y / viz.arraySize)*i));

    //    mWindow.draw(rect1);
    //    mWindow.draw(rect2);
    //}

    mWindow.display();
}
