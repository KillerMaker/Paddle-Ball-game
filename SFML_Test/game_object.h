#pragma once

#include<SFML/Graphics.hpp>
#include<exception>

#include"constants.h"

class game_object abstract
{
protected:
	sf::Sprite sprite;
	sf::Texture texture;

public:
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

	inline sf::Vector2<float> get_position() const noexcept { return sprite.getPosition(); }

	inline sf::FloatRect get_bounding_box() const noexcept { return sprite.getGlobalBounds(); }

	inline sf::Vector2<float> get_centre()const noexcept 
	{
		sf::FloatRect box = get_bounding_box();
		return sf::Vector2<float>(box.width / 2.0f, box.height / 2.0f);
	}

	inline float x() const noexcept { return sprite.getPosition().x; }
	inline float y() const noexcept { return sprite.getPosition().y; }

	virtual ~game_object(){}

	virtual void handle_collision(game_object& other) = 0;
};
