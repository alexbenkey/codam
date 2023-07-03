/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transpose.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/25 17:19:07 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/05/05 20:22:05 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"

void	transpose_file(t_tokens *list, int length, int start, int val)
{	
	int	i;

	i = 0;
	if (list->files)
		free(list->files);
	list->files = malloc(sizeof(char *) * 2);
	list->files[0] = ft_substr(list->content, start, length);
	list->files[1] = NULL;
	if (!list->mini_tok)
	{
		list->mini_tok = malloc(sizeof(int) * 2);
		list->mini_tok[0] = val;
		list->mini_tok[1] = EOL;
	}
	else
		attach_token(list, start);
}

void	transpose_arg(t_tokens *list, int length, int start)
{
	int	i;

	i = 0;
	if (list->args)
	{
		free(list->args);
		list->args = NULL;
	}
	list->args = malloc(sizeof(char *) * 2);
	list->args[0] = ft_substr(list->content, start, length);
	list->args[1] = 0;
}

void	add_in_node_file(t_tokens *list, int length, int i)
{
	char	**tmp_files;
	int		j;

	j = 0;
	while (list->files[j])
		j++;
	tmp_files = malloc(sizeof(char *) * (j + 2));
	j = 0;
	while (list->files[j])
	{
		tmp_files[j] = ft_strdup(list->files[j]);
		j++;
	}
	tmp_files[j] = ft_substr(list->content, i, length);
	tmp_files[j + 1] = NULL;
	j = 0;
	while (list->files[j])
	{
		free (list->files[j]);
		list->files[j] = 0;
		j++;
	}
	free(list->files);
	list->files = 0;
	list->files = tmp_files;
}

void	add_in_node_arg(t_tokens *list, int length, int i)
{
	char	**tmp_args;
	int		j;

	j = 0;
	while (list->args[j])
		j++;
	tmp_args = malloc(sizeof(char *) * (j + 2));
	j = 0;
	while (list->args[j])
	{
		tmp_args[j] = ft_strdup(list->args[j]);
		j++;
	}
	tmp_args[j] = ft_substr(list->content, i, length);
	tmp_args[j + 1] = NULL;
	j = 0;
	while (list->args[j])
	{
		free (list->args[j]);
		list->args[j] = 0;
		j++;
	}
	free(list->args);
	list->args = 0;
	list->args = tmp_args;
}
