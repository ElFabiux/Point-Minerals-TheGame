#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;


class Market {
private:
    sf::RenderWindow window;
    sf::Sprite background;
    sf::Texture backgroundTexture;
    

public:
    Market();
    void run();
private:
    void centerWindow();
};

