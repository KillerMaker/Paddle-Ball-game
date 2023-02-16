#pragma once
#include"moving_game_object.h"
#include<vector>


class collision_manager final
{
public:
	bool check_for_collision(game_object& left, game_object& right) const noexcept;
	void on_collision(game_object& left, game_object& right);
};

