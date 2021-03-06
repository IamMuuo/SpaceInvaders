/******************************************************
Filename: Invaders.hpp

Contains a class to manage an ivading alien
******************************************************/

#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
struct Invader
{
    private:
        sf::Texture invaderTexture;
        sf::Sprite invaderSprite;

    public:
        bool isActive = false;  // check if the invader is on screen
        int health = 100;
        float speed = 0.01f;
        Invader();  // initialize the sprite and texture
        Invader(sf::Texture& texture);
        void setPosition(float x, float y);
        const sf::Sprite& getDrawableInvader(); // return a drawable sprite.
        void setInvader(const sf::Texture& newTexture); // set a new texture for a new level
        void move(const sf::Vector2f& movement);    // move 


};