#ifndef BALL_H
#define BALL_H

#include<random>
#include"moving_game_object.h"
#include"paddle.h"
#include "Brick.h"

class ball: public moving_game_object
{

public:
	ball(float px, float py, const char* textureSource = nullptr);

	void draw(sf::RenderWindow& window) override;

	void update() override;
	void handle_collision(game_object& other) override;

	virtual void move_up() noexcept override;
	virtual void move_left() noexcept override;
	virtual void move_right() noexcept override;

};
#endif // !BALL_H

