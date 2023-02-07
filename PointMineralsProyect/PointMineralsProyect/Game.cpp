#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Card.h"
#include "LinkedList.h"
#include <sstream>
#include <random>
#include "Player.h"

Player player1(10, 10);
Player player2(410, 10);

string group1[12];
string group2[12];
string group3[12];

int g1 = 0;
int g2 = 0;
int g3 = 0;

int monton1 = 11;
int monton2 = 11;
int monton3 = 11;

int x[36];
int y[36];
int i = 0;

int currentPlayer = 1;
int J1x = 7;
int J1y = 165;

int J2x = 517;
int J2y = 165;

bool game = true;
int playerPlays = 0;

int cartasUsadas1 = 0;
int cartasUsadas2 = 0;

LinkedList cardList;
LinkedList conditionList;

int movedCards[4];
string cardsJ1[17];
string cardsJ2[17];
int playerCounter1 = 0;
int playerCounter2 = 0;

int M = 0;

sf::Sprite cardsSprites[35];

vector<string> cardVector;

void Game::createGroups(LinkedList cardList) {

    for (auto node = cardList.first; node != nullptr; node = node->next)
    {
        ostringstream oss{};
        oss << node;
        string cardNode = oss.str();
        sf::Vector2f pos = (*node->card).getPosition();

        if (pos.x == x[0])
        {
            std::cout << "posicion de grupo1 " << pos.x << " " << x[0] << " " << cardNode << std::endl;

            group1[g1] = cardNode;
            g1++;
        }
        if (pos.x == x[1])
        {
            std::cout << "posicion de grupo2 " << pos.x << " " << x[0] << " " << cardNode << std::endl;

            group2[g2] = cardNode;
            g2++;
        }
        if (pos.x == x[2])
        {
            std::cout << "posicion de grupo3 " << pos.x << " " << x[0] << " " << cardNode << std::endl;

            group3[g3] = cardNode;
            g3++;
        }
    }
}

void Game::calculatePositions(LinkedList cardList) {

    for (auto node = cardList.first; node != nullptr; node = node->next)
    {
        sf::Vector2f pos = (*node->card).getPosition();
        x[i] = pos.x;
        y[i] = pos.y;
        i++;
    }
}

void Game::changePositions(LinkedList cardList) {
    for (int i = 0; i < 36; i++)
    {
        for (auto node = cardList.first; node != nullptr; node = node->next)
        {
            ostringstream oss{};
            oss << node;
            string cardString = oss.str();
            if (cardVector[i] == cardString) {

                node->card->setPosition(x[i], y[i]);
            }
        }
    }
}

LinkedList Game::positions(sf::RenderWindow& window, LinkedList cardlist, float cardWidth) {
    float xPos = (window.getSize().x) / 2.446;
    float yPos = (window.getSize().y) / 2.30;
    int a = 0;

    for (auto node = cardlist.first; node != nullptr; node = node->next)
    {
        node->card->setPosition(xPos, yPos);
        xPos += cardWidth * 2.1;
        if ((a + 1) % 3 == 0) {
            yPos += 0;
            xPos = (window.getSize().x) / 2.446;

        }
        a++;
    }

    return cardlist;
}

LinkedList Game::rescale(LinkedList cardList) {

    float scaleFactor = 0.5f;

    for (auto node = cardList.first; node != nullptr; node = node->next)
    {
        std::cout << "nodo: " << node << std::endl;
        node->card->setScale(scaleFactor, scaleFactor);
    }
    std::cout << "reescalando..." << std::endl;
    return cardList;
}

