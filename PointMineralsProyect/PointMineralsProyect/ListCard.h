#pragma once
#include <SFML/Graphics.hpp>
#include "Node.h"

class ListCarta
{
public:
    Node* first, * last;

    ListCarta() : first(nullptr), last(nullptr) {}

    void push_front(sf::Sprite* c);
    void push_back(sf::Sprite* c);
    void insert_after(Node* n, sf::Sprite* c);
    void remove(Node* n);
};
