#include "game_manager.h"

game_manager::game_manager()
{
	brick_texture.loadFromFile("brick.png");

	int total_bricks = BRICK_COLUMNS * BRICK_ROWS;

	for (int i, row, col = row = i = 0; i < total_bricks; i++)
	{
		if (col == BRICK_COLUMNS)
		{
			row++;
			col = 0;
		}
		bricks.push_back(brick(brick_texture, (BRICK_WIDTH * col) + BRICK_OFFSET, (BRICK_HEIGHT * row) + BRICK_HEIGHT));
		col++;
	}

	window.setFramerateLimit(60);
}

void game_manager::run()
{
	while (window.isOpen())
	{
		window.clear();

		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();

		}

		background.update();

		ball.update();

		paddle.manage_player_input();
		paddle.update();

		collision_manager.on_collision(ball, paddle);

		for (auto& brick : bricks)
			collision_manager.on_collision(ball, brick);

		bricks.erase(std::remove_if(std::begin(bricks), std::end(bricks),
			[](const brick& b) {return b.is_destroyed(); }), std::end(bricks));

		background.draw(window);
		ball.draw(window);
		paddle.draw(window);

		for (auto& brick : bricks)
			brick.draw(window);

		window.display();
	}
}
