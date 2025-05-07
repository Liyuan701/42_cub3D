#include "../include/cub3D.h"

void open_window(t_win *win, char *win_name)
{
	(*win).mlx_ptr = mlx_init();
	if ((*win).mlx_ptr == NULL)
		error_msg("Error init MLX", EXIT_FAILURE);

	(*win).win_ptr = mlx_new_window((*win).mlx_ptr, WIDTH, HEIGHT, win_name);
	if ((*win).win_ptr == NULL)
		error_msg("Error init WIN", EXIT_FAILURE);
}

//mlx_hook --> cliquer x sur la fenetre pour fermer
//mlx_key_hook --> "esc" pour fermer la fenetre
int	main(int ac, char **av)
{
	int fd;
	t_win win;

	if (ac != 2)
		error_msg("Usage: ./cub3D source_file", EXIT_FAILURE);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_msg("Error opening file", EXIT_FAILURE);
	//check map
	//get map
	open_window(&win, "my map");
	//...
	mlx_hook(win.win_ptr, 17, 0, free_win, (void *)&win);
	mlx_key_hook(win.win_ptr, key, (void*)&win);
    mlx_loop(win.mlx_ptr);
	return(0);
}