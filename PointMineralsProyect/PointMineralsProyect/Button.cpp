#include "Button.h"

Button::Button() {

}

Button::Button(const string& texture) {
	this->texture.loadFromFile(texture);
	this->sprite.setTexture(this->texture);
}

void Button::setButtonTexture(const string& texture) {
	this->texture.loadFromFile(texture);
}

void Button::createSprite() {
	sprite.setTexture(texture);
}

void Button::showButton(sf::RenderWindow& window) {
	window.draw(sprite);
}

void Button::centerButton(sf::RenderWindow& window) {
	sprite.setScale(sf::Vector2f(200.f / sprite.getLocalBounds().width, 120.f / sprite.getLocalBounds().height));
	float posX = (window.getSize().x - sprite.getLocalBounds().width * sprite.getScale().x) / 2;
	float posY = (window.getSize().y - sprite.getLocalBounds().height * sprite.getScale().y) / 2;
	sprite.setPosition(posX, posY);
}

void Button::moveButton(int y, int x) {
	this->sprite.move(y, x);
}

bool Button::mouseClick(sf::RenderWindow& window) {
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	if (sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
		return true;
	}
	return false;
}