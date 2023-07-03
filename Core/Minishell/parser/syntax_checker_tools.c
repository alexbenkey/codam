/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   syntax_checker_tools.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 18:54:13 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/05/09 17:11:52 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"

int	check_or(char *input, int *arr, int i)
{
	if (input[i] == '|' && input[i + 1] == '|' && \
	arr[i] == OTHER && arr[i + 1] == OTHER)
	{
		if (!or_error_checker(input, i))
			return (0);
		arr[i] = SPLIT_OR;
		arr[i + 1] = SPLIT_OR;
	}
	return (1);
}

int	check_ampersand(char *input, int *arr, int i)
{
	if (input[i] == '&' && input[i + 1] == '&' && \
	arr[i] == OTHER && arr[i + 1] == OTHER)
	{
		if (!amp_checker(input, i))
			return (0);
		arr[i] = SPLIT_AND;
		arr[i + 1] = SPLIT_AND;
	}
	return (1);
}

int	check_pipes(char *input, int *arr, int i)
{
	if (input[i] == '|' && arr[i] == OTHER)
	{
		if (!pipe_checker(input, i))
			return (0);
		arr[i] = PIPE;
	}
	return (1);
}

int	check_l_arrow(char *input, int *arr, int i)
{
	if (input[i] == '<' && arr[i] == OTHER)
	{
		if (!red_op_checker(input, i))
			return (0);
		arr = make_red_ip(input, arr, i);
	}
	return (1);
}

int	check_r_arrow(char *input, int *arr, int i)
{
	if (input[i] == '>' && arr[i] == OTHER)
	{
		if (!red_op_checker(input, i))
			return (0);
		arr = make_red_op(input, arr, i);
	}
	return (1);
}
