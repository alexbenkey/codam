/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/26 17:36:13 by jbax          #+#    #+#                 */
/*   Updated: 2021/11/24 12:35:50 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		i;

	if (lst == NULL)
		return (0);
	temp = lst;
	i = 1;
	while (temp->next != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
