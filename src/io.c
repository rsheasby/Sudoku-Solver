#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <include/sudoku.h>
#include <include/io.h>

_Bool	readfile(char *filename)
{
	int		fd;
	char	line[10];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	for (int y = 0; y < 9; ++y)
	{
		read(fd, &line, 10);
		for (int x = 0; x < 9; ++x)
			if (line[x] >= '1' && line[x] <= '9')
				g_globals.sudoku[y][x] = line[x] - 48;
			else
				g_globals.sudoku[y][x] = '\0';
	}
	close(fd);
	return (1);
}

void	savesudoku(unsigned char board[9][9])
{
	static _Bool	solved;

	if (solved)
	{
		printf("Invalid Sudoku!\nMore than one solution.\n");
		exit(EXIT_FAILURE);
	}
	else
		solved = 1;
	for (int y = 0; y < 9; ++y)
		for (int x = 0; x < 9; ++x)
			g_globals.result[y][x] = board[y][x];
}

void	printsudoku(unsigned char board[9][9])
{
	printf("+-----------------------+\n");
	for (int y = 0; y < 9; ++y)
	{
		if (y == 3 || y == 6)
			printf("|-------+-------+-------|\n| ");
		else
			printf("| ");
		for (int x = 0; x < 9; ++x)
		{
			if (x == 3 || x == 6)
				printf("| ");
			if (!board[y][x])
				printf("  ");
			else
				printf("%d ", board[y][x]);
		}
		printf("|\n");
	}
	printf("+-----------------------+\n");
}
