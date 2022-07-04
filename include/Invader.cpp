#include "Invader.hpp"
#include "Global.hpp"
#include <SFML/Graphics/Sprite.hpp>

Invader::Invader()
{
    invaderTexture.loadFromFile(INVADERTEXTURE1);
    invaderSprite.setTexture(invaderTexture);
    invaderSprite.setScale(0.3,0.3);
}

const sf::Sprite& Invader::getDrawableInvader()
{
    return this->invaderSprite;
}

void Invader::setInvader(const sf::Texture &newTexture)
{
    // set a new texture
    this->invaderSprite.setTexture(newTexture);
}

void Invader::move(const sf::Vector2f &movement)
{
    this->invaderSprite.move(movement * speed); // move the invader
}