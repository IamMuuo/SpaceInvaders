/******************************************************************
*   A game class to handle certain events and update the game
*   Filename: Game.hpp
*   Author: Erick Muuo
*   Email:  hearteric57@gmail.com
*   Copyright: (C) 2022 All rights reserved 
******************************************************************/
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Window.hpp>

struct Game
{
    private:
        sf::RenderWindow window;
        
        void update();  // update the game
        void processEvents();   // listen and process events
        void render();  // draw the game scenes
    public:
        Game();  // initialize the window

        void run();
};