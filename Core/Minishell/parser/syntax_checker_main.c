/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   syntax_checker_main.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 18:03:28 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/05/05 18:06:04 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"

int	syntax_checker(char *input, int *arr)
{
	int	i;
	int	val;

	i = 0;
	while (arr[i] != -2)
	{
		if (arr[i] == PIPE)
		{
			if (!content_before(input, i))
				return (9);
		}
		i++;
	}
	val = check_empty_delims(input, arr);
	if (val)
		return (val);
	return (0);
}
