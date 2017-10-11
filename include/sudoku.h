#ifndef SUDOKU_H
# define SUDOKU_H

typedef struct	s_globals
{
	unsigned char   sudoku[9][9];
	unsigned char   result[9][9];
}				t_globals;

t_globals		g_globals;

#endif