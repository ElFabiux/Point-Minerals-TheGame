#include "Baraja.h"

Baraja::Baraja() : m_cartas(NULL), m_numCartas(0)
{
    m_cartas = new Carta[MAXCARTAS];
    if (!m_cartas) {
        std::cerr << "Error al asignar memoria para las cartas" << std::endl;
    }
    for (int i = 0; i < MAXCARTAS; i++) {
        Carta carta;
        carta.loadTexture(Carta::rutasTexturas[i]);
        m_cartas[i] = carta;
    }
    m_numCartas = MAXCARTAS;
}

Baraja::~Baraja() {
    delete[] m_cartas;
}