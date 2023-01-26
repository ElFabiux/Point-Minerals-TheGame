#include "Game.h"

bool Game::loadButton(const std::string& filepath, sf::Texture& texture) {
    if (!texture.loadFromFile(filepath)) {
        return false;
    }
    texture.setSmooth(true);
    texture.setRepeated(false);
    return true;
}


void Game::centerButton(sf::Sprite& button) {
    button.setScale(sf::Vector2f(200.f / button.getLocalBounds().width, 120.f / button.getLocalBounds().height));
    float posX = (window.getSize().x - button.getLocalBounds().width * button.getScale().x) / 2;
    float posY = (window.getSize().y - button.getLocalBounds().height * button.getScale().y) / 2;
    button.setPosition(posX, posY);
}

Game::Game() {
    // Create the main window
    window.create(sf::VideoMode::getDesktopMode(), "Welcome to Point Mineral");

    // Load the background image
    if (!backgroundTexture.loadFromFile("ResourseFiles/WallPapers/Lobby.png")) {
        std::cout << "Error loading image file" << std::endl;
    }

    // Create the background sprite
    backgroundSprite.setTexture(backgroundTexture);

    // Load the button images
    if (!loadButton("ResourseFiles/Buttons/Play.png", playButtonTexture) ||
        !loadButton("ResourseFiles/Buttons/Load.png", loadButtonTexture)) {
        std::cout << "Error loading image file" << std::endl;
    }

    // Create the button sprites
    playButtonSprite.setTexture(playButtonTexture);
    centerButton(playButtonSprite);
    playButtonSprite.move(-650, 180);

    loadButtonSprite.setTexture(loadButtonTexture);
    centerButton(loadButtonSprite);
    loadButtonSprite.move(425, 180);
}

void Game::run() {
    // Start the game loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

            // Handle mouse clicks
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Get the mouse position
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    // Check if the mouse is over the button
                    if (playButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        std::cout << "Play button clicked!" << std::endl;
                        window.close();
                        market.run();
                    }
                    else if (loadButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        std::cout << "Load button clicked!" << std::endl;
                    }
                }
            }
        }

        // Clear the window
        window.clear();

        // Draw the background and buttons
        window.draw(backgroundSprite);
        window.draw(playButtonSprite);
        window.draw(loadButtonSprite);

        // Display the window
        window.display();
    }
}
