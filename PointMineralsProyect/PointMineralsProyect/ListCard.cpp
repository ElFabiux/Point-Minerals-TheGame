#include "ListCard.h"

void ListCarta::push_front(sf::Sprite* c)
{
    Node* n = new Node(c);
    if (first == nullptr)
    {
        first = last = n;
    }
    else
    {
        n->next = first;
        first->prev = n;
        first = n;
    }
}

void ListCarta::push_back(sf::Sprite* c)
{
    Node* n = new Node(c);
    if (first == nullptr)
    {
        first = last = n;
    }
    else
    {
        n->prev = last;
        last->next = n;
        last = n;
    }
}

void ListCarta::insert_after(Node* n, sf::Sprite* c)
{
    Node* newNode = new Node(c);
    newNode->prev = n;
    newNode->next = n->next;
    n->next = newNode;
}

void ListCarta::remove(Node* n)
{
    if (n == first)
    {
        first = n->next;
        first->prev = nullptr;
    }
    else if (n == last)
    {
        last = n->prev;
        last->next = nullptr;
    }
    else
    {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }
    delete n;
}
