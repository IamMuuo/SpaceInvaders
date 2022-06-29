/******************************************************************
*   A Text class to encapsulate functionality in the game
*   Filename: Text.hpp
*   Author: Erick Muuo
*   Email:  hearteric57@gmail.com
*   Copyright: (C) 2022 All rights reserved 
******************************************************************/

#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>


struct Text
{
    public:
        Text();
        Text(float x, float y, const sf::Font& font, const std::string& message);
        void setFont(const sf::Font& font); // set the font
        void setCharacterSize(float size);  // font size
        sf::Text& getDrawableText();    // get drawable sprite
        void setColor(const sf::Color& color);  // font color
        void setPosition(float x, float y); // set the position
        void setText(const std::string& message);   // set the message
    sf::Font font;

    private:


    sf::Text text;
};