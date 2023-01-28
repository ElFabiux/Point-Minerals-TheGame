#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
#include "Market.h"

class Game {
private:
    Market market;

    bool loadButton(const std::string&, sf::Texture&);
    void centerButton(sf::Sprite&, sf::RenderWindow&);
    void createLobby();
    void runWindow(sf::RenderWindow&, sf::Sprite&, sf::Sprite&,
                   sf::Sprite&);
public:
    Game();
};
