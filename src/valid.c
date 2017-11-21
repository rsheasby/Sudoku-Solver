#include <include/valid.h>

static _Bool	valid_vert(unsigned char board[9][9], int x, int val)
{
	for (int y = 0; y < 9; ++y)
		if (board[y][x] == val)
			return (0);
	return (1);
}

static _Bool	valid_horiz(unsigned char board[9][9], int y, int val)
{
	for (int x = 0; x < 9; ++x)
		if (board[y][x] == val)
			return (0);
	return (1);
}

static _Bool	valid_block(unsigned char board[9][9], int x, int y, int val)
{
	while (x != 0 && x != 3 && x != 6 && x >= 0)
		--x;
	while (y != 0 && y != 3 && y != 6 && y >= 0)
		--y;
	for (int y_off = 0; y_off < 3; ++y_off)
		for (int x_off = 0; x_off < 3; ++x_off)
			if (board[y + y_off][x + x_off] == val)
				return (0);
	return (1);
}

_Bool			valid(unsigned char board[9][9], int x, int y, int val)
{
	return (valid_vert(board, x, val)
		&& valid_horiz(board, y, val)
		&& valid_block(board, x, y, val));
}

unsigned char			*possibilities(unsigned char board[9][9], int x, int y)
{
	static unsigned char	results[9];
	int			i = 0;

	for (int f = 1; f <= 9; ++f)
		if (valid(board, x, y, f))
			results[i++] = f;
	results[i] = '\0';
	return (results);
}
