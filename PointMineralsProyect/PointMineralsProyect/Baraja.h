#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
#include "Card.h"

class Baraja {
private:
    Card* m_cartas; // puntero a Carta
    int m_numCartas; // n�mero de cartas en la baraja

public:
    // Constructor
    Baraja();
    ~Baraja(); // destructor para liberar memoria

    Card* getCartas() { return m_cartas; }
    int getNumCartas() { return m_numCartas; }
};

