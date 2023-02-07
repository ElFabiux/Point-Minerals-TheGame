#include "Card.h"

Card::Card() {
    fillMineralCards();
}

LinkedList Card::getMineralCards() {
    return mineralCards;
}

void Card::fillMineralCards() {
    
    // Cargar las imágenes de las cartas en texturas
    sf::Texture cardTexture1, cardTexture2, cardTexture3;
    cardTexture1.loadFromFile("LogoGold.jpg");
    cardTexture2.loadFromFile("LogoDiamond.jpg");
    cardTexture3.loadFromFile("LogoRuby.jpg");

    // Crear sprites a partir de las texturas
    sf::Sprite card1(cardTexture1), card2(cardTexture2), card3(cardTexture3);

    // Agregar los sprites a la lista
    mineralCards.pushFront(&card1);
    mineralCards.pushFront(&card2);
    mineralCards.pushFront(&card3);
}

void Card::showMineralList(sf::RenderWindow& window) {
    float scaleFactor = 0.5f;
    /*
    // Calcular la posición x de cada carta
    float cardWidth = card1.getGlobalBounds().width * scaleFactor;
    float xPos = (window.getSize().x - cardWidth * 3) / 2;

    // Alinear las cartas horizontalmente
    for (auto node = mineralCards.first; node != nullptr; node = node->next)
    {
        node->card->setPosition(xPos, window.getSize().y / 2);
        xPos += cardWidth;
    }
    */

    // Dibujar las cartas en la ventana
    for (auto node = mineralCards.first; node != nullptr; node = node->next)
    {
        window.draw(*node->card);
    }
}