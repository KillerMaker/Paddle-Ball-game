#pragma once
class playable_game_object abstract
{
	public:
		virtual void manage_player_input() = 0;
};