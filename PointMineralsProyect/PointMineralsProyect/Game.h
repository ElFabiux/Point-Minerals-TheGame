#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Game {
private:
    bool loadButtons(const std::string&, sf::Texture&);
    void centerButton(sf::Sprite&, sf::RenderWindow&);
    void createLobby();
    void createMarket();
    void runLobbyWindow(sf::RenderWindow&, sf::Sprite&, sf::Sprite&, sf::Sprite&);
    void runMarketWindow(sf::RenderWindow&, sf::Sprite&);
public:
    Game();
};