#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Button
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Button();
	Button(const string&);
	void setButtonTexture(const string&);
	void createSprite();
	void showButton(sf::RenderWindow&);
	void centerButton(sf::RenderWindow&);
	void moveButton(int, int);
	bool mouseClick(sf::RenderWindow& window);
};

