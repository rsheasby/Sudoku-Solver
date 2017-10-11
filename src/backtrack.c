#include <include/backtrack.h>
#include <include/valid.h>
#include <include/sudoku.h>
#include <include/io.h>

_Bool	backtrack(int x, int y)
{
	char	result[9];
	char	*temp;

	if (y == 8 && x == 9)
		savesudoku(g_globals.sudoku);
	else if (x == 9)
	{
		++y;
		x = 0;
	}
	if (g_globals.sudoku[y][x])
		return (backtrack(x + 1, y));
	temp = possibilities(g_globals.sudoku, x, y);
	for(int i = 0; i < 9; ++i)
		result[i] = temp[i];
	for(int i = 0; result[i] && i < 9; ++i)
	{
		g_globals.sudoku[y][x] = result[i];
		backtrack(x + 1, y);
	}
	g_globals.sudoku[y][x] = 0;
	return (0);
}
