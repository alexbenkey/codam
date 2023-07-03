/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   seeking_tools.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/25 17:49:10 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/05/05 17:40:19 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"

int	find_pipe(int *arr, int max, int position)
{
	while (position <= max)
	{
		if (arr[position] == PIPE)
			return (position);
		position++;
	}
	return (position);
}

int	find_tokens(int val, t_tokens *list)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(list->content);
	if (!list->tokens)
		return (-1);
	while (list->tokens[i] != EOL && list->content[i])
	{
		if (list->tokens[i] == val)
			return (i);
		i++;
	}
	return (-1);
}

t_tokens	*find_args(t_tokens *list)
{
	t_tokens	*head;
	int			i;

	i = 0;
	head = list;
	while (list)
	{
		while (list->tokens && list->tokens[i] != EOL)
		{
			if (list->tokens[i] >= COMMAND)
				i = cut_to_args(list, i);
			i++;
		}
		i = 0;
		list = list->next;
	}
	return (head);
}

t_tokens	*find_files(t_tokens *list)
{
	t_tokens	*head;
	int			i;

	i = 0;
	head = list;
	while (list)
	{
		while (list->tokens && list->tokens[i] != EOL)
		{
			if (list->tokens[i] >= REDIRECT_IP && list->tokens[i] \
				<= REDIRECT_APPEND)
				i = cut_off_file_symbol(list, i);
			else if (list->tokens[i] == RD_TIL_DELIM)
			{
				i = cut_off_file_symbol(list, i);
				head = heredoc_func(list, head);
				if (!head)
					return (head);
			}
			i++;
		}
		i = 0;
		list = list->next;
	}
	return (head);
}
