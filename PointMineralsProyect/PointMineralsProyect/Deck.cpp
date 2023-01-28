#include "Deck.h"

Deck::Deck() : cards(NULL), numCards(0)
{
    cards = new Card[MAXCARTAS];
    if (!cards) {
        std::cerr << "Error al asignar memoria para las cartas" << std::endl;
    }
    for (int i = 0; i < MAXCARTAS; i++) {
        Card carta;
        carta.loadTexture(Card::rutasTexturas[i]);

        cards[i] = carta;
    }
    numCards = MAXCARTAS;
}

Deck::~Deck() {
    delete[] cards;
}

Card* Deck::getCards() { return cards; }

int Deck::getNumCards() { return numCards; }