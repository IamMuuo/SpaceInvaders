#include "Game.hpp"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>


Game::Game()
: window(sf::VideoMode(800,600), "Space Invaders!", sf::Style::Titlebar| sf::Style::Close)
{
    ;
}

void Game::processEvents()
{
    //  Handles the player input
    sf::Event event;

    while (window.pollEvent(event)) {
        if(event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::render()
{
    //  Draw the game sprites
    window.clear(); // clear the last frame

    window.display();   //display the sprites into the current buffer
}

void Game::update()
{
    // Update sprites frames etc
    ;
}
void Game::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}