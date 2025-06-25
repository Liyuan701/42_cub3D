# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_ly                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 11:36:09 by lifan             #+#    #+#              #
#    Updated: 2025/05/08 11:36:09 by lifan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################     COMPILATION ########################################

CC = cc
CFLAG = -Wall -Wextra -Werror
NAME = cub3D

#######################     COMMANDES   ########################################

RM = rm -f
VAL = valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all

#######################     FILES       ########################################

PARSE = 1_parse/parse.c\
		1_parse/init_game.c\
		1_parse/get_map.c\
		1_parse/check_map.c\
		1_parse/flood_map.c\
		1_parse/get_config.c\
		1_parse/check_config.c

RENDER = 2_render/refresh.c\
		2_render/ray.c\
		2_render/key.c\
		2_render/cast.c\
		2_render/draw_map.c\
		2_render/draw_pixel.c\
		2_render/draw_player.c\

UTILS = 3_utils/clean.c \
		3_utils/count.c \
		3_utils/config_util.c \
		3_utils/config_util2.c \
		3_utils/debug.c \
		3_utils/error.c \
		3_utils/mylloc.c \

#######################     DIRS        ########################################
SRC_DIR = src
OBJ_DIR = obj
MLX_DIR = lib/minilibx-linux
LIB_DIR = lib/libft
INC_DIR = include
FILE = main.c $(PARSE) ${UTILS} ${RENDER}

SRCS = ${addprefix $(SRC_DIR)/, $(FILE)}
OBJS = ${SRCS:${SRC_DIR}/%.c= $(OBJ_DIR)/%.o}
LIBFT = ${LIB_DIR}/libft.a
MLX = ${MLX_DIR}/libmlx.a

#######################  LIBS AND ATHS    #######################################

INCLUDE = -I${INC_DIR} -I${LIB_DIR} -I${MLX_DIR}
LIBS = -L${LIB_DIR} -lft -L${MLX_DIR} -lmlx  -lX11 -lXext

#######################     Messages    ########################################

WELL = 		echo "${BLUE}|￣￣￣￣￣￣￣|"&&\
		 	echo "${BLUE}|   Okay!     |"&&\
 			echo "${BLUE}|   make...   |"&&\
 			echo "${BLUE}|   DONE !    |"&&\
 			echo "${BLUE}|_____________|"&&\
 			echo "${BLUE}(\__/) ||"&&\
 			echo "${BLUE}(•ㅅ•) ||"&&\
 			echo "${BLUE}/ 　 づ"\

BLUE = \033[94m
YELLOW = \033[93m

#######################     RULES       ########################################

all:		${NAME}

$(OBJ_DIR)/%.o:${SRC_DIR}/%.c
			@mkdir -p $(@D)
			@${CC} ${CFLAG} ${INCLUDE} -c $< -o $@

${NAME}:	${OBJ_DIR} ${OBJS} $(LIBFT) ${MLX}
			@echo "🔍 ${BLUE} Checking if linking is necessary..."
			@$(CC) $(CFLAG) $(OBJS) ${LIBS} ${INCLUDE} -o ${NAME}
			@echo "✅ ${BLUE} Linking completed! \n" && ${WELL}

${OBJ_DIR}:
			@mkdir -p ${OBJ_DIR}

${LIBFT}:
			@make all -C ${LIB_DIR} -s

${MLX}:
			@make all -C ${MLX_DIR} -s

clean:
		@rm -rf ${OBJ_DIR}
		@make clean -C ${LIB_DIR} -s
		@make clean -C ${MLX_DIR} -s
		@echo "🧹 ${BLUE}Clean done, objs cleaned\n"

fclean:	clean
		@${RM} ${NAME}
		@make fclean -C ${LIB_DIR} -s
		@echo "🗑️  ${BLUE}Fclean done, all cleaned.\n"

debug:
		valgrind --leak-check=full --track-origins=yes ./cub3D asset/map/n_not_close.cub

re:	fclean all

.PHONY:	clean fclean all re debug
