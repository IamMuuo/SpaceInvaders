/******************************************************************
*   A player class to handle player functionality
*   Filename: Player.hpp
*   Author: Erick Muuo
*   Email:  hearteric57@gmail.com
*   Copyright: (C) 2022 All rights reserved 
******************************************************************/

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

#pragma once

struct Player
{
    private:
        sf::Texture playerTexture;
        sf::Sprite  playerSprite;

    public:
        int health;
        Player();
        sf::Sprite& getDrawablePlayer();
        void move(const sf::Vector2f& movement);
    
};