#pragma once
#include "MainHeader.h"
#include "Visualizer.h"

class Game {
public:
    Game(const std::string& title);
    void run();

    int screenWidth;
    int screenHeight;
    sf::Vector2i m_screensize;
    Visualizer viz;
private:
    sf::RenderWindow mWindow;
    void processEvents();
    void render();
};


