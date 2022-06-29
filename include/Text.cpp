#include "Text.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Text.hpp>

Text::Text()
{
    ;
}
Text::Text(float x, float y, const sf::Font& font, const std::string& message)
{
    this->text.setPosition(x,y);
    this->text.setFont(font);
    this->text.setString(message);
    this->setColor(sf::Color::Green);
}

sf::Text& Text::getDrawableText()
{
    return this->text;
}

void Text::setCharacterSize(float size)
{
    this->text.setCharacterSize(size);
}

void Text::setColor(const sf::Color &color)
{
    this->text.setFillColor(color);
}

void Text::setText(const std::string &message)
{
    this->text.setString(message);
}

void Text::setPosition(float x, float y)
{
    this->text.setPosition(x,y);
}

void Text::setFont(const sf::Font &font)
{
    this->text.setFont(font);
}