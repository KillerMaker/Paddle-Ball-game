#pragma once
#include"game_object.h"

class moving_game_object abstract : public game_object
{
protected:
	sf::Vector2<float> velocity;
	sf::Vector2<float> position;

	virtual void move_up() noexcept = 0;
	virtual void move_left() noexcept = 0;
	virtual void move_right() noexcept = 0;
	virtual void move_down()noexcept = 0;
};