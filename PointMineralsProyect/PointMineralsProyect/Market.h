#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
#include "Deck.h"

class Market {
private:
    sf::RenderWindow window;
    sf::Sprite background;
    sf::Texture backgroundTexture;
    Deck deck;

public:
    Market();
    void run();
private:
    void centerWindow();
};