void Game::updateGame(LinkedList cardlist, sf::RenderWindow& window) {
    sf::Texture backgroundTexture;

    sf::Sprite backgroundSprite;
    backgroundTexture.loadFromFile("ResourseFiles/WallPapers/Table.jpg");
    backgroundSprite.setTexture(backgroundTexture);
    sf::Vector2u windowSize = window.getSize();
    backgroundSprite.setScale(
        windowSize.x / backgroundSprite.getLocalBounds().width,
        windowSize.y / backgroundSprite.getLocalBounds().height
    );
    sf::Color colorFondo(28, 211, 120);
    window.clear(colorFondo);
    window.draw(backgroundSprite);
    player1.drawPlayer(window);
    player2.drawPlayer(window);
    for (auto node = cardlist.first; node != nullptr; node = node->next)
    {

        window.draw(*node->card);
    }
    window.display();

}

void Game::play(LinkedList cardList, sf::Vector2i mousePos, int cardU, int currentPlayer, sf::RenderWindow& window, int jx, int jy) {

    int x = 2;
    int y = 1;
    for (auto node = cardList.first; node != nullptr; node = node->next)
    {
        sf::FloatRect spriteBounds = node->card->getGlobalBounds();
        if (spriteBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
            ostringstream oss{};
            oss << node;
            string cardNode = oss.str();
            sf::Vector2f pos = (*node->card).getPosition();
            movedCards[M + 1] = pos.x;
            movedCards[M + 1] = pos.y;
            M = M + 2;
            int posicion1 = pos.x;
            int posicion2 = pos.y;
            std::cout << "click en carta detectado: x" << pos.x << " y" << pos.y << "  " << node << std::endl;
            if (pos.y > 400)
            {

                //JUGADOR 1: 
                if (currentPlayer == 1)
                {
                    cardsJ1[playerCounter1] = cardNode;
                    playerCounter1++;
                    std::cout << "coordenadas 1  " << jx << " " << jy << std::endl;
                    while ((posicion1 > jx) && (posicion2 > jy))
                    {
                        node->card->setPosition(posicion1, posicion2);
                        if (posicion1 > jx) {

                            sf::Vector2f pos = (*node->card).getPosition();

                            posicion1 = posicion1 - 2;
                            //    std::cout << "Moviendo...  x  "<< posicion1 << std::endl;
                        }
                        if (posicion2 > jy)
                        {

                            posicion2 = posicion2 - 1;
                            //     std::cout << "Moviendo...  y  "<< posicion2 << std::endl;
                        }

                        updateGame(cardList, window);
                    }

                    std::cout << "coordenadas nuevas 1  " << posicion1 << " " << posicion2 << std::endl;

                    if (posicion1 <= jx)
                    {
                        while (posicion2 > jy)
                        {
                            //       std::cout << "Falto y  "<< std::endl;
                            node->card->setPosition(posicion1, posicion2);
                            if (posicion2 > jy)
                            {

                                posicion2 = posicion2 - 1;
                                //          std::cout << "Moviendo...  y  " << posicion2 << std::endl;
                                updateGame(cardList, window);
                            }
                        }
                    }
                    std::cout << "coordenadas nuevas 1  " << posicion1 << " " << posicion2 << std::endl;
                    if (posicion2 <= jy)
                    {
                        while (posicion1 > jx)
                        {
                            //     std::cout << "Falto x  " << std::endl;
                            node->card->setPosition(posicion1, posicion2);
                            if (posicion1 > jx)
                            {

                                posicion1 = posicion1 - 2;
                                //       std::cout << "Moviendo...  x  " << posicion1 << std::endl;
                                updateGame(cardList, window);
                            }
                        }
                    }
                    std::cout << "coordenadas nuevas 1  " << posicion1 << " " << posicion2 << std::endl;

                    if (M == 4)
                    {
                        fillMarket(window);
                    }
                }

                //JUGADOR 2:
                if (currentPlayer == 2)
                {
                    cardsJ2[playerCounter2] = cardNode;
                    playerCounter2++;
                    std::cout << "coordenadas 2  " << jx << " " << jy << std::endl;
                    while ((posicion1 < jx) && (posicion2 > jy))
                    {
                        node->card->setPosition(posicion1, posicion2);
                        if (posicion1 < jx) {

                            sf::Vector2f pos = (*node->card).getPosition();

                            posicion1 = posicion1 + 2;
                            //      std::cout << "Moviendo...  x  " << posicion1 << std::endl;
                        }
                        if (posicion2 > jy)
                        {

                            posicion2 = posicion2 - 1;
                            //      std::cout << "Moviendo...  y  " << posicion2 << std::endl;
                        }

                        updateGame(cardList, window);


                    }
                    std::cout << "coordenadas nuevas 2  " << posicion1 << " " << posicion2 << std::endl;
                    if (posicion1 >= jx)
                    {

                        while (posicion2 > jy)
                        {
                            //        std::cout << "Falto y  " << std::endl;
                            node->card->setPosition(posicion1, posicion2);
                            if (posicion2 > jy)
                            {

                                posicion2 = posicion2 - 1;
                                //           std::cout << "Moviendo...  y  " << posicion2 << std::endl;
                                updateGame(cardList, window);
                            }
                        }
                    }
                    std::cout << "coordenadas nuevas 2  " << posicion1 << " " << posicion2 << std::endl;
                    if (posicion2 >= jy)
                    {
                        while (posicion1 < jx)
                        {
                            //      std::cout << "Falto x  " << std::endl;
                            node->card->setPosition(posicion1, posicion2);
                            if (posicion1 < jx)
                            {

                                posicion1 = posicion1 + 2;
                                //         std::cout << "Moviendo...  x  " << posicion1 << std::endl;
                                updateGame(cardList, window);
                            }
                        }
                    }
                    std::cout << "coordenadas nuevas 2  " << posicion1 << " " << posicion2 << std::endl;
                    if (M == 4)
                    {
                        fillMarket(window);
                    }
                }
            }
        }
    }
}

