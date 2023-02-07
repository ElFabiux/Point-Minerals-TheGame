#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Card.h"
#include "Button.h"
using namespace std;
using namespace sf;

class Game {
private:
    Card cards;

public:
    void calculatePositions(LinkedList);
    void changePositions(LinkedList);
    void createGroups(LinkedList);
    void fillMarket(sf::RenderWindow&);
    LinkedList rescale(LinkedList);
    LinkedList positions(sf::RenderWindow&, LinkedList, float);
    void updateGame(LinkedList, sf::RenderWindow&);
    void autoMovement(LinkedList, string[], int);
    void play(LinkedList, sf::Vector2i, int, int, sf::RenderWindow&, int x, int y);
    float width(sf::Sprite);
    float height(sf::Sprite);
    void createLobby();
    void createMarket();
    void runLobbyWindow(sf::RenderWindow&, sf::Sprite&);
    void runMarketWindow(sf::RenderWindow&, sf::Sprite&);
    Game();

};