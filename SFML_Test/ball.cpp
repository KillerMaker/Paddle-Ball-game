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
		move_up();

		if (x()<other.x())
			move_left();
		else
			move_right();
	}
	if (brick* obj = dynamic_cast<brick*>(&other))
	{
		float left_overlap = right() - other.left();
		float right_overlap = left() - other.right();
		float top_overlap = bottom() - other.top();
		float bottom_overlap = top() - other.bottom();

		if (left_overlap < right_overlap)
			move_left();
		else if (right_overlap < left_overlap)
			move_right();

		if (top_overlap < bottom_overlap)
			move_up();
		else if (bottom_overlap < top_overlap)
			move_down();

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

void ball::move_down() noexcept
{
	velocity.y = BALL_SPEED;
}
