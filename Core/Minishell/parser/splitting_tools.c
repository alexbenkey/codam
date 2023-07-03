/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   splitting_tools.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/25 16:39:08 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/05/08 16:09:35 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"

int		*ft_arrdup(int *source, int len);

t_tokens	*split_into_list(char *input, int *arr, t_tokens *top)
{
	static int	start = 0;
	int			max;
	int			end;

	end = 0;
	max = ft_strlen(input);
	while (start < max)
	{
		end = (start + get_node_length(arr, start));
		if (start == 0)
			fill_node(top, input, start, end);
		else
			top = get_node(start, arr, input, top);
		if (start == end)
			start++;
		else
			start = end;
	}
	return (top);
}

void	fill_node_split(t_tokens *node, int split_point, int noc)
{
	char		*str;
	int			*arr;
	size_t		node_2_len;
	size_t		len;

	len = ft_strlen(node->content);
	node_2_len = (len - (split_point + noc));
	arr = ft_arrdup(node->tokens, ar_len(node->tokens));
	str = ft_strdup(node->content);
	free(node->content);
	free(node->tokens);
	node->content = 0;
	node->tokens = 0;
	node->next->content = ft_substr(str, (split_point + noc), \
	node_2_len);
	node->content = ft_substr(str, 0, (split_point));
	node->next->tokens = ft_subarr(arr, (split_point + noc), \
	node_2_len);
	node->tokens = ft_subarr(arr, 0, (split_point - 1));
	free(arr);
	free(str);
}

// splits the content of a node at the position given as 'split_points' and 
// places the righthand part of the string in a new node in the linked list.
// noc determines the amount of characters to be splitted on 
// (i.e. for '&&' noc would be 2)
// if node_nr is given, it determines the node in which the 
// string should be split
void	split_to_node(t_tokens *node, int split_point, int noc)
{
	t_tokens	*new;

	new = malloc(sizeof(t_tokens));
	new->content = 0;
	new->tokens = 0;
	new->args = 0;
	new->files = 0;
	new->mini_tok = 0;
	new->log_op = 0;
	if (node->next)
		new->next = node->next;
	else
		new->next = 0;
	node->next = new;
	fill_node_split(node, split_point, noc);
}
