#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "LinkedList.h"

class Card
{
private:
	LinkedList mineralCards;
public:
	Card();
	LinkedList getMineralCards();
	void fillMineralCards();
	void showMineralList(sf::RenderWindow&);
};

