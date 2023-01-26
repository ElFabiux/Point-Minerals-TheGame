#include "Baraja.h"

Baraja::Baraja() : m_cartas(NULL), m_numCartas(0)
{
    m_cartas = new Card[MAXCARTAS];
    if (!m_cartas) {
        std::cerr << "Error al asignar memoria para las cartas" << std::endl;
    }
    for (int i = 0; i < MAXCARTAS; i++) {
        Card carta;
        carta.loadTexture(Card::rutasTexturas[i]);
        m_cartas[i] = carta;
    }
    m_numCartas = MAXCARTAS;
}

Baraja::~Baraja() {
    delete[] m_cartas;
}
