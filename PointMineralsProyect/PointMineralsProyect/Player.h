#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Jugador {
public:
    Jugador(int x, int y);
    void Dibujar(sf::RenderWindow& ventana);
    void AumentarPuntos(int puntos);

private:
    std::string PedirNombre() {
        std::cout << "Ingrese el nombre del jugador: ";
        std::string nombre;
        std::cin >> nombre;
        return nombre;
    }
    std::string nombre;
    int puntos;
    sf::Font fuente;
    sf::RectangleShape cuadro;
    sf::Text texto_nombre;
    sf::Text texto_puntos;
};
