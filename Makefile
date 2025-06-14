# ##################################### VARIABLES ###################################
NAME        = cub3D
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INCLUDES    = -Iinclude -Ilib/minilibx-opengl -Ilib/libft -I/opt/X11/include

LIBFT_DIR   = lib/libft
LIBFT_LIB   = $(LIBFT_DIR)/libft.a

MLX_DIR     = lib/minilibx-opengl
MLX_LIB     = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -L/opt/X11/lib -lX11 -lXext \
              -framework OpenGL -framework AppKit -lm

SRC_DIR     = src
PARSE_DIR   = $(SRC_DIR)/1_parse
RENDER_DIR  = $(SRC_DIR)/2_render
UTILS_DIR   = $(SRC_DIR)/3_utils

SRCS        = $(SRC_DIR)/main.c \
              $(wildcard $(PARSE_DIR)/*.c) \
              $(wildcard $(RENDER_DIR)/*.c) \
              $(wildcard $(UTILS_DIR)/*.c)

OBJ_DIR     = obj
OBJS        = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# ##################################### RULES ###################################

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $@

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re