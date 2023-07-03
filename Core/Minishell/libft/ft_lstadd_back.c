/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/26 17:32:56 by jbax          #+#    #+#                 */
/*   Updated: 2021/12/15 16:07:19 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = (*lst);
	if (*lst == NULL)
	{
		(*lst) = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = (*temp).next;
		(*temp).next = new;
	}
}
