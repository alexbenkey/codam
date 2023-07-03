/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokanize_tools.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/20 15:35:31 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/05/09 15:42:15 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"

int	*command_after_pipe(char *input, int *arr)
{
	int	i;

	if (!arr)
		return (NULL);
	i = 0;
	while (input[i])
	{
		if (arr[i] == PIPE)
		{
			i++;
			while (input[i] != ' ' && input[i] && arr[i] != PIPE)
			{
				arr[i] = COMMAND;
				i++;
				if (input[i] == ' ' || !input[i])
					return (arr);
			}
		}
		i++;
	}
	return (arr);
}

int	*check_commands(char *input, int *arr)
{
	int	i;

	if (!arr || !input)
		return (NULL);
	i = 0;
	while (input[i])
	{
		if (arr[i] == OTHER)
		{
			while (arr[i] == OTHER || arr[i] == SPC)
			{
				arr[i] = COMMAND;
				i++;
			}
			if (arr[i] == -2)
				return (arr);
		}
		i++;
	}
	return (arr);
}	

int	*make_red_op(char *input, int *arr, int i)
{
	int	done;
	int	val;

	done = 0;
	if (input[i + 1] == '>')
		val = REDIRECT_APPEND;
	else
		val = REDIRECT_OP;
	arr[i] = val;
	i++;
	if (val == REDIRECT_APPEND)
		arr[i++] = val;
	while (done == 0)
	{
		while (input[i] == ' ')
			arr[i++] = val;
		while (input[i] && !ft_strrchr("|&<>", input[i]) && (input[i] != ' ' || \
		arr[i] == QUOTE_DL))
			arr[i++] = val;
		done = 1;
	}
	return (arr);
}

int	*make_red_ip(char *input, int *arr, int i)
{
	int	done;
	int	val;

	done = 0;
	if (input[i + 1] == '<')
		val = RD_TIL_DELIM;
	else
		val = REDIRECT_IP;
	arr[i] = val;
	i++;
	if (val == RD_TIL_DELIM)
		arr[i++] = val;
	while (done == 0)
	{
		while (input[i] == ' ')
			arr[i++] = val;
		while (input[i] && !ft_strrchr("|&<>", input[i]) && (input[i] != ' ' || \
		arr[i] == QUOTE_DL))
			arr[i++] = val;
		done = 1;
	}
	return (arr);
}
