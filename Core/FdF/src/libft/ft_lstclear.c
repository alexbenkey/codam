/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 18:52:34 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/24 18:52:35 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*following;

	current = *lst;
	while (current)
	{
		following = current->next;
		del(current->content);
		free(current);
		current = following;
	}
	*lst = NULL;
}
