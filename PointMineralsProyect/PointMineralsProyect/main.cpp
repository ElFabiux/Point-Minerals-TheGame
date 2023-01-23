#include <iostream>
#include <SFML/Graphics.hpp>

void market() {

    sf::RenderWindow windowMarket(sf::VideoMode::getDesktopMode(), "Market");

    //load the background 
    sf::Texture marketTexture;
    if (!marketTexture.loadFromFile("ResourseFiles/WallPapers/Table.jpg"))
    {
        std::cout << "Error loading image ile" << std::endl;
    }
    // Create the background sprite
    sf::Sprite windowMarketSprite(marketTexture);

    // Center the window on the screen
    float windowPosX = (sf::VideoMode::getDesktopMode().width - windowMarket.getSize().x) / 2;
    float windowPosY = (sf::VideoMode::getDesktopMode().height - windowMarket.getSize().y) / 2;
    windowMarket.setPosition(sf::Vector2i(windowPosX, windowPosY));

    // Clear screen
    windowMarket.clear();

    // Draw the Background
    windowMarket.draw(windowMarketSprite);

    // Update the window
    windowMarket.display();

    while (windowMarket.isOpen())
    {
        // Process events
        sf::Event event;
        while (windowMarket.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                windowMarket.close();
        }
    }
}

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Welcome to Point Mineral");

    // Load the background image
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("ResourseFiles/WallPapers/Lobby.png"))
    {
        std::cout << "Error loading image file" << std::endl;
    }

    // Create the background sprite
    sf::Sprite backgroundSprite(backgroundTexture);

    // Load the button image->Play
    sf::Texture buttonPlay;
    if (!buttonPlay.loadFromFile("ResourseFiles/Buttons/Play.png"))
    {
        std::cout << "Error loading image file" << std::endl;
        return 1;
    }

    // Create the button sprite
    sf::Sprite buttonSpritePlay(buttonPlay);
    buttonSpritePlay.setScale(sf::Vector2f(200.f / buttonSpritePlay.getLocalBounds().width, 120.f / 
    buttonSpritePlay.getLocalBounds().height));

    //load the button image->Load
    sf::Texture buttonLoad;
    if (!buttonLoad.loadFromFile("ResourseFiles/Buttons/Load.png"))
    {
        std::cout << "Error loading image file" << std::endl;
    }
    sf::Sprite buttonSpriteLoad(buttonLoad);
    buttonSpriteLoad.setScale(sf::Vector2f(200.f / buttonSpriteLoad.getLocalBounds().width, 120.f /
    buttonSpriteLoad.getLocalBounds().height));

    /* Center the button Play on the screen
    float posXPlay = (window.getSize().x - buttonSpritePlay.getLocalBounds().width * buttonSpritePlay.getScale().x) / 2;
    float posYPlay = (window.getSize().y - buttonSpritePlay.getLocalBounds().height * buttonSpritePlay.getScale().y) / 2;
    buttonSpritePlay.setPosition(posXPlay, posYPlay);*/
    buttonSpritePlay.setPosition(window.getSize().x - buttonSpritePlay.getLocalBounds().width * 
    buttonSpritePlay.getScale().x, 180);
    buttonSpritePlay.move(-650,0);

    // Center the button Load on the screen
    /*float posXLoad = (window.getSize().x - buttonSpriteLoad.getLocalBounds().width * buttonSpriteLoad.getScale().x) / 2;
    float posYLoad = (window.getSize().y - buttonSpriteLoad.getLocalBounds().height * buttonSpriteLoad.getScale().y) / 2;
    buttonSpriteLoad.setPosition(posXLoad, posYLoad);*/
    buttonSpriteLoad.setPosition(buttonSpritePlay.getLocalBounds().width * buttonSpritePlay.getScale().x, 180);
    buttonSpriteLoad.move(425, 0);
   

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
                    if (buttonSpritePlay.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        std::cout << "Button clicked!" << std::endl;
                        //close window
                        window.close();
                        //call the market
                        market();
                        break;
                    }
                }
            }
        }

        // Clear screen
        window.clear();

        // Draw the Background
        window.draw(backgroundSprite);
        // Draw the button Play
        window.draw(buttonSpritePlay);

        //Draw the button Load
        window.draw(buttonSpriteLoad);

        // Update the window
        window.display();
    }

    return 0;
}