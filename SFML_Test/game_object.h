#pragma once

#include<SFML/Graphics.hpp>
#include<exception>

#include"constants.h"

class game_object abstract
{
protected:
	sf::Sprite sprite;
	sf::Texture texture;

	bool destroyed = false;

public:
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

	sf::Vector2<float> get_position() const noexcept;

	sf::FloatRect get_bounding_box() const noexcept;

	sf::Vector2<float> get_centre()const noexcept;
	

	float x() const noexcept;
	float y() const noexcept;

	virtual ~game_object(){}

	virtual void handle_collision(game_object& other) = 0;

	float left() const noexcept;
	float right() const noexcept;
	float top() const noexcept;
	float bottom() const noexcept;

	void destroy() noexcept;

	bool is_destroyed() const noexcept;
};
