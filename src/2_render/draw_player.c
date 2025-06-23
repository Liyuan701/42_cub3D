#include "../include/cub3D.h"

void draw_player(t_game *game, int size)
{
    t_pixel p;

    p.game = game;
    p.x = game->player->x;
    p.y = game->player->y;
    draw_square(&p, size, game->player->color);
}

void set_player_angle(t_game *game)
{
	int x;
	int y;

	y = 0;
	while(game->cub->map[y])
	{
		x = 0;
		while(game->cub->map[y][x])
		{
			if (game->cub->map[y][x] == 'N')
				game->player->angle = PI / 2;
            else if (game->cub->map[y][x] == 'S')
				game->player->angle = 3 * PI / 2;
            else if (game->cub->map[y][x] == 'E')
				game->player->angle = 0;
            else if (game->cub->map[y][x] == 'W')
				game->player->angle = PI;
			x++;
		}
		y++;
	}
}

void set_player_start_pos(t_game *game)
{
	int x;
	int y;
	bool	player_set;

	y = 0;
	player_set = false;
	while(game->cub->copy[y] && player_set == false)
	{
		x = 0;
		while(game->cub->copy[y][x] && player_set == false)
		{
			if (is_wall(game, x, y) == false)
			{
				game->player->x = x * game->size_square;
				game->player->y = y * game->size_square;
				player_set = true;
			}
			x++;
		}
		y++;
	}
	if (!player_set) 
	{
        game->player->x = game->cub->width / 2 * game->size_square;
        game->player->y = game->cub->height / 2 * game->size_square;
    }
}

void set_player(t_game *game)
{
	game->player->key_up = false;
    game->player->key_down = false;
    game->player->key_right = false;
    game->player->key_left = false;
	// player->left_rotate = false;
    // player->right_rotate = false;

	set_player_start_pos(game);
	set_player_angle(game);
}

void move_player(t_game *game, t_player *player)
{
	double move_speed = 2.0;
	double cos_angle = cos(player->angle);
    double sin_angle = sin(player->angle);
	// double new_x;
	// double new_y;
	
	// if (player->left_rotate)
    //     player->angle -= rotate_speed;
    // if (player->right_rotate)
    //     player->angle += rotate_speed;
	
	if (player->angle > 2 * PI)
        player->angle = 0;
    if (player->angle < 0)
        player->angle = 2 * PI;
    
	if (player->key_up == true)
	{
        player->x -= cos_angle * move_speed;
		player->y -= sin_angle * move_speed;
		// if (is_wall(game, new_x, new_y) == true)
        // {
        //     player->x = new_x;
        //     player->y = new_y;
        // }
	}
	if (player->key_down == true)
	{
        player->x += cos_angle * move_speed;
		player->y += sin_angle * move_speed;
	}
		if (player->key_left == true)
	{
        player->x -= sin_angle * move_speed;
		player->y += cos_angle * move_speed;
	}
	if (player->key_right == true)
	{
        player->x += sin_angle * move_speed;
		player->y -= cos_angle  * move_speed;
	}
}

// void move_player_dir(t_player *player, double cos_angle, double sin_angle, double move_speed)
// {
// 	if (player->key_up == true)
// 	{
//         player->x -= cos_angle * move_speed;
// 		player->y -= sin_angle * move_speed;
// 	}
// }