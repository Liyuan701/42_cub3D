#include "../include/cub3D.h"

//TODO This page we will control the movement of player
//TODO Left/right trun, others move.

int	ft_key(int code, t_game	*game)
{
	if (keycode == KEY_A)
		vars->player->forward = -1;
	else if (keycode == KEY_S)
		vars->player->forward = -1;
	else if (keycode == KEY_D)
		vars->player->forwaed = +1;
	else if (keycode == KEY_W)
		vars->player->forward = +1;
	else if (keycode == RIGHT)
		vars->player->turn = +1;
	else if (keycode == LEFT)
		vars->player->turn = -1;
	else if (keycode == ESC)
		return (ft_clean(game));
	return (ft_move(code, game));
}
