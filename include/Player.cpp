#include "Player.hpp"
#include "Global.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

Player::Player()
{
    // initialize the player state
    playerTexture.loadFromFile(PLAYERTEXTURE);
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(640,750);
    playerSprite.setScale(0.3,0.3);
}

sf::Sprite& Player::getDrawablePlayer()
{
    // returns a rendable player
    return playerSprite;
}

void Player::move(const sf::Vector2f& movement)
{
    // bounds checking
    playerSprite.move(movement);
}