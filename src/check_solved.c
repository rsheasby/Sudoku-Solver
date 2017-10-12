_Bool	check_solved(unsigned char board[9][9])
{
	for (int y = 0; y < 9; ++y)
		for (int x = 0; x < 9; ++x)
			if (!board[x][y])
				return (0);
	return (1);
}