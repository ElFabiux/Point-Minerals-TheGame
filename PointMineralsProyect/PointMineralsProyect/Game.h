#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Card.h"
#include "Button.h"
using namespace std;
using namespace sf;

class Game {
private:
    Card cards;

    void createLobby();
    void CalcularPosiciones(LinkedList);
    void CambiarPosiciones(LinkedList);
    void crearGrupos(LinkedList);
    void LlenarMercado(sf::RenderWindow&);
    LinkedList reescalar(LinkedList);
    LinkedList Posiciones(sf::RenderWindow&, LinkedList, float);
    void actualizarJuego(LinkedList, sf::RenderWindow&);
    void movimientosAuto(LinkedList, string[], int monton);
    void Jugada(LinkedList, sf::Vector2i mousePos, int cartasU, int jugador, sf::RenderWindow&, int x, int y);
    float Width(sf::Sprite);
    float Height(sf::Sprite);
    void createMarket();
    void runLobbyWindow(sf::RenderWindow&, sf::Sprite&);
    void runMarketWindow(sf::RenderWindow&, sf::Sprite&);
public:
    Game();

};