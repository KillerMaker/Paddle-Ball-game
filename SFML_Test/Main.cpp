#include <SFML/Graphics.hpp>

#include"collision_manager.h"
#include "background.h"
#include"ball.h"
#include "paddle.h"
#include "Brick.h"

int main()
{
    collision_manager collision_manager;
    background background(0.0f, 0.0f, "background.jpg");
    ball ball(SCREEN_WIDTH/2, SCREEN_HEIGHT/2,"ball.png");
    paddle paddle("paddle.png");

    int total_bricks = BRICK_COLUMNS * BRICK_ROWS;
    std::vector<brick> bricks;

    sf::Texture brick_texture;
    brick_texture.loadFromFile("brick.png");

    for (int i ,row, col = row = i = 0; i < total_bricks; i++)
    {
        if (col == BRICK_COLUMNS)
        {
            row++;
            col = 0;
        }
        bricks.push_back(brick(brick_texture, (BRICK_WIDTH * col)+BRICK_OFFSET, (BRICK_HEIGHT * row) + BRICK_HEIGHT));
        col++;
    }
       

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Random Ball");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        window.clear();

        sf::Event event;

        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        background.update();
        ball.update();

        paddle.manage_player_input();
        paddle.update();

        collision_manager.on_collision(ball, paddle);

        for (int i=0; i<total_bricks;i++)
        {
            if(collision_manager.check_for_collision(bricks[i], ball))
                bricks.erase(bricks.begin() + i);
        }

        background.draw(window);
        ball.draw(window);
        paddle.draw(window);

        for (auto& brick : bricks)
            brick.draw(window);

        window.display();
    }

    return 0;
}