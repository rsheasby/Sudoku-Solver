#include <include/valid.h>
#include <include/sudoku.h>

static _Bool	hidden_vert_valid(unsigned char b[9][9], int x, int y, int val)
{
	for (int x2 = 0; x2 < 9; ++x2)
		if (x != x2 && !b[y][x2] && valid(b, x2, y, val))
			return (0);
	return (1);
}

static _Bool	hidden_horiz_valid(unsigned char b[9][9], int x, int y, int val)
{
	for (int y2 = 0; y2 < 9; ++y2)
		if (y != y2 && !b[y2][x] && valid(b, x, y2, val))
			return (0);
	return (1);
}

static _Bool	hidden_block_valid(unsigned char b[9][9], int x, int y, int val)
{
	int	x2 = x;
	int	y2 = y;

	while (x2 != 0 && x2 != 3 && x2 != 6 && x2 >= 0)
		--x2;
	while (y2 != 0 && y2 != 3 && y2 != 6 && y2 >= 0)
		--y2;
	for (int y_off = 0; y_off < 3; ++y_off)
		for (int x_off = 0; x_off < 3; ++x_off)
			if ((x != x2 + x_off || y != y2 + y_off) &&
			!b[y2 + y_off][x2 + x_off] &&
			valid(b, x2 + x_off, y2 + y_off, val))
				return (0);
	return (1);
}

static int		hidden_single(unsigned char b[9][9], int x, int y)
{
	unsigned char	*temp;

	temp = possibilities(b, x, y);
	for (int val = 0; temp[val] && val < 9; ++val)
		if ((hidden_vert_valid(b, x, y, temp[val]) ||
		hidden_horiz_valid(b, x, y, temp[val]) ||
		hidden_block_valid(b, x, y, temp[val])))
			return (temp[val]);
	return (0);
}

_Bool			find_hidden_singles(unsigned char b[9][9])
{
	int	temp;
	int	changed = 0;

	for (int y = 0; y < 9; ++y)
		for (int x = 0; x < 9; ++x)
		{
			temp = hidden_single(b, x, y);
			if (temp)
			{
				b[y][x] = temp;
				changed = 1;
				g_globals.logic_solve = 1;
			}
		}
	return (changed);
}