void Game::fillMarket(sf::RenderWindow& window) {

    int half = 0;
    for (auto node = cardList.first; node != nullptr; node = node->next)
    {
        sf::Vector2f pos = (*node->card).getPosition();

        if (pos.y == 260)
        {
            ostringstream oss{};
            oss << node;
            string cardNode = oss.str();

            if (movedCards[0] == 327)
            {
                if (cardNode == group1[monton1]) {
                    node->card->setPosition(movedCards[0], movedCards[1]);

                    monton1--;
                    M = 0;
                }
            }
            if (movedCards[0] == 382)
            {

                if (cardNode == group2[monton2]) {
                    node->card->setPosition(movedCards[0], movedCards[1]);
                    monton2--;
                    M = 0;
                }
            }
            if (movedCards[0] == 438)
            {

                if (cardNode == group3[monton3]) {
                    node->card->setPosition(movedCards[0], movedCards[1]);
                    monton3--;
                    M = 0;
                }
            }

        }
    }

    for (auto node = cardList.first; node != nullptr; node = node->next)
    {
        sf::Vector2f pos = (*node->card).getPosition();

        if (pos.y == 260)
        {
            ostringstream oss{};
            oss << node;
            string cardNode = oss.str();

            //CARTA 2
            if (movedCards[2] == 327)
            {

                if (cardNode == group1[monton1]) {
                    node->card->setPosition(movedCards[2], movedCards[3]);
                    monton1--;

                    M = 0;
                }
            }
            if (movedCards[2] == 382)
            {

                if (cardNode == group2[monton2]) {
                    node->card->setPosition(movedCards[2], movedCards[3]);
                    monton2--;
                    M = 0;
                }
            }
            if (movedCards[2] == 438)
            {

                if (cardNode == group3[monton3]) {
                    node->card->setPosition(movedCards[2], movedCards[3]);
                    monton3--;
                    M = 0;
                }
            }
        }
    }


    //monton 1
    if (monton1 < 1)
    {
        if (monton2 >= monton3)
        {
            half = (monton2 / 2);
            monton2 = monton2 - half;
            for (int i = 0; i < half; i++)
            {
                group1[i] = group2[i];
                monton1 = monton1 + (half - 1);

                for (auto node = cardList.first; node != nullptr; node = node->next) {
                    ostringstream oss{};
                    oss << node;
                    string cardNode = oss.str();
                    sf::Vector2f pos = (*node->card).getPosition();
                    if (cardNode == group2[i])
                    {
                        if (pos.y == 260)
                        {
                            std::cout << "carta movida del grupo 2: " << cardNode << node << std::endl;
                            node->card->setPosition(327, pos.y);
                        }


                    }

                }

            }
        }
        else
        {
            half = (monton3 / 2);
            monton3 = monton3 - half;
            for (int i = 0; i < half; i++)
            {
                group1[i] = group3[i];
                monton1 = monton1 + (half - 1);
                for (auto node = cardList.first; node != nullptr; node = node->next) {
                    ostringstream oss{};
                    oss << node;
                    string cardNode = oss.str();
                    sf::Vector2f pos = (*node->card).getPosition();
                    if (cardNode == group3[i])
                    {
                        if (pos.y == 260)
                        {
                            node->card->setPosition(327, pos.y);
                            std::cout << "carta movida del grupo 3: " << cardNode << node << std::endl;

                        }
                    }

                }

            }

        }
    }

    //monton 2
    if (monton2 < 1)
    {
        if (monton1 >= monton3)
        {
            half = (monton1 / 2);
            monton1 = monton1 - half;
            for (int i = 0; i < half; i++)
            {
                group2[i] = group1[i];
                monton2 = monton2 + (half - 1);

                for (auto node = cardList.first; node != nullptr; node = node->next) {
                    ostringstream oss{};
                    oss << node;
                    string cardNode = oss.str();
                    sf::Vector2f pos = (*node->card).getPosition();
                    if (cardNode == group1[i])
                    {
                        if (pos.y == 260)
                        {
                            node->card->setPosition(382, pos.y);
                            std::cout << "carta movida del grupo 1 monton 2: " << cardNode << node << std::endl;
                        }
                    }
                }

            }
        }
        else
        {
            half = (monton3 / 2);
            monton3 = monton3 - half;
            for (int i = 0; i < half; i++)
            {
                group2[i] = group3[i];
                monton2 = monton2 + (half - 1);

                for (auto node = cardList.first; node != nullptr; node = node->next) {
                    ostringstream oss{};
                    oss << node;
                    string cardNode = oss.str();
                    sf::Vector2f pos = (*node->card).getPosition();
                    if (cardNode == group3[i])
                    {
                        if (pos.y == 260)
                        {
                            node->card->setPosition(382, pos.y);
                            std::cout << "carta movida del grupo 3: " << cardNode << node << std::endl;
                        }
                    }

                }

            }

        }
    }

    //monton 3
    if (monton3 < 1)
    {
        if (monton2 >= monton1)
        {
            half = (monton2 / 2);
            monton2 = monton2 - half;
            for (int i = 0; i < half; i++)
            {
                group3[i] = group2[i];
                monton3 = monton3 + half;

                for (auto node = cardList.first; node != nullptr; node = node->next) {
                    ostringstream oss{};
                    oss << node;
                    string cardNode = oss.str();
                    sf::Vector2f pos = (*node->card).getPosition();
                    if (cardNode == group2[i])
                    {
                        if (pos.y == 260)
                        {
                            node->card->setPosition(438, pos.y);
                            std::cout << "carta movida del grupo 2: " << cardNode << node << std::endl;
                        }
                    }

                }

            }

        }
        else
        {
            half = (monton1 / 2);
            monton1 = monton1 - half;
            for (int i = 0; i < half; i++)
            {
                group3[i] = group1[i];
                monton3 = monton3 + half;

                for (auto node = cardList.first; node != nullptr; node = node->next) {
                    ostringstream oss{};
                    oss << node;
                    string cardNode = oss.str();
                    sf::Vector2f pos = (*node->card).getPosition();
                    if (cardNode == group1[i])
                    {
                        if (pos.y == 260)
                        {
                            node->card->setPosition(438, pos.y);
                            std::cout << "carta movida del grupo 1: monton 3" << cardNode << node << std::endl;
                        }
                    }

                }

            }

        }
    }


    for (int i = 0; i < 17; i++)
    {
        std::cout << "cartas de jugador 1: " << cardsJ1[i] << std::endl;
        std::cout << "cartas de jugador 2: " << cardsJ2[i] << std::endl;
    }

    updateGame(cardList, window);
}

