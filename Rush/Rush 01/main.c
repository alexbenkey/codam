#include<unistd.h>

// void	ft_print_row(int *arr)
// {
// 	int count;

// 	count = 0;
// 	while (count < 4)
// 	{
// 		int a;
// 		a = (arr[count] + '0');
// 		write(1, &a, 1);
// 		write(1, " ", 1);
// 		count ++;
// 	}
// 	write(1, "\n", 1);
// }

// void check_side_rows(int b , int c, int *clues)
// {
// 	int count;
// 	count = 1;

// 	while (count < 3)
// 	{
// 		if (clues[count] == 4)
// 		arr[count] = 1;
// 		else if (clues[count] == 1)
// 		arr[count] = 4;
// 		count++;
// 	}
// }


// void check_top_bottom_row(int *arr, int *clues)
// {
// 	int count;
// 	count = 0;

// 	while (count < 4)
// 	{
// 		if (clues[count] == 4)
// 		arr[count] = 1;
// 		else if (clues[count] == 1)
// 		arr[count] = 4;
// 		count++;
// 	}
// }



	int	x1[] = {0,0,0,0};
	int	x2[] = {0,0,0,0};
	int	x3[] = {0,0,0,0};
	int	x4[] = {0,0,0,0};

	check_side_rows(cl_left[1] , cl_left[2], cl_left)
	check_side_rows(cl_left[1] , cl_left[2], cl_left)
	check_side_rows( , int c, clues)
	check_top_bottom_row(x1, cl_top);
	check_top_bottom_row(x4, cl_bottom);
	ft_print_row(x1);
	ft_print_row(x2);
	ft_print_row(x3);
	ft_print_row(x4);

	return (0);
}