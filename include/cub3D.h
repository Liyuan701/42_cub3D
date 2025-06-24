/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yy <yy@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:42:55 by lifan             #+#    #+#             */
/*   Updated: 2025/06/24 23:17:24 by yy               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h> //perrer
# include <errno.h> //errno(use for perrer)
# include <stdlib.h> //exit, EXIT_FAILURE, EXIT_SUCCESS
# include <fcntl.h> // O_RDONLY
# include <unistd.h>  // open, read, write，access
# include <stdbool.h> //bool
# include <math.h>
# include "../libft/libft.h"
// # include <X11/keysym.h>
// # include "../minilibx-opengl/mlx.h"
// # include "../lib/minilibx-linux/mlx.h"

//####################  KEYS #####################################
# define KEY_A 0x0061
# define KEY_W 0x0077
# define KEY_S 0x0073
# define KEY_D 0x0064
# define ESC 0x00ff1b
# define LEFT 0x00ff51
# define RIGHT 0x00ff53

//#################### SET  ########################################
# define WIDTH		640
# define HEIGHT		480
# define BLOCK		64

# define FOV	(PI/3) //60
# define PI		3.14159265358979323846

# define PARSE	101
# define GAME	102

# define RAY 0xC8A0FF
# define RED "\033[31m"
# define RESET "\033[0m"

# define PROPORTIONAL 2


//##################### PERSO ######################################

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
	double	angle;
	char	dir;
	int		color;
	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;
	// bool	left_rotate;
	// bool	right_rotate;

}	t_player;

typedef struct s_tex
{
	void	*img;
	char	*data;
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
	int		end_config;
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
	int		seen[6];
	int		index;
	// int		last_index;
	int		r;
	int		g;
	int		b;
	int		count;
}	t_config;


typedef	struct	s_ray
{
	double  vector_x;
    double  vector_y;
    double  ray_x;
    double  ray_y;
    int     map_x;
    int     map_y;
	double	d_x;
	double	d_y;
	double	side_x;
	double	side_y;
	int		step_x;
	int		step_y;
	int		hit_side;
	double	hit_x;
	double	hit_y;
}	t_ray;

typedef struct s_wall
{
	t_tex *tex;
    int wall_height;
    int start_y;
    int end_y;
    int tex_x;
    int tex_y;
    int color;
    int draw_y;
}	t_wall;

typedef struct s_map
{
	double size_square;
	double size_square_mini;
}	t_map;

//* Here I stcok all info of this game.
typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			status;
	int			width;
	int			height;
	int			size_line;
	t_track		*head;
	t_cub		*cub;
	t_tex		*tex;
	t_tex		tex_n;
	t_tex		tex_s;
	t_tex		tex_e;
	t_tex		tex_w;
	t_player	*player;
	t_config	config;
	t_ray		ray;
	t_wall		wall;
	t_map		map;
}	t_game;

typedef struct s_pixel
{
	t_game *game;
	int		x;
	int		y;

}	t_pixel;

//##################### PARSE ######################################
//check config
void	check_xpm_exit(t_game *game, char *line);
int		check_parse_color(t_game *game, char *line);
int		is_config_index(char *str);
void	check_config_line(t_game *game, t_config *c, char *line);
void	check_config(t_game *game, t_config *c);

//check map
int		ft_check_map(t_game *game, char **map);

//flood map
void	ft_flood_map(t_game *game, char **map);

//get config
int		get_start(char *line);
char	*mylloc_strdup(t_game *game, const char *src);
char	*mylloc_value(t_game *game, char *line);
void	get_index_value(char *line, t_game *game);
void	ft_get_config(t_game *game);

//get map
int		ft_get_map(t_game *game);
int		ft_find_start(t_game *game, char **text, int i);

//init game
void	ft_init_game(t_game *game);

//parse
int		ft_parse(t_game *game, char *file);

//##################### RENDER #####################################

//draw_map
void	draw_map(t_game *game, int size_square);
bool	is_wall(t_game *game, int x, int y);
void	set_map_size(t_game *game);

//draw_pixel
void	put_pixel(t_game *game, int x, int y, int color);
void	clear_image(t_game *game);
void	draw_square(t_pixel *p, int size, int color);

//draw player
void	set_player_start_pos(t_game *game);
void	set_player_angle(t_game *game);
void	set_player(t_game *game);
void	draw_player(t_game *game, int size);
void	move_player(t_game *game, t_player *player);


//refresh
void	ft_init_window(t_game *game);
void	ft_refresh(void	*param);
void	ft_render(t_game *game);
int		ft_load_tex(t_game	*game);
int		load_texture(void *mlx_ptr, char *path, t_tex *tex);
int		ft_load_tex(t_game	*game);


//key
int	ft_key_release(int keycode, t_game *game);
int	ft_key_press(int keycode, t_game *game);

//ray & cast
void	ft_cast_wall(t_game *game, double distance, int column, char side);
int		get_tex_color(t_tex *tex, int x, int y);
int		calculate_tex_x(t_game *game, t_tex *tex, double dist);
t_tex   *ft_select_wall(t_game *game, char wall);
char    hit_wall(t_ray *ray);
void	ft_init_ray(t_game *game, t_player *player);
bool	ft_if_encounter(t_game *game);
double  ft_distance(t_game *game);
double  ft_cali_fisheye(t_game *game, t_player *player);
int		ft_draw_ray(t_game *game, t_player *player, float angle, int column);


//##################### UTILS ######################################
//config util
void	init_seen(int seen[6]);
int		str_is_digit(char *s);
int		ft_isspace(char c);
int		ft_str_isspace(char *str);

//config util
char 	*replace_space(char *line);
void	free2tab_exit(t_game *game, char **tab1, char **tab2, char *error_msg);

//clean
int		ft_free_one(t_game *game, void *ptr);
void	ft_free_all(t_game *game);
void	ft_free_tab(char **tab);
void	ft_free_all_tex(t_game *game);
void	free_texture(void *mlx_ptr, t_tex *tex);
void	ft_clean(t_game	*game);

//count
int		ft_count_lines(t_game *game, char *file);
void	ft_count_width(t_game *game, int height, int start);
int		ft_find(char c, char *str);

//error
void	ft_error(char *str);
void	ft_error_close(t_game *game, char *str);
void	ft_close(t_game *game);

//mylloc
void	*ft_mylloc(t_game *game, size_t size);
//##################### DEBUGS ######################################

int		ft_debug_parse(t_game *game);
int		print_config(t_config *cfg);
int		print_cub(t_cub *c);
int		print_player(t_player *p);
void	print_map(char **map);
void	ft_draw_line(t_game *game, int x0, int y0, int x1, int y1, int color);
void	ft_draw_ray_line(t_game *game);


#endif
