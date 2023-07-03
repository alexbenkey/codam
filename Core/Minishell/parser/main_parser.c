/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_parser.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/20 15:35:35 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/05/08 16:21:13 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"

int			label_quotess(char *str, int *arr);

t_tokens	*main_loop(char *input)
{
	int			len;
	int			*arr;
	t_tokens	*list;

	len = ft_strlen(input);
	arr = make_arr(len);
	if (!tokanize(input, arr))
	{
		free(arr);
		free(input);
		return (NULL);
	}
	list = malloc(sizeof(t_tokens));
	list->content = 0;
	list->next = 0;
	list = primary_split(input, arr, list);
	return (list);
}

int	*tokanize(char *input, int *arr)
{
	int	val;

	label_quotess(input, arr);
	arr = check_operators(input, arr);
	if (!arr)
		return (NULL);
	arr = command_after_pipe(input, arr);
	if (!arr)
		return (NULL);
	arr = label_spaces(input, arr);
	arr = check_commands(input, arr);
	if (!arr)
		return (NULL);
	val = syntax_checker(input, arr);
	if (val)
	{
		syntax_err_message(val);
		return (NULL);
	}
	return (arr);
}

t_tokens	*primary_split(char *input, int *arr, t_tokens *list)
{
	list->content = input;
	list->tokens = arr;
	list->log_op = 1;
	list->args = 0;
	list->files = 0;
	list->mini_tok = 0;
	list = split_on_amps(list);
	list = split_on_or(list);
	list = split_on_pipes(list);
	trim_spaces(list);
	list = find_files(list);
	list = find_args(list);
	list = check_for_commands(list);
	return (list);
}
