#include "Game.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>


Game::Game()
: window(sf::VideoMode(800,600), "Space Invaders!", sf::Style::Titlebar| sf::Style::Close)
{
    if(!playerTexture.loadFromFile("/home/erick/Documents/SpaceInvaders/Assets/Sprites/Eagle.png"))
    {
        // Handle player
    }

    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(100.f,100.f);
}

void Game::processEvents()
{
    //  Handles the player input
    sf::Event event;

    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code,false);
                break;
            
            case sf::Event::Closed:
                window.close();
                break;

            default:
                ;   // Explicitly done to silence the compiler
                    // warning emmited
        }
    }
}

void Game::render()
{
    //  Draw the game sprites
    window.clear(); // clear the last frame
    window.draw(playerSprite);
    window.display();   //display the sprites into the current buffer
}

void Game::update(sf::Time deltaTime)
{
    // Update sprites frames etc
    sf::Vector2f movement(0.f,0.f);

    if(isMovingDown)
        movement.y += 100.f;
    if(isMovingUp)
        movement.y -= 100.f;
    if(isMovingLeft)
        movement.x -= 100.f;
    if(isMovingRight)
        movement.x += 100.f;
    
    playerSprite.move(movement * deltaTime.asSeconds());
}
void Game::run()
{
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key& key, bool isPressed)
{
    // handle player input

    if(key == sf::Keyboard::W)
        isMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        isMovingDown = isPressed;
    else if (key == sf::Keyboard::A)
        isMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        isMovingRight = isPressed;
}
