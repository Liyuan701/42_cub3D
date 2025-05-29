#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h> //perrer
#include <errno.h> //errno(use for perrer)
#include <stdlib.h> //exit, EXIT_FAILURE, EXIT_SUCCESS
#include <fcntl.h> // O_RDONLY
#include <unistd.h>  // open, read, write
#include <stdbool.h> //bool
#include <X11/keysym.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx-opengl/mlx.h"
# include "../minilibx-linux/mlx.h"

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
	char	dir;
	int		dir_x;
	int		dir_y;
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
}	t_tex;

//* nl is the nb of lines.
//* text is a copy of contenus of .cub
typedef struct s_cub
{
	int		nl;
	int		op_fd;
	char	**text;
	char	**map;
	char	**copy;
	int		width;
	int		height;
	int		start;
}	t_cub;

//*for color :0xRRGGBB
typedef struct s_config
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor;
	int		ceiling;
}   t_config;

//* Here I stcok all info of this game.
typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			status;
	int			width;
	int			height;
	t_track		*head;
	t_cub		*cub;
	t_tex		*tex;
	t_player	*player;
	t_config	config;
}	t_game;

##################### PARSE ######################################

##################### RENDER #####################################
int		ft_key(int keycode, t_game	*game);
void	ft_refresh(void);

##################### UTILS ######################################
void	ft_close(t_game *game);
#endif
