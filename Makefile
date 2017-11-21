NAME = sudoku-solver

CC = clang

CFLAGS = -Wall -Wextra -Werror -Ofast -o $(NAME) -I .
DEBUGFLAGS = -pg

CFILES = src/backtrack.c src/hidden_single.c src/main.c src/valid.c \
src/check_solved.c src/io.c src/naked_single.c

$(NAME):
	$(CC) $(CFLAGS) $(CFILES)

all: $(NAME)

fclean:
	rm -f $(NAME)

debug: fclean
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(CFILES)

re: fclean all

run: re
	./sudoku-solver sudoku.txt
