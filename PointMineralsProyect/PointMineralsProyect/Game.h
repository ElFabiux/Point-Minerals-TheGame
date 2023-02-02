#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Card.h"
#include "Button.h"
using namespace std;

class Game {
private:
    Card cards;

    //bool loadButtons(const std::string&, sf::Texture&);
    //void centerButton(sf::Sprite&, sf::RenderWindow&);
    void createLobby();
    void createMarket();
    void runLobbyWindow(sf::RenderWindow&, sf::Sprite&);
    void runMarketWindow(sf::RenderWindow&, sf::Sprite&);
public:
    Game();
};