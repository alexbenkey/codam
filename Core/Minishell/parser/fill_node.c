/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_node.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/20 15:47:26 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/05/08 16:54:19 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"

void	fill_node(t_tokens *node, char *input, int start, int end)
{
	char	*string;
	int		i;

	i = 0;
	string = malloc((end - start) + 1);
	while (start < end)
	{
		string[i] = input[start];
		i++;
		start++;
	}
	string[i] = '\0';
	node->content = string;
}

t_tokens	*get_node(int start, int *arr, char *input, t_tokens *top)
{
	int			end;
	char		*str;
	int			i;
	t_tokens	*tmp;

	i = 0;
	end = start;
	while (arr[end] == arr[start])
		end++;
	if (arr[start] != SPC)
	{
		tmp = setup_new_node(top);
		str = ms_calloc(0, ((end - start) + 1));
		while (start < end)
			str[i++] = input[start++];
		str[i] = '\0';
		tmp->content = str;
		tmp->next = 0;
	}
	return (top);
}

static void	del_files(char **files, int *tokens)
{
	int	index;
	int	error;

	error = 0;
	index = 0;
	while (files && files[index])
	{
		if (tokens[index] == RD_TIL_DELIM)
			error = unlink(files[index]);
		if (error == -1)
			perror(files[index]);
		index++;
	}
}

void	free_list(t_tokens *list)
{
	t_tokens	*tmp;

	while (list)
	{
		tmp = list->next;
		if (list->content)
		{
			free(list->content);
			list->content = 0;
		}
		if (list->tokens)
			free(list->tokens);
		if (list->args)
			ft_arrclear_c(list->args, (ft_arrlen_c(list->args)));
		del_files(list->files, list->mini_tok);
		if (list->files)
		{
			ft_arrclear_c(list->files, (ft_arrlen_c(list->files)));
		}
		if (list->mini_tok)
			free(list->mini_tok);
		free(list);
		list = tmp;
	}
}
