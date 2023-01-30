#include "Game.h"

//Cargar los botones
bool Game::loadButtons(const std::string& filepath, sf::Texture& texture) {
    if (!texture.loadFromFile(filepath)) {
        return false;
    }
    texture.setSmooth(true);
    texture.setRepeated(false);
    return true;
}

//Centrar los botones
void Game::centerButton(sf::Sprite& button, sf::RenderWindow& window) {
    button.setScale(sf::Vector2f(200.f / button.getLocalBounds().width, 120.f / button.getLocalBounds().height));
    float posX = (window.getSize().x - button.getLocalBounds().width * button.getScale().x) / 2;
    float posY = (window.getSize().y - button.getLocalBounds().height * button.getScale().y) / 2;
    button.setPosition(posX, posY);
}

//Cargar la ventana 
void Game::runLobbyWindow(sf::RenderWindow& window, sf::Sprite& playButtonSprite, sf::Sprite& loadButtonSprite,
    sf::Sprite& backgroundSprite)
{
    window.setFramerateLimit(60);
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
                        createMarket();
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

void Game::runMarketWindow(sf::RenderWindow& window, sf::Sprite& backgroundSprite) {
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        window.draw(backgroundSprite);

        window.display();
    }
}

void Game::createLobby() {
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    // Create the main window
    window.create(sf::VideoMode::getDesktopMode(), "Welcome to Point Mineral");

    // Load the background image
    backgroundTexture.loadFromFile("ResourseFiles/WallPapers/Lobby.png");

    // Create the background sprite
    backgroundSprite.setTexture(backgroundTexture);

    sf::Texture playButtonTexture;
    sf::Sprite playButtonSprite;
    sf::Texture loadButtonTexture;
    sf::Sprite loadButtonSprite;

    // Load the button images
    loadButtons("ResourseFiles/Buttons/Play.png", playButtonTexture);
    loadButtons("ResourseFiles/Buttons/Load.png", loadButtonTexture);

    // Create the button sprites
    playButtonSprite.setTexture(playButtonTexture);
    centerButton(playButtonSprite, window);
    playButtonSprite.move(-425, 180);

    loadButtonSprite.setTexture(loadButtonTexture);
    centerButton(loadButtonSprite, window);
    loadButtonSprite.move(425, 180);

    runLobbyWindow(window, playButtonSprite, loadButtonSprite, backgroundSprite);
}

void Game::createMarket() {
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    // Create the main window
    window.create(sf::VideoMode::getDesktopMode(), "Welcome to Point Mineral");

    // Load the background image
    backgroundTexture.loadFromFile("ResourseFiles/WallPapers/Table.jpg");

    // Create the background sprite
    backgroundSprite.setTexture(backgroundTexture);

    runMarketWindow(window, backgroundSprite);
}

Game::Game() {
    createLobby();
}
