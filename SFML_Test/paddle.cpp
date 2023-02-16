#include "paddle.h"

paddle::paddle(const char* textureSource)
{
	texture.loadFromFile(textureSource);
	sprite.setTexture(texture);

	float x = SCREEN_WIDTH / 2 - get_bounding_box().width / 2;
	float y = (SCREEN_HEIGHT - get_bounding_box().height)-10;

	sprite.setPosition(x,y);
	this->velocity = sf::Vector2<float>(PADDLE_SPEED, 0);
}

void paddle::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void paddle::manage_player_input()
{
	if ((x() > 0 && x() < SCREEN_WIDTH - get_bounding_box().width))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			move_left();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			move_right();
		else
			velocity = { 0,0 };
	}
	else if (x() >= SCREEN_WIDTH - get_bounding_box().width)
		move_left();
	else if (x() <= 0)
		move_right();
}

void paddle::update()
{
	sprite.move(velocity);
}

void paddle::move_up() noexcept
{
	return;
}

void paddle::move_left() noexcept
{
	velocity.x = -PADDLE_SPEED;
}

void paddle::move_right() noexcept
{
	velocity.x = PADDLE_SPEED;
}

void paddle::move_down() noexcept
{
	return;
}




