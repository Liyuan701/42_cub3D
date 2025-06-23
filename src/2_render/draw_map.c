#include "../include/cub3D.h"

//copy map --> 0 or 1 or V
void draw_map(t_game *game, int size_square)
{
    t_pixel p;
    int x;
    int y;
    
    p.game = game;
    y = 0;
    while(game->cub->copy[y])
    {
        x = 0;
        while(game->cub->copy[y][x])
        {
            p.x = x * size_square;
            p.y = y * size_square;
            if (game->cub->copy[y][x] == '0')
            {
                draw_square(&p, size_square, game->config.floor);
            }
			else
				draw_square(&p, size_square, game->config.ceiling);
            x++;   
        }
        y++;
    }
}

bool is_wall(t_game *game, int x, int y)
{
	if (y < 0 || y >= game->cub->height 
		|| x < 0 || x >= (int)ft_strlen(game->cub->copy[y]))
        return (true);
	
	if (game->cub->copy[y][x] == '0')
		return (false);
	return (true);
}

// bool can_move(t_game *game, double x, double y)
// {
// 	if (y < 0 || y >= game->cub->height 
// 		|| x < 0 || x >= (int)ft_strlen(game->cub->copy[y]))
//         return (true);
	
// 	if (game->cub->copy[y][x] == '0')
// 		return (false);
// 	return (true);
// }