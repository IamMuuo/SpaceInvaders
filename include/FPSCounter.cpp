#include "FPSCounter.hpp"
#include <SFML/Graphics/Color.hpp>
#include <sstream>

void FPSCounter::renderTo(sf::RenderWindow &win)
{
   win.draw(counterText.getDrawableText());
}

FPSCounter::FPSCounter(const std::string& message,const sf::Font& font)
: counterText( 1260, 0,font,message)
{
    counterText.setColor(sf::Color::White);
}

void FPSCounter::updateCounter()
{
    fpsTimer = fpsClock.getElapsedTime();
    std::stringstream ss;
    ss << "FPS: " << (1.0f / fpsTimer.asSeconds());
    counterText.setText(ss.str());
}