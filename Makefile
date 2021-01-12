##
## EPITECH PROJECT, 2020
## B-PSU-100-BDX-1-1-myls-owen.welte
## File description:
## Makefile
##

CC			=	gcc

SRC			=	display/pre_game_disp.c		\
				errors/errors.c				\
				errors/file_format_error.c	\
				game/game_main.c			\
				game/check_maps.c 			\
				game/create_maps.c 			\
				game/display_maps.c 		\
				game/interactions.c 		\
				network/connexion.c			\
				network/convert.c			\
				network/in_game_signal.c	\
				network/pre_game_connexion.c\
				network/recieve_info.c		\
				network/send_attack.c		\
				network/send_info.c			\
				utils/getnbr.c				\
				utils/init_pid.c			\
				utils/network_some.c		\
				utils/open_files.c			\
				utils/put_text.c			\
				utils/my_strcmp.c			\
				navy.c						\

DIR_SRC 	= 	src/
DIR_TEST 	= 	tests/

SRC_MAIN 	= 	main.c	\

TEST_NAME	=	unit_tests

TEST_SRC	=	test_connexion.c	 	\
				test_errors.c			\
				test_file_format.c		\
				test_getnbr.c			\
				test_ig_signal.c		\
				test_interactions.c		\
				test_pre_game.c			\
				test_utils.c			\
				test.c 					\

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

##tests_run:	re
##	gcc -o $(TEST_NAME) $(TEST_SRC) $(SRC) $(LDFLAGS) $(CPPFLAGS) --coverage -lcriterion
##	./$(TEST_NAME)

##criterion:	all
##	gcc -o cr.out src/call_operations.o src/operations.o src/parsing.o src/tools.o tests/test_eval_expr.c -lcriterion --coverage -Llib/my -lmy -Iinclude/
##	./cr.out
##	cd gcovr
##	gcovr --html --html-detail -o website_test.html --html-title test_criterion -r .. --exclude ../tests/ --exclude ../gcovr/
##	/usr/bin/firefox website_test.html

.PHONY: all clean fclean re cc dbg tests_run
