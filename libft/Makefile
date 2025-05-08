NAME = libft.a
SRC = ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint\
ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy\
ft_strlcat ft_toupper ft_tolower ft_strchr ft_strrchr\
ft_strncmp ft_memchr ft_memcmp ft_strnstr ft_atoi\
ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim\
ft_split ft_itoa ft_strmapi ft_striteri ft_putchar_fd\
ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
ft_printf print_char print_nb \
ft_lstadd_back ft_lstadd_front ft_lstclear \
ft_lstdelone ft_lstiter ft_lstlast \
ft_lstmap ft_lstnew ft_lstsize get_next_line_utils\
get_next_line

SRCS = ${addsuffix .c, ${SRC}}
OBJS = ${SRCS:.c=.o}
CC = cc
FLAG = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

%.o	:	%.c
		@${CC} ${FLAG} -c $< -o $@

${NAME}	:	${OBJS}
		@${AR} ${NAME} ${OBJS}

all	:	${NAME}

clean	:
		@${RM} ${OBJS}

fclean:	clean
		@${RM} ${NAME}

re:	fclean all

.PHONY: clean fclean all re
