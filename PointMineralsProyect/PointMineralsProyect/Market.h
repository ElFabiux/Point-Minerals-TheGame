#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
#include "Baraja.h"

class Market {
private:
    sf::RenderWindow window;
    sf::Sprite background;
    sf::Texture backgroundTexture;
    Baraja baraja;

public:
    Market();
    void run();
private:
    void centerWindow();
};

