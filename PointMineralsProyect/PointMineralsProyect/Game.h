#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
#include "Market.h"

class Game {

private:
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Texture playButtonTexture;
    sf::Sprite playButtonSprite;
    sf::Texture loadButtonTexture;
    sf::Sprite loadButtonSprite;
    Market market;

    bool loadButton(const std::string&, sf::Texture&);
    void centerButton(sf::Sprite&);
public:
    Game();
    void run();
};
