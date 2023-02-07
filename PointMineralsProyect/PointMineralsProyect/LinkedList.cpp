#include "LinkedList.h"

void LinkedList::pushFront(sf::Sprite* c)
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

void LinkedList::pushBack(sf::Sprite* c)
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

void LinkedList::insertAfter(Node* n, sf::Sprite* c)
{
    Node* newNode = new Node(c);
    newNode->prev = n;
    newNode->next = n->next;
    n->next = newNode;
}

void LinkedList::remove(Node* n)
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
