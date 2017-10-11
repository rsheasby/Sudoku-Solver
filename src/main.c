#include <include/io.h>
#include <include/backtrack.h>
#include <include/sudoku.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		readfile(argv[1]);
		start_backtracking();
		printsudoku(g_globals.result);
	}
	return (0);
}
