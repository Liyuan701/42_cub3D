# ------------------------------------- VARIABLES -------------------------------------
NAME        = cub3D
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INCLUDES    = -Iinclude -Ilib/minilibx-opengl -Ilib/libft -I/opt/X11/include

LIBFT_DIR   = lib/libft
LIBFT_LIB   = $(LIBFT_DIR)/libft.a

MLX_DIR     = lib/minilibx-opengl
MLX_LIB     = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -lm

SRC_DIR     = src
OBJ_DIR     = obj

PARSE_SRC   = \
		1_parse/parse.c\
		1_parse/init_game.c\
		1_parse/get_map.c\
		1_parse/check_map.c\
		1_parse/flood_map.c\
		1_parse/get_config.c\
		1_parse/check_config.c

RENDER_SRC  = 2_render/refresh.c\
		2_render/ray.c\
		2_render/key.c\
		2_render/cast.c\
		2_render/draw_ray.c\
		2_render/draw_map.c\
		2_render/draw_pixel.c\
		2_render/draw_player.c\
		2_render/move_player.c\

UTILS_SRC   = 3_utils/clean.c \
		3_utils/count.c \
		3_utils/config_util.c \
		3_utils/config_util2.c \
		3_utils/debug.c \
		3_utils/error.c \
		3_utils/mylloc.c \

MAIN_SRC    = main.c

SRCS        = $(addprefix $(SRC_DIR)/, $(PARSE_SRC) $(RENDER_SRC) $(UTILS_SRC)) \
              $(SRC_DIR)/$(MAIN_SRC)

OBJS        = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

# ------------------------------------- RULES -------------------------------------
all: $(NAME)

$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJS)
	$(CC) $(INCLUDES) $(OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(INCLUDES) -c $< -o $@

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re