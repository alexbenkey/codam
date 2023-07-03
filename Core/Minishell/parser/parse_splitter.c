/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_splitter.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/14 18:49:19 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/04/25 17:53:52 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"

t_tokens	*split_on_amps(t_tokens *list)
{
	t_tokens	*top;
	int			place;

	if (!list)
		return (NULL);
	top = list;
	place = 0;
	while (list)
	{
		place = find_tokens(SPLIT_AND, list);
		if (place == -1)
			break ;
		split_to_node(list, place, 2);
		list->next->log_op = OPP_AND;
		list = list->next;
	}
	return (top);
}

t_tokens	*split_on_or(t_tokens *list)
{
	t_tokens	*top;
	int			place;

	if (!list)
		return (NULL);
	top = list;
	place = -1;
	while (list)
	{
		place = find_tokens(SPLIT_OR, list);
		if (place != -1)
		{
			split_to_node(list, place, 2);
			list->next->log_op = OPP_OR;
		}
		list = list->next;
	}
	return (top);
}

t_tokens	*split_on_pipes(t_tokens *list)
{
	t_tokens	*top;
	int			place;

	if (!list)
		return (NULL);
	top = list;
	place = -1;
	while (list)
	{
		place = find_tokens(PIPE, list);
		if (place != -1)
		{
			split_to_node(list, place, 1);
			list->next->log_op = OPP_PIPE;
		}
		list = list->next;
	}
	return (top);
}
