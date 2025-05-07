#include "../include/cub3D.h"

int free_win(t_win *win)
{
	mlx_destroy_window((*win).mlx_ptr, (*win).win_ptr);
	// mlx_destroy_display((*win).mlx_ptr);
	free((*win).mlx_ptr);
	return(0);
}