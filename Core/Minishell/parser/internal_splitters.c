/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   internal_splitters.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/02 12:49:19 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/05/05 16:50:09 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"

static char	**cpy_arg_quote(t_tokens *list)
{
	char		**temp;
	char		**dest;
	int			j;
	int			i;
	int			tmp;

	dest = NULL;
	j = 0;
	i = 0;
	while (list->args && list->args[i])
	{
		temp = split_quote(list->args[i], ' ');
		while (temp[j])
		{
			tmp = 0;
			dest = ft_arradd_index(dest, temp[j++], ft_arrlen_c(dest));
			while (dest[tmp])
				tmp++;
		}
		free(temp);
		temp = 0;
		j = 0;
		i++;
	}
	return (dest);
}

void	split_on_flags(t_tokens *list)
{
	char		**dest;
	t_tokens	*head;

	head = list;
	dest = NULL;
	while (list)
	{
		dest = cpy_arg_quote(list);
		ft_arrclear_c(list->args, ft_arrlen_c(list->args));
		list->args = dest;
		dest = 0;
		list = list->next;
	}
}
