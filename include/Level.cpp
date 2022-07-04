
#include "Level.hpp"
#include "Global.hpp"
#include "Invader.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <cstdlib>
Level::Level()
{
    srand((int)time(NULL));
    numberOfInvaders = (rand() % 30) + MINIMUM_ENEMIES; // generate random number of enemies

    invaders = new Invader[numberOfInvaders];

    srand((int)time(nullptr));

    for(int i = 0; i < numberOfInvaders; i++)
    {
        invaders[i].setPosition(rand()%1250, -10) ;
        invaders[i].speed = (rand()%20) + 10;
    }
}

void Level::renderLevelInvaders(sf::RenderWindow& win)
{
    for(int i = 0; i < numberOfInvaders; i++)
    {
        win.draw(invaders[i].getDrawableInvader());
    }
}

Level::~Level()
{
    delete [] invaders;
}

void Level::moveInvaders(const sf::Vector2f &movement)
{
    for(int i = 0; i < numberOfInvaders; i++)
    {
        invaders[i].move(movement);
    }
}