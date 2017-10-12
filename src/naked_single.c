#include <include/valid.h>
#include <include/sudoku.h>

static int	naked_single(unsigned char board[9][9], int x, int y)
{
	unsigned char	*possible;

	possible = possibilities(board, x, y);
	if (possible[1])
		return (0);
	else
		return (possible[0]);
}

//	;-)

_Bool		find_naked_singles(unsigned char board[9][9])
{
	_Bool	changed = 0;
	int		temp;
	
	for (int y = 0; y < 9; ++y)
		for (int x = 0; x < 9; ++x)
		{
			temp = 0;
			if (!board[y][x])
				temp = naked_single(board, x, y);
			if (temp)
			{
				board[y][x] = temp;
				changed = 1;
				g_globals.logic_solve = 1;
			}
		}
	return (changed);
}
