#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Player {
public:
    Player(int x, int y);
    void drawPlayer(sf::RenderWindow&);
    void increasePoints(int);

private:
    std::string enterName();
    std::string playerName;
    int points;
    sf::Font font;
    sf::RectangleShape square;
    sf::Text nameText;
    sf::Text pointsText;
};
