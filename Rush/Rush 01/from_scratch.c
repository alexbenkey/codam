#include<unistd.h>
#include<stdio.h>
#include <stdlib.h>

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

int get_grid_row(int *grid, y)
{
	// get the row of the currently evaluated value.
}

int get_grid_column(int *grid, x)
{
	// get the column of the currently evaluated value.
}


int checktop(int *grid, int *cl_top, x)
{
	int clue = cl_top[x]
	cells = get_grid_column(x); // not yet written
	val = current_input_val(); // not yet written
	int index;
	int highest;
	int mincount;
	int maxcount; 
	highest = 0;
	mincount = 0;
	maxcount = 0;
	while (index < 4)
	{
		if (cells[index] > highest)
		{
			mincount++;
			maxcount++;
			highest = cells[index];
		}
		else
			maxcount++;
	} 
	if (mincount > val || maxcount < val)
		return 1;
	else
		return 0;
}

int checkbottom(int *grid, int *cl_bottom , x)
{
	int clue = cl_bottom[x]
	int cells = get_grid_column(x); // not yet written
	int val = current_input_val(); // not yet written
	int index;
	int highest;
	int mincount;
	int maxcount; 
	highest = 0;
	mincount = 0;
	maxcount = 0;
	while (index < 4)
	{
		if (cells[index] > highest)
		{
			mincount++;
			maxcount++;
			highest = cells[index];
		}
		else
			maxcount++;
	} 
	if (mincount > val || maxcount < val)
		return 1;
	else
		return 0;
}

int checkleft(int *grid, int *cl_left , y)
{
	int clue = cl_left[y]
	int cells = get_grid_row(y); // not yet written
	int val = current_input_val(); // not yet written
	int index;
	int highest;
	int mincount;
	int maxcount; 
	highest = 0;
	mincount = 0;
	maxcount = 0;
	while (index < 4)
	{
		if (cells[index] > highest)
		{
			mincount++;
			maxcount++;
			highest = cells[index];
		}
		else
			maxcount++;
	} 
	if (mincount > val || maxcount < val)
		return 1;
	else
		return 0;
}

int checkright(int *grid, int *cl_left , y)
{
	int clue = cl_left, y
	int cells = get_grid_row(y); // not yet written
	int val = current_input_val(); // not yet written
	int index;
	int highest;
	int mincount;
	int maxcount; 
	highest = 0;
	mincount = 0;
	maxcount = 0;
	while (index < 4)
	{
		if (cells[index] > highest)
		{
			mincount++;
			maxcount++;
			highest = cells[index];
		}
		else
			maxcount++;
	} 
	if (mincount > val || maxcount < val)
		return 1;
}

int put_new_val(*grid)
{
	int	*grid;
	grid = malloc(sizeof(*grid) * 16);

	int counter;
	counter = 0;
	while (grid[counter] != 0)
		counter++;
	if (grid[counter] == 0)
		grid[counter] = selectvalue(); //not yet written
	return counter;
}
	
void check_for_complete(int *grid)
{
	// run through the current board and check if everything is filled out
	int index;
	index = 15; 
		if (grid[index] != 0)
			return 1; // I want to be able to return the grid itself here
		else 
			return 0; 
}



int recursive_tester(int *grid , val)
{
	int cl_top[] = {argv[0],argv[2],argv[4],argv[6]}; 
    int cl_left[] = {argv[16],argv[18],argv[20],argv[22]};
    int cl_right[] = {argv[24],argv[26],argv[28],argv[30]};
    int cl_bottom[] = {argv[8],argv[10],argv[12],argv[14]};
	
	int counter = put_new_val(); //not yet written
	int gridpoint = convert_counter_to_gridpoint(counter);

	checktop(grid, cl_top, x);
	checkbottom(grid, cl_bottom, x);
	checkleft(grid, cl_left, y);
	checkright(grid, cl_right, y);
	if_correct_recurse(grid); // not yet written

	a = check_for_complete(grid);
	if (a == 1)
		print_grid(grid);
	else
		print_error(); //not yet written
}

void clue(char *argv)
{
    // get the clue that is relevant for the current row / column
}


int	main (int argc, char *argv[])
{
	clue(argv[1]);
	// make blank array
	int grid[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	// int cl_top[] = {4,3,2,1};
	// int cl_bottom[] = {1,2,3,2}; 
	// int cl_left[] = {4,3,2,1};
	// int cl_right[] = {1,2,2,2};

	print_grid(grid);
	recursive_tester(grid, val); // val needs to be obtained (the value that needs to be added "1,2,3,4")
}
