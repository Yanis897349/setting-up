##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Build setting up
##

RM = rm -f

SRC = ./src/Reader/reader.c \
	./src/Generator/generator.c \
	./src/Display/display.c
SRC_TEST = ./tests/test_setting_up.c
MAIN_SRC = ./src/setting_up.c

CFLAGS += -Wall -Wextra -Werror -I . -I ./src/ -L . -lmy

LIB_PATH = ./lib/my

NAME_TEST = unit_tests
NAME = setting_up

.PHONY: all build_lib clean_lib fclean_lib clean fclean re tests_run valgrind

all: $(NAME)

build_lib:
	make -C $(LIB_PATH)

clean_lib:
	make clean -C $(LIB_PATH)

fclean_lib:
	make fclean -C $(LIB_PATH)

$(NAME): build_lib
	$(CC) $(MAIN_SRC) $(SRC) $(CFLAGS) -o $(NAME)

clean: clean_lib
	$(RM) $(NAME)

fclean: clean fclean_lib tests_clean

re: fclean all

tests_run: build_lib
	$(CC) $(SRC) $(SRC_TEST) $(CFLAGS) -o $(NAME_TEST) --coverage -lcriterion
	./$(NAME_TEST)

valgrind: all
	valgrind -s --leak-check=full --error-exitcode=1 ./$(NAME)

tests_clean:
	$(RM) $(NAME_TEST)
	$(RM) *.gcno
	$(RM) *.gcda
