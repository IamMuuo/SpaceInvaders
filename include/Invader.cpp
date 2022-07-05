#include "Invader.hpp"
#include "Global.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

Invader::Invader()
{
    invaderTexture.loadFromFile(INVADERTEXTURE1);
    invaderSprite.setTexture(invaderTexture);
    invaderSprite.setScale(0.3,0.3);
    invaderSprite.setRotation(180);
}
Invader::Invader(sf::Texture& texture)
{
    invaderSprite.setTexture(texture);
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

    if(invaderSprite.getPosition().y > HEIGHT)
        isActive = false;
    else
        isActive = true;
}

void Invader::setPosition(float x, float y)
{
    invaderSprite.setPosition(x,y);
}