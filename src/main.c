#include <include/io.h>
#include <include/backtrack.h>
#include <include/sudoku.h>
#include <include/naked_single.h>
#include <include/hidden_single.h>
#include <include/check_solved.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	keepgoing = 1;

	if (argc >= 2)
		{
		readfile(argv[1]);
		printf("Input puzzle:\n");
		printsudoku(g_globals.sudoku);
		printf("Trying to solve using logic.\n");
		while (keepgoing)
		{
			keepgoing = 0;
			keepgoing += find_naked_singles(g_globals.sudoku);
			keepgoing += find_hidden_singles(g_globals.sudoku);
		}
		if (check_solved(g_globals.sudoku))
		{
			printf("Success!!!\nSolution:\n");
			printsudoku(g_globals.sudoku);
			return(0);
		}
		else if (g_globals.logic_solve)
		{
			printf("Partial success...\n");
			printsudoku(g_globals.sudoku);
		}
		else
			printf("No luck :-(\n");
		start_backtracking();
		printf("Solved using backtracking!\nSolution:\n");
		printsudoku(g_globals.result);
	}
	return (0);
}