void Game::autoMovement(LinkedList cardList, string group[], int monton) {

    int movimientos = 2;
    int cant = monton;
    int y = 407;

    while (movimientos > 0)
    {
        for (auto node = cardList.first; node != nullptr; node = node->next)
        {
            ostringstream oss{};
            oss << node;
            string cardNode = oss.str();
            sf::Vector2f pos = (*node->card).getPosition();


            if (cardNode == group[cant])
            {

                cant--;
                node->card->setPosition(pos.x, y);
                sf::Vector2f pos1 = (*node->card).getPosition();
                movimientos = movimientos - 1;
                y += 73;
                std::cout << "carta movida   " << pos1.x << " " << pos1.y << std::endl;
            }
        }
    }
}


float Game::height(sf::Sprite card) {
    float scaleFactor = 0.5f;
    float cardHeight = card.getGlobalBounds().height * scaleFactor;

    return cardHeight;
}


float Game::width(sf::Sprite card) {
    float scaleFactor = 0.5f;
    float cardWidth = card.getGlobalBounds().width * scaleFactor;

    return cardWidth;
}


void Game::createLobby() {

    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    std::ostringstream oss{};

    // Create the main window 
    window.create(sf::VideoMode::getDesktopMode(), "Welcome to Point Mineral");

    // Load the background image 
    backgroundTexture.loadFromFile("ResourseFiles/WallPapers/Lobby.png");

    // Create the background sprite 
    backgroundSprite.setTexture(backgroundTexture);
    runLobbyWindow(window, backgroundSprite);

}


