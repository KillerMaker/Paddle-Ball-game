#include "collision_manager.h"

bool collision_manager::check_for_collision(game_object& left, game_object& right) const noexcept
{
	return left.get_bounding_box().intersects(right.get_bounding_box());
}

void collision_manager::on_collision(game_object& left, game_object& right)
{
	if (check_for_collision(left, right))
	{
		left.handle_collision(right);
		right.handle_collision(left);
	}
	
}




