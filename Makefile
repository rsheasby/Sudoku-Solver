NAME = libft.a

CC = clang

CFLAGS = -Wall -Wextra -Werror -o $(NAME)

CFILES = src/*.c

$(NAME):
	$(CC) $(CFLAGS) $(CFILES)

all: $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all