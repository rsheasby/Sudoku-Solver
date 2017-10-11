#include <include/io.h>
#include <include/backtrack.h>
#include <include/sudoku.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		if (!readfile(argv[1]))
			return (1);
		printf("Solving puzzle using backtracking (This may take a while)...\n");
		backtrack(0, 0);
		printf("Solved! Solution:\n");
		printsudoku(g_globals.result);
	}
	return (0);
}
