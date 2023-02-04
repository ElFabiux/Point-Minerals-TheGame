#include <SFML/Graphics.hpp>
#include <string>

class Jugador {
public:
    Jugador(std::string nombre, int x, int y);
    void Dibujar(sf::RenderWindow& ventana);
    void AumentarPuntos(int puntos);

private:
    std::string nombre;
    int puntos;
    sf::Font fuente;
    sf::RectangleShape cuadro;
    sf::Text texto_nombre;
    sf::Text texto_puntos;
};
