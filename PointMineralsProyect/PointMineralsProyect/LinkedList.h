#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Node.h"

class LinkedList
{
public:
    Node* first, * last;

    LinkedList() : first(nullptr), last(nullptr) {}

    void pushFront(sf::Sprite* c);
    void pushBack(sf::Sprite* c);
    void insertAfter(Node* n, sf::Sprite* c);
    void remove(Node* n);
};
