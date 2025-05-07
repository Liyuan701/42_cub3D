#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h> //perrer
#include <errno.h> //errno(use for perrer)
#include <stdlib.h> //exit, EXIT_FAILURE, EXIT_SUCCESS
#include <fcntl.h> // O_RDONLY
#include <unistd.h>  // open, read, write
#include <X11/keysym.h>
# include <math.h>
// # include "../libft/libft.h"
# include "../minilibx-opengl/mlx.h"
// # include "../minilibx-linux/mlx.h"


# define WIDTH		1000
# define HEIGHT		800






typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;

}	t_win;

//util
void error_msg(char *str, int exit_status);

//free
int free_win(t_win *win);

//key
int	key(int key, void* param);
















#endif
