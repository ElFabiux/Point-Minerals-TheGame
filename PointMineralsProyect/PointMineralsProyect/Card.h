#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
#define MAXCARTAS 6

class Card {
public:
    static const std::string rutasTexturas[MAXCARTAS];
private:
    sf::Sprite sprite;
    sf::Texture texture;

public:
    // Constructor
    Card() {}

    // Método para cargar una textura para el sprite de la carta
    void loadTexture(const std::string& rutaTextura);

    // Método para obtener el sprite de la carta
    sf::Sprite& getSprite();
};
