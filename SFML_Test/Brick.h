#pragma once
#include "game_object.h"
#include "ball.h"

class brick : public game_object
{
	static sf::Texture brick_texture;
public:
	brick(const sf::Texture& brick_texture, float x, float y);
	void handle_collision(game_object& other) override;
	void update() override;
	void draw(sf::RenderWindow& window) override;
};

