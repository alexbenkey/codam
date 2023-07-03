/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_operators.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/02 12:17:33 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/05/08 19:24:53 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"

int	*check_operators(char *input, int *arr)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (!check_ampersand(input, arr, i))
			return (0);
		if (!check_or(input, arr, i))
			return (0);
		if (!check_pipes(input, arr, i))
			return (0);
		if (!check_r_arrow(input, arr, i))
			return (0);
		if (!check_l_arrow(input, arr, i))
			return (0);
		i++;
	}
	return (arr);
}
