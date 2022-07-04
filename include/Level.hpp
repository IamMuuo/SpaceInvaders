/**************************************************************
A level class to anage level utility
**************************************************************/

#pragma once

#include "Invader.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

struct Level 
{
    Invader* invaders;
    bool isClear = false;
    int numberOfInvaders = 0;

    Level();
    void nextLevel();
    void renderLevelInvaders(sf::RenderWindow& win);
    void moveInvaders(const sf::Vector2f &movement);
    ~Level();
};