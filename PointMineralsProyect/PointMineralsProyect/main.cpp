#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
#include "Game.h"
#include "Market.h"
#include "Card.h"
#include "Baraja.h"

/*class Carta {
private:
    static const std::string rutasTexturas[MAXCARTAS] = {
    "ResourseFiles/Diamond/LogoDiamond.jpg",
    "ResourseFiles/Ruby/LogoRuby.jpg",
    "ResourseFiles/Fluorite/LogoFluorite.jpg",
    "ResourseFiles/Emerald/LogoEmerald.jpg",
    "ResourseFiles/Gold/LogoGold.jpg",
    "ResourseFiles/Iron/LogoIron.jpg"
    };
    sf::Sprite m_sprite;
    sf::Texture m_texture;

public:
    // Constructor
    Carta() {}

    // Método para cargar una textura para el sprite de la carta
    bool loadTexture(const std::string& rutaTextura) {
        if (!m_texture.loadFromFile(rutaTextura)) {
            return false;
        }
        m_texture.setSmooth(true);
        m_texture.setRepeated(false);
        m_sprite.setTexture(m_texture);
        return true;
    }

    // Método para obtener el sprite de la carta
    sf::Sprite& getSprite() { return m_sprite; }
};*/

/*class Baraja {
private:
    std::vector<Carta> m_cartas;

public:
    // Constructor
    Baraja() {
        for (int i = 0; i < MAXCARTAS; i++) {
            Carta carta;
            if (!carta.loadTexture(Carta::rutasTexturas[i])) {
                std::cout << "Error al cargar la textura" << std::endl;
            }
            m_cartas.push_back(carta);
        }
    }

    std::vector<Carta>& getCartas() { return m_cartas; }
};

class Market {
private:
    sf::RenderWindow m_window;
    sf::Sprite m_background;
    Baraja m_baraja;

public:
    Market() : m_window(sf::VideoMode::getDesktopMode(), "Market") {
        if (!m_background.loadFromFile("ResourseFiles/WallPapers/Table.jpg")) {
            std::cout << "Error loading image file" << std::endl;
        }
        centerWindow();
    }

    void run() {
        while (m_window.isOpen()) {
            sf::Event event;
            while (m_window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    m_window.close();
            }

            m_window.clear();

            m_window.draw(m_background);

            for (auto& carta : m_baraja.getCartas()) {
                m_window.draw(carta.getSprite());
            }

            m_window.display();
        }
    }

private:
    void centerWindow() {
        float windowPosX = (sf::VideoMode::getDesktopMode().width - m_window.getSize().x) / 2;
        float windowPosY = (sf::VideoMode::getDesktopMode().height - m_window.getSize().y) / 2;
        m_window.setPosition(sf::Vector2i(windowPosX, windowPosY));
    }
};*/
/*
class Game {
public:
    Game() {
        // Create the main window
        m_window.create(sf::VideoMode::getDesktopMode(), "Welcome to Point Mineral");
        centerWindow();

        // Load the background image
        if (!m_backgroundTexture.loadFromFile("ResourseFiles/WallPapers/Lobby.png")) {
            std::cout << "Error loading image file" << std::endl;
        }

        // Create the background sprite
        m_backgroundSprite.setTexture(m_backgroundTexture);

        // Load the button images
        if (!loadButtonTexture("ResourseFiles/Buttons/Play.png", m_playButtonTexture) ||
            !loadButtonTexture("ResourseFiles/Buttons/Load.png", m_loadButtonTexture)) {
            std::cout << "Error loading image file" << std::endl;
        }

        // Create the button sprites
        m_playButtonSprite.setTexture(m_playButtonTexture);
        centerButton(m_playButtonSprite);
        m_playButtonSprite.move(-650, 180);

        m_loadButtonSprite.setTexture(m_loadButtonTexture);
        centerButton(m_loadButtonSprite);
        m_loadButtonSprite.move(425, 180);
    }

    void run() {
        // Start the game loop
        while (m_window.isOpen()) {
            // Process events
            sf::Event event;
            while (m_window.pollEvent(event)) {
                // Close window: exit
                if (event.type == sf::Event::Closed)
                    m_window.close();

                // Handle mouse clicks
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        // Get the mouse position
                        sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                        // Check if the mouse is over the button
                        if (m_playButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                            std::cout << "Play button clicked!" << std::endl;
                        }
                        else if (m_loadButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                            std::cout << "Load button clicked!" << std::endl;
                        }
                    }
                }
            }

            // Clear the window
            m_window.clear();

            // Draw the background and buttons
            m_window.draw(m_backgroundSprite);
            m_window.draw(m_playButtonSprite);
            m_window.draw(m_loadButtonSprite);

            // Display the window
            m_window.display();
        }
    }

private:
    sf::RenderWindow m_window;
    sf::Texture m_backgroundTexture;
    sf::Sprite m_backgroundSprite;
    sf::Texture m_playButtonTexture;
    sf::Sprite m_playButtonSprite;
    sf::Texture m_loadButtonTexture;
    sf::Sprite m_loadButtonSprite;

    bool loadButtonTexture(const std::string& filepath, sf::Texture& texture) {
        if (!texture.loadFromFile(filepath)) {
            return false;
        }
        texture.setSmooth(true);
        texture.setRepeated(false);
        return true;
    }

    void centerButton(sf::Sprite& button) {
        button.setScale(sf::Vector2f(200.f / button.getLocalBounds().width, 120.f / button.getLocalBounds().height));
        float posX = (m_window.getSize().x - button.getLocalBounds().width * button.getScale().x) / 2;
        float posY = (m_window.getSize().y - button.getLocalBounds().height * button.getScale().y) / 2;
        button.setPosition(posX, posY);
    }

    void centerWindow() {
        float windowPosX = (sf::VideoMode::getDesktopMode().width - m_window.getSize().x) / 2;
        float windowPosY = (sf::VideoMode::getDesktopMode().height - m_window.getSize().y) / 2;
        m_window.setPosition(sf::Vector2i(windowPosX, windowPosY));
    }
};*/

int main() {
    Game game;
    game.run();
    return 0;
}