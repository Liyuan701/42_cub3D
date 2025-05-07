#include "../include/cub3D.h"

// void	key_move(int key, t_win *win)
// {
// 	if (key == XK_Left)
// 		(*win).offset_x -= 50;	
// 	else if (key == XK_Right)
// 		(*win).offset_x += 50;	
// 	else if (key == XK_Up)
// 		(*win).offset_y -= 50;	
// 	else if (key == XK_Down)
// 		(*win).offset_y += 50;	
// }

int	key(int key, void *param)
{
	(void)key;
	(void)param;
	// t_win *win;

	// win = (t_win*)param;
	// if (key == XK_Escape)
	// {
		// free_win(win);
	// 	exit(EXIT_SUCCESS);
	// }
	// else if (key == XK_Left || key == XK_Right || key == XK_Up || key == XK_Down)
		// key_move(key, win);
	return (0);
}
