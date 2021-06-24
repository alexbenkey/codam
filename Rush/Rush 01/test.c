#include<unistd.h>
int print_grid(int *grid)
{
	int x = 0;
	int a;
	while (x < 16)
	{
		a = (grid[x] + 48);
		write (1, &a, 1);
		write (1, " ", 1);
		if (x % 4 == 3)
		{
			write (1, "\n", 1);
		}
		x++;
	}
	return 0;
}

int	main (int argc, char *argv[])
{
	int grid[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	print_grid(grid);
}
