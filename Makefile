NAME = sudoku-solver

CC = clang

CFLAGS = -Wall -Wextra -Werror -Ofast -o $(NAME) -I .

CFILES = src/*.c

$(NAME):
	$(CC) $(CFLAGS) $(CFILES)

all: $(NAME)

fclean:
	rm -f $(NAME)

debug: fclean
	$(CC) $(CFLAGS) -pg $(CFILES)

re: fclean all

run: re
	./sudoku-solver sudoku.txt
