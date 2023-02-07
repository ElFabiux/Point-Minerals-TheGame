#include "Player.h"

std::string Player::enterName() {
    std::cout << "Ingrese el nombre del jugador: ";
    std::string nombre;
    std::cin >> nombre;
    return nombre;
}

Player::Player(int x, int y) {
    this->playerName = enterName();
    this->points = 0;

    this->font.loadFromFile("arial.ttf");

    this->nameText.setFont(font);
    this->nameText.setString(playerName);
    this->nameText.setCharacterSize(17);
    this->nameText.setPosition(x + 0, y + 0);

    this->pointsText.setFont(font);
    this->pointsText.setString(std::to_string(points));
    this->pointsText.setCharacterSize(17);
    this->pointsText.setPosition(x + 83, y + 0);

    this->square.setSize(sf::Vector2f(120, 30));
    this->square.setPosition(x, y);
    this->square.setFillColor(sf::Color::White);
}

void Player::drawPlayer(sf::RenderWindow& window) {
    //ventana.draw(cuadro);
    window.draw(nameText);
    window.draw(pointsText);
}

void Player::increasePoints(int points) {
    this->points += points;
    this->pointsText.setString(std::to_string(this->points));
}
