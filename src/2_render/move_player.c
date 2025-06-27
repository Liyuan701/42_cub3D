#include "../include/cub3D.h"

void	mov_player_up(t_game *game, double new_x, double new_y)
{
	if (game->player->key_up == true)
	{
		new_x = game->player->x - game->move.cos_angle;
		new_y = game->player->y - game->move.sin_angle;
		if (is_wall(game, new_x, new_y) == false
			&& is_wall(game, new_x + game->move.size_player, new_y) == false)
		{
			game->player->x = new_x;
			game->player->y = new_y;
		}
	}
}

void	mov_player_down(t_game *game, double new_x, double new_y)
{
	if (game->player->key_down == true)
	{
		new_x = game->player->x + game->move.cos_angle;
		new_y = game->player->y + game->move.sin_angle;
		if (is_wall(game, new_x, new_y) == false
			&& is_wall(game, new_x + game->move.size_player,
				new_y + game->move.size_player) == false)
		{
			game->player->x = new_x;
			game->player->y = new_y;
		}
	}
}

void	mov_player_left(t_game *game, double new_x, double new_y)
{
	if (game->player->key_left == true)
	{
		new_x = game->player->x - game->move.sin_angle;
		new_y = game->player->y + game->move.cos_angle;
		if (is_wall(game, new_x, new_y) == false
			&& is_wall(game, new_x, new_y + game->move.size_player) == false)
		{
			game->player->x = new_x;
			game->player->y = new_y;
		}
	}
}

void	mov_player_right(t_game *game, double new_x, double new_y)
{
	if (game->player->key_right == true)
	{
		new_x = game->player->x + game->move.sin_angle;
		new_y = game->player->y - game->move.cos_angle ;
		if (is_wall(game, new_x + game->move.size_player, new_y) == false
			&& is_wall(game, new_x + game->move.size_player,
				new_y + game->move.size_player) == false)
		{
			game->player->x = new_x;
			game->player->y = new_y;
		}
	}
}

void	move_player(t_game *game, double size_square)
{
	// game->move.speed = 1.0;
	game->move.cos_angle = cos(game->player->angle);
	game->move.sin_angle = sin(game->player->angle);
	game->move.size_player = size_square / 2;

	// if (player->left_rotate)
	//     player->angle -= rotate_speed;
	// if (player->right_rotate)
	//     player->angle += rotate_speed;

	mov_player_up(game, game->move.new_x, game->move.new_y);
	mov_player_down(game, game->move.new_x, game->move.new_y);
	mov_player_left(game, game->move.new_x, game->move.new_y);
	mov_player_right(game, game->move.new_x, game->move.new_y);
}
