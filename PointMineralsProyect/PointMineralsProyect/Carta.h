#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#define MAXCARTAS 6

class Carta {
public:
    static const std::string rutasTexturas[MAXCARTAS];
private:
    sf::Sprite m_sprite;
    sf::Texture m_texture;

public:
    // Constructor
    Carta() {}

    // Método para cargar una textura para el sprite de la carta
    void loadTexture(const std::string& rutaTextura);

    // Método para obtener el sprite de la carta
    sf::Sprite& getSprite() { return m_sprite; }
};
