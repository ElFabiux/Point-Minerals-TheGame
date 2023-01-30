#include "Market.h"

Market::Market() : window(sf::VideoMode::getDesktopMode(), "Market"){
    if (!backgroundTexture.loadFromFile("ResourseFiles/WallPapers/Table.jpg")) {
        std::cout << "Error loading image file" << std::endl;
    }
    background.setTexture(backgroundTexture);
    centerWindow();
}

void Market::run() {
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.draw(background);

        window.display();
    }
}

void Market::centerWindow() {
    float windowPosX = (sf::VideoMode::getDesktopMode().width - window.getSize().x) / 2;
    float windowPosY = (sf::VideoMode::getDesktopMode().height - window.getSize().y) / 2;
    window.setPosition(sf::Vector2i(windowPosX, windowPosY));
}

