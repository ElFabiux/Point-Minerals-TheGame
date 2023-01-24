#include "Market.h"
#include <SFML/Graphics.hpp>

Market::Market() : m_window(sf::VideoMode::getDesktopMode(), "Market"), m_baraja() {
	if (!m_backgroundTexture.loadFromFile("ResourseFiles/WallPapers/Table.jpg")) {
		std::cout << "Error loading image file" << std::endl;
	}
	m_background.setTexture(m_backgroundTexture);
	centerWindow();
}

void Market::run() {
    while (m_window.isOpen()) {
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }

        m_window.draw(m_background);

        for (int i = 0; i < m_baraja.getNumCartas(); i++) {
            m_window.draw(m_baraja.getCartas()[i].getSprite());
        }

        m_window.display();
    }
}

void Market::centerWindow() {
	float windowPosX = (sf::VideoMode::getDesktopMode().width - m_window.getSize().x) / 2;
	float windowPosY = (sf::VideoMode::getDesktopMode().height - m_window.getSize().y) / 2;
	m_window.setPosition(sf::Vector2i(windowPosX, windowPosY));
}


