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

####################  KEYS #####################################
# define KEY_A 0x0061
# define KEY_W 0x0077
# define KEY_S 0x0073
# define KEY_D 0x0064
# define ESC 0x00ff1b
# define LEFT 0x00ff51
# define RIGHT 0x00ff53


#################### SET  ########################################
# define WIDTH		640
# define HEIGHT		480

# define PARSE	101
# define GAME	102

#define RED "\033[31m"
#define RESET "\033[0m"


##################### PERSO ######################################

# define FAIL 1


typedef struct s_track
{
	void			*ptr;
	struct s_track	*next;
}	t_track;

typedef struct s_player
{
	double	x;
	double	y;
	int		color;
	int		forward;
	int		turn;
}	t_player;

typedef struct s_tex
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
	int		f_color;
	int		c_color;
}	t_tex;

typedef struct s_map
{
	int		fd;
	int		line; //nb de ligne du contenu
	char	**text; //tous les contenus du .cub
	char	**map;
	int		width;
	int		height;
	int		end;
	int		end_config;
}	t_map;

//* Here I stcok all info of this game.
typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		status;
	int		width;
	int		height;
	t_track	*head;
	t_map	*map;
	t_tex	*tex;
	t_play	*player;
}	t_game;

##################### PARSE ######################################

##################### RENDER #####################################

##################### UTILS ######################################

#endif
