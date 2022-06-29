/******************************************************************
*   A game class to handle certain events and update the game
*   Filename: Game.hpp
*   Author: Erick Muuo
*   Email:  hearteric57@gmail.com
*   Copyright: (C) 2022 All rights reserved 
******************************************************************/
#pragma once

#include "Player.hpp"
#include "Text.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Window.hpp>

struct Game
{
    private:
        sf::RenderWindow window;
        Player player;
        Text health;
        // moving flags
        bool isMovingDown = false,
        isMovingUp = false,
        isMovingRight = false,
        isMovingLeft = false;

        void handlePlayerInput(sf::Keyboard::Key& key, bool isPressed);        
        void update(sf::Time deltaTime);  // update the game
        void processEvents();   // listen and process events
        void render();  // draw the game scenes

    public:
        Game();  // initialize the window

        void run();
};