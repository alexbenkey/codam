/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple_tools.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/02 12:34:36 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/05/09 16:19:10 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"

int	*label_vals(int start, int end, int *arr, int sig)
{
	if (end != start)
	{
		while (start <= end)
		{
			arr[start] = sig;
			start++;
		}
	}
	return (arr);
}

t_tokens	*check_for_commands(t_tokens *list)
{
	split_on_flags(list);
	return (list);
}

int	count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	content_before(char *input, int i)
{
	if (i == 0)
		return (0);
	else
	{
		while (i)
		{
			i--;
			if (input[i] != ' ' && input[i] != '\t' && input[i] != '\n')
				return (1);
		}
		return (0);
	}
}

int	content_after(char *input, int i)
{
	while (input[i])
	{
		if (!ft_iswhite_space(input[i]))
			return (i);
		i++;
	}
	return (0);
}
