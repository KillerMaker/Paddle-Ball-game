#pragma once

#include "moving_game_object.h"
#include "playable_game_object.h"

class paddle : public moving_game_object, public playable_game_object
{
public:
	paddle(const char* textureSource);
	void draw(sf::RenderWindow& window) override;
	void update() override;
	void handle_collision(game_object& other) override { return; }
	virtual void move_up() noexcept override;
	virtual void move_left() noexcept override;
	virtual void move_right() noexcept override;
	virtual void manage_player_input() override;

};