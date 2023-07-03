/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/26 17:41:47 by jbax          #+#    #+#                 */
/*   Updated: 2021/11/24 12:30:17 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newtemp;

	newlst = ft_lstnew((*f)(lst->content));
	lst = lst->next;
	while (lst != NULL)
	{
		newtemp = ft_lstnew((*f)(lst->content));
		if (NULL == newtemp)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newtemp);
		lst = lst->next;
	}
	return (newlst);
}
