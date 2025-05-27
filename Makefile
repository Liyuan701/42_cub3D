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

PARSE = src/1_parse/parse.c

RENDER =
		src/2_render/key.c \


UTILS = src/3_utils/util.c \
		src/3_utils/free.c \

#######################     DIRS        ########################################
SRC_DIR = src
OBJ_DIR = obj
MLX_DIR = lib/minilibx-linux
LIB_DIR = lib/libft
INC_DIR = include
FILE = src/main.c $(SET) ${RENDER} ${UTILS}

SRCS = ${addprefix $(SRC_DIR)/, $(FILE)}
OBJS = ${SRCS:.c=.o}
LIBFT = ${LIB_DIR}/libft.a
MLX = ${MLX_DIR}/libmlx.a

#######################  LIBS AND ATHS    #######################################

INCLUDE = -I${INC_DIR} -I${LIB_DIR} -I${MLX_DIR}
LIBS = -L${MLX_DIR} -lmlx -L${LIB_DIR} -lft -lX11 -lXext

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
YELLOW = = \033[93m

#######################     RULES       ########################################

all:		${NAME}

$(OBJ_DIR)/%.o:${SRC_DIR}/%.c
			@mkdir -p $(@D)
			@${CC} ${CFLAG} ${INCLUDE} -c $< -o $@

${NAME}:	${OBJ_DIR} ${OBJS} $(LIBFT) ${MLX}
			@echo "🔍${BLUE} Checking if linking is necessary..."
			@$(CC) $(CFLAG) $(OBJS) ${LIBS} ${INCLUDE} -o ${NAME}
			@echo "$✅{BLUE} Linking completed! \n" && ${WELL}

${LIBFT}:
			@make all -C ${LIB_DIR} -s

${MLX}:
			@make all -C ${MLX_DIR} -s

clean:
		@rm -rf ${OBJ_DIR}
		@make clean -C ${LIB_DIR} -s
		@make clean -C ${MLX_DIR} -s
		@echo "🧹${BLUE}Clean done, objs cleaned\n"

fclean:	clean
		@${RM} ${NAME}
		@make fclean -C ${LIB_DIR} -s
		@make fclean -C ${MLX_DIR} -s
		@echo "🗑️{BLUE}Fclean done, all cleaned.\n"

re:	fclean all

.PHONY:	clean fclean all re
