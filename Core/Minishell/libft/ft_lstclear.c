/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/26 17:34:06 by jbax          #+#    #+#                 */
/*   Updated: 2021/04/26 17:34:08 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (*lst != NULL)
	{
		while ((*lst) != NULL)
		{
			temp = (*lst)->next;
			(*del)((*lst)->content);
			free ((*lst));
			(*lst) = temp;
		}
	}
}
