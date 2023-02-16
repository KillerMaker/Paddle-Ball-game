#include "background.h"

background::background(float x, float y, const char* textureSource)
{
	texture.loadFromFile(textureSource);
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}

void background::update()
{
}

void background::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
