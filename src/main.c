#include "../include/cub3D.h"

//* react to keypress and close
//* refresh every loop and stay in the loop.
int	main(int ac, char **av)
{
	t_game	game;

	if (ft_check_args(ac, av))
		return (0);
	if (ft_init_map(&game))
		return (0);
	if (ft_init_game(&game))
		return (0);
	mlx_hook(game.win_ptr, 17, (1L << 17), ft_close, &game);
	mlx_hook(game.win_ptr, 6, 1L << 6, &mouse, &game);
	mlx_hook(game.win_ptr, 2, (1L << 0), ft_key, &game);
	mlx_loop_hook(win.mlx_ptr, ft_refresh, &game);
	mlx_loop(win.mlx_ptr);
	return(0);
}
