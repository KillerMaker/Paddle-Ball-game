#include "Brick.h"


brick::brick(const sf::Texture& brick_texture, float x, float y)
{
	sprite.setTexture(brick_texture);
	sprite.setPosition(x, y);
}

void brick::handle_collision(game_object& other)
{
	if (ball* obj = dynamic_cast<ball*>(&other))
		destroy();

}

void brick::update()
{

}

void brick::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
