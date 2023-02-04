#include "Player.h"

Jugador::Jugador(std::string nombre, int x, int y) {
    this->nombre = nombre;
    this->puntos = 0;

    this->fuente.loadFromFile("arial.ttf");

    this->texto_nombre.setFont(fuente);
    this->texto_nombre.setString(nombre);
    this->texto_nombre.setCharacterSize(14);
    this->texto_nombre.setPosition(x + 10, y + 10);

    this->texto_puntos.setFont(fuente);
    this->texto_puntos.setString(std::to_string(puntos));
    this->texto_puntos.setCharacterSize(14);
    this->texto_puntos.setPosition(x + 80, y + 10);

    this->cuadro.setSize(sf::Vector2f(110, 20));
    this->cuadro.setPosition(x, y);
    this->cuadro.setFillColor(sf::Color::White);
}

void Jugador::Dibujar(sf::RenderWindow& ventana) {
    //ventana.draw(cuadro);
    ventana.draw(texto_nombre);
    ventana.draw(texto_puntos);
}

void Jugador::AumentarPuntos(int puntos) {
    this->puntos += puntos;
    this->texto_puntos.setString(std::to_string(this->puntos));
}
