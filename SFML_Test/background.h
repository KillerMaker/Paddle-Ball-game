#ifndef BACKGROUND_H
#define BACKGROUND_H

#include"game_object.h"

class background: public game_object
{
public:
	background(float x, float y, const char* textureSource);

	void update() override;
	void draw(sf::RenderWindow& window) override;
	void handle_collision(game_object& other) override { throw std::exception("A collision handler for this object is not yet implemented");}
}; 

#endif // BACKGROUND_H

