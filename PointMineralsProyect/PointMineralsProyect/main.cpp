#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "ListCard.h"

/*class Node
{
public:
    sf::Sprite* card;
    Node* prev, * next;

    Node(sf::Sprite* c) : card(c), prev(nullptr), next(nullptr) {}
};

class ListCarta
{
public:
    Node* first, * last;

    ListCarta() : first(nullptr), last(nullptr) {}

    void push_front(sf::Sprite* c)
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

    void push_back(sf::Sprite* c)
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

    void insert_after(Node* n, sf::Sprite* c)
    {
        Node* newNode = new Node(c);
        newNode->prev = n;
        newNode->next = n->next;
        n->next = newNode;
    }

    void remove(Node* n)
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
};*/

int main()
{
    /*
    // Crear una ventana SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "Cartas");

    // Crear una lista doblemente enlazada de sprites
    ListCarta cardList;

    // Cargar las imágenes de las cartas en texturas
    sf::Texture cardTexture1, cardTexture2, cardTexture3;
    cardTexture1.loadFromFile("LogoGold.jpg");
    cardTexture2.loadFromFile("LogoDiamond.jpg");
    cardTexture3.loadFromFile("LogoRuby.jpg");

    // Crear sprites a partir de las texturas
    sf::Sprite card1(cardTexture1), card2(cardTexture2), card3(cardTexture3);

    // Agregar los sprites a la lista
    cardList.push_front(&card1);
    cardList.push_front(&card2);
    cardList.push_front(&card3);

    // Escalar los sprites a un tamaño más pequeño
    float scaleFactor = 0.5f;
    for (auto node = cardList.first; node != nullptr; node = node->next)
    {
        node->card->setScale(scaleFactor, scaleFactor);
    }

    // Bucle principal del juego
    while (window.isOpen())
    {
        // Procesar eventos de la ventana
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Limpiar la ventana
        window.clear();

        // Calcular la posición x de cada carta
        float cardWidth = card1.getGlobalBounds().width * scaleFactor;
        float xPos = (window.getSize().x - cardWidth * 3) / 2;

        // Alinear las cartas horizontalmente
        for (auto node = cardList.first; node != nullptr; node = node->next)
        {
            node->card->setPosition(xPos, window.getSize().y / 2);
            xPos += cardWidth;
        }

        // Dibujar las cartas en la ventana
        for (auto node = cardList.first; node != nullptr; node = node->next)
        {
            window.draw(*node->card);
        }

        // Mostrar la ventana
        window.display();
    }
    */
    Game game;

    return 0;
}
