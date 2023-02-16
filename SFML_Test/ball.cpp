#include "ball.h"

ball::ball(float px, float py,const char* textureSource)
{

	position = sf::Vector2<float>(px, py);
	velocity = sf::Vector2<float>(BALL_SPEED, BALL_SPEED);

	texture.loadFromFile(textureSource);
	sprite.setTexture(texture);

	sprite.setPosition(position);

}

void ball::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void ball::update()
{
	sprite.move(velocity);

	velocity.x = x() < 0 || x() > SCREEN_WIDTH ? velocity.x *= -1 : velocity.x;
	velocity.y = y() < 0 || y() > SCREEN_HEIGHT ? velocity.y *= -1 : velocity.y;
}

void ball::handle_collision(game_object& other)
{
	if (paddle* obj = dynamic_cast<paddle*>(&other))
	{
		float other_pos = obj->get_position().x;
		float other_centre = obj->get_centre().x;

		float this_centre = get_centre().x;

		move_up();

		if (position.x + this_centre < other_pos + other_centre)
			move_left();
		else if (position.x + this_centre > other_pos + other_centre)
			move_right();
	}
	if (brick* obj = dynamic_cast<brick*>(&other))
	{
		velocity.x *= -1;
		velocity.y *= -1;
	}
}

void ball::move_up() noexcept
{
	velocity.y = -BALL_SPEED;
}

void ball::move_left() noexcept
{
	velocity.x = -BALL_SPEED;
}

void ball::move_right() noexcept
{
	velocity.x = BALL_SPEED;
}
