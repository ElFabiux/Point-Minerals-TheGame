#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Welcome to Point Mineral");

    // Load the background image
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("ResourseFiles/WallPapers/Lobby.png"))
    {
        std::cout << "Error loading image file" << std::endl;
        return 1;
    }

    // Create the background sprite
    sf::Sprite backgroundSprite(backgroundTexture);

    // Load the button image
    sf::Texture buttonTexture;
    if (!buttonTexture.loadFromFile("ResourseFiles/Buttons/Play.png"))
    {
        std::cout << "Error loading image file" << std::endl;
        return 1;
    }

    // Create the button sprite
    sf::Sprite buttonSprite(buttonTexture);
    buttonSprite.setScale(sf::Vector2f(100.f / buttonSprite.getLocalBounds().width, 50.f / buttonSprite.getLocalBounds().height));

    // Center the button on the screen
    float posX = (window.getSize().x - buttonSprite.getLocalBounds().width * buttonSprite.getScale().x) / 2;
    float posY = (window.getSize().y - buttonSprite.getLocalBounds().height * buttonSprite.getScale().y) / 2;
    buttonSprite.setPosition(posX, posY);


    // Center the window on the screen
    float windowPosX = (sf::VideoMode::getDesktopMode().width - window.getSize().x) / 2;
    float windowPosY = (sf::VideoMode::getDesktopMode().height - window.getSize().y) / 2;
    window.setPosition(sf::Vector2i(windowPosX, windowPosY));

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

            // Handle mouse clicks
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    // Get the mouse position
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    // Check if the mouse is over the button
                    if (buttonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        std::cout << "Button clicked!" << std::endl;
                    }
                }
            }
        }

        // Clear screen
        window.clear();

        // Draw the Background
        window.draw(backgroundSprite);
        // Draw the button
        window.draw(buttonSprite);

        // Update the window
        window.display();
    }

    return 0;
}