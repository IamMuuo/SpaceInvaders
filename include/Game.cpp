#include "Game.hpp"
#include "Global.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>


Game::Game()
: window(sf::VideoMode(WIDTH,HEIGHT), PROGRAM_NAME, sf::Style::Titlebar| sf::Style::Close)
{
    window.setFramerateLimit(MAXFRAME);
    health.font.loadFromFile(SANS_FONT_PATH);
    health.setText("Score!");
    health.setCharacterSize(20);
    health.setFont(health.font);
    health.setPosition(80, 20);
    healthLogoTexture.loadFromFile(HEALTHLOGO);
    healthLogoSprite.setTexture(healthLogoTexture);
    healthLogoSprite.setScale(0.2,0.2);
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
    window.draw(healthLogoSprite);
    window.draw(health.getDrawableText());
    window.draw(player.getDrawablePlayer());
    level.renderLevelInvaders(window);
    
    window.display();   //display the sprites into the current buffer
}

void Game::update(sf::Time deltaTime)
{
    // Update sprites frames etc
    sf::Vector2f movement(0.f,0.f);

    if(isMovingDown)
        movement.y += MAXFRAME;
    if(isMovingUp)
        movement.y -= MAXFRAME;
    if(isMovingLeft)
        movement.x -= MAXFRAME;
    if(isMovingRight)
        movement.x += MAXFRAME;

    player.move(movement*deltaTime.asSeconds());

    level.moveInvaders(sf::Vector2f(0.0f,0.01f));

    if(level.isLevelComplete())
    {
        level.nextLevel();
    }
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