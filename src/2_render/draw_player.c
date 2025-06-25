#include "../include/cub3D.h"

void draw_player(t_game *game, int size, int color)
{
	t_pixel p;
	p.game = game;
	p.x = game->player->x;
	p.y = game->player->y;
	draw_square(&p, size, color);
}

void draw_player_mini(t_game *game, int size, int color)
{
    t_pixel p;

    p.game = game;
    p.x = game->player->x / game->map.size_square * game->map.size_square_mini;
    p.y = game->player->y / game->map.size_square * game->map.size_square_mini;
    draw_square(&p, size, color);
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
			if (game->cub->copy[y][x] == '0')//--> changer au strchr "NSEO"
			{
				game->player->x = x * game->size_square;
				game->player->y = y * game->size_square;
				player_set = true;
			}
			x++;
		}
		y++;
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
	// double move_speed = 1.0;
	double cos_angle = cos(player->angle);
    double sin_angle = sin(player->angle);
	double new_x;
	double new_y;

	// if (player->left_rotate)
    //     player->angle -= rotate_speed;
    // if (player->right_rotate)
    //     player->angle += rotate_speed;

	if (player->key_up == true)
	{
        new_x = player->x - cos_angle;
		new_y = player->y - sin_angle;
		if (is_wall(game, new_x, new_y) == false)
        {
            player->x = new_x;
            player->y = new_y;
        }
		else
        {
            int wall_y = new_y / game->map.size_square;
            player->y = (wall_y + 1) * game->map.size_square;
        }
	}
	if (player->key_down == true)
	{
        new_x = player->x + cos_angle;
		new_y = player->y + sin_angle;
		if (is_wall(game, new_x, new_y + game->map.size_square) == false)
        {
            player->x = new_x;
            player->y = new_y;
        }
		else
        {
            int wall_y = (new_y + game->map.size_square) / game->map.size_square;
            player->y = (wall_y - 1) * game->map.size_square;
        }
	}
		if (player->key_left == true)
	{
        new_x = player->x - sin_angle;
		new_y = player->y + cos_angle;
		if (is_wall(game, new_x, new_y) == false)
        {
            player->x = new_x;
            player->y = new_y;
        }
		else
        {
            int wall_x = new_x / game->map.size_square;
            player->x = (wall_x + 1) * game->map.size_square;
        }
	}
	if (player->key_right == true)
	{
        new_x = player->x + sin_angle;
		new_y = player->y - cos_angle ;
		if (is_wall(game, new_x + game->map.size_square, new_y) == false)
        {
            player->x = new_x;
            player->y = new_y;
        }
		else
        {
            int wall_x = (new_x + game->map.size_square) / game->map.size_square;
            player->x = (wall_x - 1) * game->map.size_square;
        }
	}
}
