/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   C_to_F.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 19:44:41 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/03/30 15:45:00 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./libs/libft/libft.h"

int	main(int argc, char **argv)
{
	int	C;
	int F;

	if (argc > 2 || argc <= 1)
	{
		write(1, "ERROR!", 7);
		return (0);
	}
	else
		C = ft_atoi(argv[1]);
	if (C)
	{
		F = (C * 1.8) + 32;
		printf("%i Celsius converts to %i Fahrenheit", C, F);
	}
}
