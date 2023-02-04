#include <iostream>
#include <SFML/Graphics.hpp>
#include "game.h"
#include "Card.h"
#include "LinkedList.h"
#include "Player.h"

/*

//Cargar los botones

Bool Game::loadButtons(const std::string& filepath, sf::Texture& texture) {

    If (!texture.loadFromFile(filepath)) {

        Return false;

    }

    Texture.setSmooth(true);

    Texture.setRepeated(false);

    Return true;

}



//Centrar los botones

Void Game::centerButton(sf::Sprite& button, sf::RenderWindow& window) {

    Button.setScale(sf::Vector2f(200.f / button.getLocalBounds().width, 120.f / button.getLocalBounds().height));

    Float posX = (window.getSize().x – button.getLocalBounds().width * button.getScale().x) / 2;

    Float posY = (window.getSize().y – button.getLocalBounds().height * button.getScale().y) / 2;

    Button.setPosition(posX, posY);

}

*/

void Game::createLobby() {

    sf::RenderWindow window;

    sf::Texture backgroundTexture;

    sf::Sprite backgroundSprite;



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



//Cargar la ventana  

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
    LinkedList cardList;
    int fps = 60;
    sf::Vector2u windowSize = window.getSize();
    backgroundSprite.setScale(
        windowSize.x / backgroundSprite.getLocalBounds().width,
        windowSize.y / backgroundSprite.getLocalBounds().height
    );
    window.setFramerateLimit(fps);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        sf::Color colorFondo(28, 211, 120);
        window.clear(colorFondo);
        window.draw(backgroundSprite);
        sf::Texture cardTexture1, cardTexture2, cardTexture3, cardTexture4, cardTexture5, cardTexture6;
        cardTexture1.loadFromFile("ResourseFiles/Diamond/LogoDiamond.jpg");
        cardTexture2.loadFromFile("ResourseFiles/Emerald/LogoEmerald.jpg");
        cardTexture3.loadFromFile("ResourseFiles/Fluorite/LogoFluorite.jpg");

        cardTexture4.loadFromFile("ResourseFiles/Diamond/LogoDiamond.jpg");
        cardTexture5.loadFromFile("ResourseFiles/Emerald/LogoEmerald.jpg");
        cardTexture6.loadFromFile("ResourseFiles/Fluorite/LogoFluorite.jpg");



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

        /*Agregar los sprites a la lista
        for (int i = 0; i < 6; i++)
        {
            for (int x = 1; x < 7; x++)
            {
                std::cout << "carta guardada! "<< i << std::endl;

            }
        }*/
        cardList.push_front(&card1);
        cardList.push_front(&card2);
        cardList.push_front(&card3);
        cardList.push_front(&card4);
        cardList.push_front(&card5);
        cardList.push_front(&card6);
        cardList.push_front(&card7);
        cardList.push_front(&card8);
        cardList.push_front(&card9);
        cardList.push_front(&card10);
        cardList.push_front(&card11);
        cardList.push_front(&card12);


        cardList.push_front(&card13);
        cardList.push_front(&card14);
        cardList.push_front(&card15);
        cardList.push_front(&card16);
        cardList.push_front(&card17);
        cardList.push_front(&card18);
        cardList.push_front(&card19);
        cardList.push_front(&card20);
        cardList.push_front(&card21);
        cardList.push_front(&card22);
        cardList.push_front(&card23);
        cardList.push_front(&card24);


        cardList.push_front(&card25);
        cardList.push_front(&card26);
        cardList.push_front(&card27);
        cardList.push_front(&card28);
        cardList.push_front(&card29);
        cardList.push_front(&card30);
        cardList.push_front(&card31);
        cardList.push_front(&card32);
        cardList.push_front(&card33);
        cardList.push_front(&card34);
        cardList.push_front(&card35);
        cardList.push_front(&card36);

        // Escalar los sprites a un tamaño más pequeño
        float scaleFactor = 0.5f;
        for (auto node = cardList.first; node != nullptr; node = node->next)
        {
            node->card->setScale(scaleFactor, scaleFactor);
        }

        // Calcular la posición x de cada carta
        float cardWidth = card1.getGlobalBounds().width * scaleFactor;
        float cardHigh = card1.getGlobalBounds().height * scaleFactor;
        float xPos = (window.getSize().x) / 2.446;
        float yPos = (window.getSize().y) / 2.35;
        // std::cout << xPos << std::endl;

         // Alinear las cartas horizontalmente
        int a = 0;
        for (auto node = cardList.first; node != nullptr; node = node->next)
        {
            node->card->setPosition(xPos, yPos);
            xPos += cardWidth * 2.1;
            if ((a + 1) % 3 == 0) {
                yPos += 3;
                xPos = (window.getSize().x) / 2.446;

            }
            a++;
        }

        // Dibujar las cartas en la ventana
        int i = 0;

        //std::random_shuffle(cardList.first, cardList.last);

        for (auto node = cardList.first; node != nullptr; node = node->next)
        {
            window.draw(*node->card);
            std::cout << "carta dibujada!" << node << std::endl;

        }

        //Prueba de nombre y puntos de la clase player
        Jugador jugador1("Jugador 1:", 10, 10);
        Jugador jugador2("Jugador 2:", 270, 10);
        jugador1.Dibujar(window);
        jugador2.Dibujar(window);
        //

        window.display();

        sf::sleep(sf::seconds(200));
    }

}

Game::Game() {

    createLobby();

}