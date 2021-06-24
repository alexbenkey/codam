#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "functions.h"
#include "extra_functions.c"
#include "atoi.c"

#define BUF_SIZE 691

int		put_int_in_string(char *str, int *array);
int		check_dict_length(char *str);

int	main(int argc, char **argv)
{
	int 	val_array[31];
	int		nb;
	int 	key_array;
	int		len;
	int		dict;
	int		return_rd;
	char	buf[BUF_SIZE + 1];
	char	error_msg[39] = "there was an error in opening the file";

	nb = 0;
	if (argc != 2 && argc != 3)
		return (error("Error"));
	else if (argc == 2)
		nb = ft_valid_number(argv[1]);
	dict = open("numbers.dict.txt", O_RDONLY);
	if (dict == -1)
		ft_putstr(error_msg);
	if (dict > 0)
		printf("the open function returned: %d\n", dict);
	return_rd = read(dict, buf, BUF_SIZE);
	buf[return_rd] = '\0';
	key_array = check_dict_length(buf);
	put_int_in_string(buf, key_array);
	// put keys into a new array
	if (close(dict) == -1)
	{
		printf ("close() error");
		return (1);
	}
	free(key_array);
	return (0);
}

int	check_dict_length(char *str)
{
	int	len;
	int	index;
	int *val;

	len = 0;
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == ':')
			len++;
		index++;
	}
	val = (int *) malloc(len * sizeof(int));
	// add malloc check
	return (val);
}

int	put_int_in_string(char *str, int *array)
{
	int index;
	int counter;
	int	number;
	int test;

	counter = 0;
	index = 0;
	while (str[index] != '\0')
	{
		while (str[index] < '0' || str[index] > '9')
			index++;
		number = 0;
		while (str[index] >= '0' && str[index] <= '9')
		{
			number = number * 10;
			number = number + str[index] - '0';
			index++;
		}
		array[counter] = number;
		counter++;
		array[counter] = '\0';
	}
	return (counter);
}