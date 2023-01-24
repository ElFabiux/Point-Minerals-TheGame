#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Market.h"

class Game {

public:
    Game() {
        // Create the main window
        m_window.create(sf::VideoMode::getDesktopMode(), "Welcome to Point Mineral");

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
                            m_window.close();
                            m_market.run();
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
    Market m_market;
    

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
};