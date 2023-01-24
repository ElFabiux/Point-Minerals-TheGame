#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Carta.h"

class Baraja {
private:
    Carta* m_cartas; // puntero a Carta
    int m_numCartas; // número de cartas en la baraja

public:
    // Constructor
    Baraja();
    ~Baraja(); // destructor para liberar memoria

    Carta* getCartas() { return m_cartas; }
    int getNumCartas() { return m_numCartas; }
};