void Game::createMarket() {

    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;


    // Create the main window 
    window.create(sf::VideoMode(800, 600), "welcome to Point Mineral");

    // Load the background image 
    backgroundTexture.loadFromFile("ResourseFiles/WallPapers/Table.jpg");

    // Create the background sprite 
    backgroundSprite.setTexture(backgroundTexture);
    runMarketWindow(window, backgroundSprite);

}


void Game::runLobbyWindow(sf::RenderWindow& window, sf::Sprite& backgroundSprite)
{
    sf::Vector2u windowSize = window.getSize();
    backgroundSprite.setScale(
        windowSize.x / backgroundSprite.getLocalBounds().width,
        windowSize.y / backgroundSprite.getLocalBounds().height
    );
    Button playB("ResourseFiles/Buttons/Play.png");
    Button loadB("ResourseFiles/Buttons/Load.png");

    playB.centerButton(window);
    loadB.centerButton(window);
    playB.moveButton(-425, 180);
    loadB.moveButton(425, 180);

    window.setFramerateLimit(60);

    while (window.isOpen()) {

        // Process events 

        sf::Event event;

        while (window.pollEvent(event)) {

            // Close window: exit 

            if (event.type == sf::Event::Closed)

                window.close();

            // Handle mouse clicks 
            if (event.type == sf::Event::MouseButtonPressed) {

                if (event.mouseButton.button == sf::Mouse::Left) {

                    // Get the mouse position 

                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    // Check if the mouse is over the button 

                    if (playB.mouseClick(window)) {

                        std::cout << "Play button clicked!" << std::endl;

                        window.close();

                        createMarket();

                    }
                    else if (loadB.mouseClick(window)) {

                        std::cout << "Load button clicked!" << std::endl;

                    }

                }

            }

        }

        // Clear the window 
        window.clear();

        // Draw the background and buttons 
        window.draw(backgroundSprite);

        playB.showButton(window);
        loadB.showButton(window);

        // Display the window 

        window.display();

    }

}


