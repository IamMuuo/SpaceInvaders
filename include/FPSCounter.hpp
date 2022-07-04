/******************************************************************
*   A FPS Counter
*   Filename: FPSCounter.hpp
*   Author: Erick Muuo
*   Email:  hearteric57@gmail.com
*   Copyright: (C) 2022 All rights reserved 
******************************************************************/

#pragma once

#include "Text.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

struct FPSCounter
{
    private:
    sf::Font counterFont;
    Text counterText;
    sf::Clock fpsClock;
    sf::Time fpsTimer;


    public:
    FPSCounter(const std::string& message,const sf::Font& font);
    void renderTo(sf::RenderWindow& win);
    void updateCounter();

};