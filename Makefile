##
## EPITECH PROJECT, 2020
## B-PSU-100-BDX-1-1-myls-owen.welte
## File description:
## Makefile
##

CC			=	gcc

SRC			=	file.c

DIR_SRC 	= 	src/

DIR_TEST 	= 	tests/

SRC_MAIN 	= 	main.c	\

TEST_NAME	=	unit_tests

TEST_SRC	=	main_test.c

OBJ			=	$(addprefix $(DIR_SRC), $(SRC:.c=.o)) $(addprefix $(DIR_SRC), $(SRC_MAIN:.c=.o))

NAME 		= 	navy

CFLAGS		=	-Wall -Werror -Wextra

#LDFLAGS		=	-O2

CPPFLAGS 	=	-I./include/

all: 		$(NAME)

$(NAME): 	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(CFLAGS)

clean:
	rm -rf $(OBJ)
	rm -rf src/main.o

fclean: 	clean
	rm -rf $(NAME)
	rm -rf *.gc*
	rm -rf $(TEST_NAME)

re:			fclean all

dbg:		CFLAGS += -g
dbg:		$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) -ggdb3

tests_run:      re
	gcc -o $(TEST_NAME) $(SRC) $(TEST_SRC) $(LDFLAGS) $(CPPFLAGS) --coverage -lcriterion
	./$(TEST_NAME)

.PHONY: all clean fclean re cc dbg tests_run
