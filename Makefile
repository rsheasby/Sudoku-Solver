NAME = sudoku-solver

CC = clang

CFLAGS = -Wall -Wextra -Werror -o $(NAME) -I .

CFILES = src/*.c

$(NAME):
	$(CC) $(CFLAGS) $(CFILES)

all: $(NAME)

fclean:
	rm -f $(NAME)

debug: fclean
	$(CC) $(CFLAGS) -g $(CFILES)

re: fclean all

run: re
	./sudoku-solver sudoku.txt