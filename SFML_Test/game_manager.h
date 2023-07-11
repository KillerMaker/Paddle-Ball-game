#pragma once

#include <SFML/Graphics.hpp>

#include"collision_manager.h"
#include "background.h"
#include"ball.h"
#include "paddle.h"
#include "Brick.h"

class game_manager
{
private:
	sf::RenderWindow window{ sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Ball and paddle game" };
	collision_manager collision_manager;
	sf::Texture brick_texture;

	ball ball{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, "ball.png" };
	paddle paddle{ "paddle.png" };
	background background{ 0.0f, 0.0f, "background.jpg" };
	std::vector<brick> bricks;

public:
	game_manager();
	void run();
	
};

