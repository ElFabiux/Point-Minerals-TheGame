#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Baraja.h"

class Market {
private:
    sf::RenderWindow m_window;
    sf::Sprite m_background;
    sf::Texture m_backgroundTexture;
    Baraja m_baraja;

public:
    Market();
    void run();
private:
    void centerWindow();
};
