##
## EPITECH PROJECT, 2020
## my_project
## File description:
## Makefile
##

CC			=	gcc

SRC			=	file.c

SRC_MAIN 	= 	main.c

DIR_SRC 	= 	src/

OBJ			=	$(addprefix $(DIR_SRC), $(SRC:.c=.o)) $(addprefix $(DIR_SRC), $(SRC_MAIN:.c=.o))

NAME 		= 	my_prog

LDFLAGS  	= 	-Llib/ -lmy

CFLAGS		=	-Wall -Werror -Wextra

CPPFLAGS 	=	-Iinclude/ -Ilib/include

lib:
	make -C lib/

all: 		$(NAME)

$(NAME): 	lib $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS)

clean:
	rm -rf $(OBJ)

fclean: 	clean
	rm -rf $(NAME)
	make -C lib/ fclean

re:			fclean all

.PHONY: all clean fclean re
