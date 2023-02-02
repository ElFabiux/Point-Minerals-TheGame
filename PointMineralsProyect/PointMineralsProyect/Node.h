#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Node
{
public:
    sf::Sprite* card;
    Node* prev, * next;

    Node(sf::Sprite* c) : card(c), prev(nullptr), next(nullptr) {}
};
