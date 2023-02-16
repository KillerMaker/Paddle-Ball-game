#include "game_object.h"

sf::Vector2<float> game_object::get_position() const noexcept
{
    return sprite.getPosition();
}

sf::FloatRect game_object::get_bounding_box() const noexcept
{
    return sprite.getGlobalBounds();
}

sf::Vector2<float> game_object::get_centre() const noexcept
{
    sf::FloatRect box = get_bounding_box();
    return sf::Vector2<float>(box.width / 2.0f, box.height / 2.0f);
}



float game_object::x() const noexcept
{
    return sprite.getPosition().x;
}

float game_object::y() const noexcept
{
    return sprite.getPosition().y;
}



float game_object::left() const noexcept
{
    return x() - get_bounding_box().width / 2.0f;
}

float game_object::right() const noexcept
{
    return x() + get_bounding_box().width / 2.0f;
}

float game_object::top() const noexcept
{
    return y() - get_bounding_box().height / 2.0f;
}

float game_object::bottom() const noexcept
{
    return y() + get_bounding_box().height / 2.0f;
}



void game_object::destroy() noexcept
{
    destroyed = true;
}

bool game_object::is_destroyed() const noexcept
{
    return destroyed;
}
