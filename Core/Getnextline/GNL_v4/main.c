/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/06 15:24:30 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/03/11 21:00:32 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"	
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	char	*buf;
	int		fd;
	int		i;

	i = 20;
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		while (i)
		{
			buf = get_next_line(fd);
			printf("\nmain output: %s \n", buf);
			i--;
			free(buf);
			buf = NULL;
		}
		close(fd);
	}
	else
		printf("no file to read from.\n");
	system("leaks -q gnl_b.out");
}
