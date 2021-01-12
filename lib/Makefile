#
## EPITECH PROJECT, 2021
## Makefile
## File description:
## lib makefile
#

SRC 		= 	my_putchar.c 	\
				my_strlen.c 	\
				my_putstr.c 	\

OBJ 		= 	$(SRC:.c=.o)

NAME 		= 	libmy.a

CFLAGS 		= 	-Wall -Wextra -Werror

CPPFLAGS 	= 	-Iinclude

all: 		$(NAME)

$(NAME): 	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) $(NAME)

flcean: 	clean
	$(RM) $(NAME)

re: 		fclean all

.PHONY: all clean fclean re
