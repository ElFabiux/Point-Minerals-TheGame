#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
#include "Card.h"

class Deck {
private:
    Card* cards; // puntero a Carta
    int numCards; // número de cartas en la baraja

public:
    // Constructor
    Deck();
    ~Deck(); // destructor para liberar memoria

    Card* getCards();
    int getNumCards();
};