void Game::runMarketWindow(sf::RenderWindow& window, sf::Sprite& backgroundSprite) {
    int fps = 240;
    sf::Vector2u windowSize = window.getSize();
    backgroundSprite.setScale(
        windowSize.x / backgroundSprite.getLocalBounds().width,
        windowSize.y / backgroundSprite.getLocalBounds().height
    );
    window.setFramerateLimit(fps);

    while (window.isOpen()) {
        sf::Event event;


        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)

                window.close();
        }
        sf::Color colorFondo(28, 211, 120);
        window.clear(colorFondo);
        window.draw(backgroundSprite);


        sf::Texture cardTexture1, cardTexture2, cardTexture3, cardTexture4, cardTexture5, cardTexture6;
        cardTexture1.loadFromFile("ResourseFiles/Diamond/LogoDiamond.jpg");
        cardTexture2.loadFromFile("ResourseFiles/Emerald/LogoEmerald.jpg");
        cardTexture3.loadFromFile("ResourseFiles/Fluorite/LogoFluorite.jpg");

        cardTexture4.loadFromFile("ResourseFiles/Gold/LogoGold.jpg");
        cardTexture5.loadFromFile("ResourseFiles/Iron/LogoIron.jpg");
        cardTexture6.loadFromFile("ResourseFiles/Ruby/LogoRuby.jpg");

        // Crear sprites a partir de las texturas


        sf::Sprite card1(cardTexture1), card2(cardTexture2), card3(cardTexture3);
        sf::Sprite card4(cardTexture4), card5(cardTexture5), card6(cardTexture6);

        sf::Sprite card7(cardTexture1), card8(cardTexture2), card9(cardTexture3);
        sf::Sprite card10(cardTexture4), card11(cardTexture5), card12(cardTexture6);


        sf::Sprite card13(cardTexture1), card14(cardTexture2), card15(cardTexture3);
        sf::Sprite card16(cardTexture4), card17(cardTexture5), card18(cardTexture6);

        sf::Sprite card19(cardTexture1), card20(cardTexture2), card21(cardTexture3);
        sf::Sprite card22(cardTexture4), card23(cardTexture5), card24(cardTexture6);

        sf::Sprite card25(cardTexture1), card26(cardTexture2), card27(cardTexture3);
        sf::Sprite card28(cardTexture4), card29(cardTexture5), card30(cardTexture6);

        sf::Sprite card31(cardTexture1), card32(cardTexture2), card33(cardTexture3);
        sf::Sprite card34(cardTexture4), card35(cardTexture5), card36(cardTexture6);


        cardList.pushFront(&card1);
        cardList.pushFront(&card2);
        cardList.pushFront(&card3);
        cardList.pushFront(&card4);
        cardList.pushFront(&card5);
        cardList.pushFront(&card6);
        cardList.pushFront(&card7);
        cardList.pushFront(&card8);
        cardList.pushFront(&card9);
        cardList.pushFront(&card10);
        cardList.pushFront(&card11);
        cardList.pushFront(&card12);

        cardList.pushFront(&card13);
        cardList.pushFront(&card14);
        cardList.pushFront(&card15);
        cardList.pushFront(&card16);
        cardList.pushFront(&card17);
        cardList.pushFront(&card18);
        cardList.pushFront(&card19);
        cardList.pushFront(&card20);
        cardList.pushFront(&card21);
        cardList.pushFront(&card22);
        cardList.pushFront(&card23);
        cardList.pushFront(&card24);

        cardList.pushFront(&card25);
        cardList.pushFront(&card26);
        cardList.pushFront(&card27);
        cardList.pushFront(&card28);
        cardList.pushFront(&card29);
        cardList.pushFront(&card30);
        cardList.pushFront(&card31);
        cardList.pushFront(&card32);
        cardList.pushFront(&card33);
        cardList.pushFront(&card34);
        cardList.pushFront(&card35);
        cardList.pushFront(&card36);

        cardList = rescale(cardList);
        float scaleFactor = 0.5f;

        float cardWidth = card1.getGlobalBounds().width * scaleFactor;
        float cardHigh = card1.getGlobalBounds().height * scaleFactor;

        cardList = positions(window, cardList, cardWidth);

        //obtiene el nodo de cada carta y lo guarda en cardVector

        for (auto node = cardList.first; node != nullptr; node = node->next) {
            ostringstream oss{};
            oss << node;
            string cardString = oss.str();
            cardVector.push_back(cardString);
        }

        //reordena los indices aleatoriamente
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(cardVector.begin(), cardVector.end(), g);

        //obtiene la posicion de cada carta


        calculatePositions(cardList);
        changePositions(cardList);
        createGroups(cardList);


        autoMovement(cardList, group1, monton1);
        monton1 = monton1 - 2;
        autoMovement(cardList, group2, monton2);
        monton2 = monton2 - 2;
        autoMovement(cardList, group3, monton3);
        monton3 = monton3 - 2;

        for (auto node = cardList.first; node != nullptr; node = node->next)
        {


            //std::cout <<"posicion: " << pos.x << "," << pos.y << std::endl;
             // std::cout << "carta dibujada!"<< node << std::endl;
            window.draw(*node->card);
        }

        window.display();

        //bucle para verificar las jugadas
        while (game = true)
        {
            sf::Event event;
            if (window.waitEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                        for (auto node = cardList.first; node != nullptr; node = node->next)
                        {
                            sf::FloatRect spriteBounds = node->card->getGlobalBounds();
                            if (spriteBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {

                                if (playerPlays < 5)
                                {

                                    playerPlays++;
                                    if (currentPlayer == 1)
                                    {
                                        std::cout << "cartas jugadas 1: " << cartasUsadas1 << std::endl;
                                        std::cout << "movimiento j1 en x: " << J1x << std::endl;

                                        play(cardList, mousePos, cartasUsadas1, currentPlayer, window, J1x, J1y);

                                        J1x += cardWidth * 2.1;;


                                        if (cartasUsadas1 == 4)
                                        {
                                            J1x = 7;
                                            J1y += cardHigh * 2;
                                            cartasUsadas1 = 0;
                                        }
                                        else
                                        {
                                            cartasUsadas1++;
                                        }

                                        std::cout << "jugada: " << playerPlays << std::endl;
                                        if (playerPlays == 2)
                                        {


                                            currentPlayer = 2;


                                        }

                                    }
                                    if (playerPlays >= 3)
                                    {
                                        std::cout << "cartas jugadas 2: " << cartasUsadas2 << std::endl;
                                        if (currentPlayer == 2)
                                        {
                                            std::cout << "movimiento j2 en x: " << J2x << std::endl;


                                            play(cardList, mousePos, cartasUsadas2, currentPlayer, window, J2x, J2y);

                                            J2x += cardWidth * 2.1;;

                                            if (cartasUsadas2 == 4)
                                            {
                                                J2x = 517;
                                                J2y += cardHigh * 2;
                                                cartasUsadas2 = 0;
                                            }
                                            else
                                            {
                                                cartasUsadas2++;
                                            }
                                            std::cout << "jugada: " << playerPlays << std::endl;
                                            if (playerPlays == 4)
                                            {
                                                currentPlayer = 1;
                                                playerPlays = playerPlays - 4;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

Game::Game() {
    createLobby();
}