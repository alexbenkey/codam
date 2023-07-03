/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstascii.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/24 16:49:24 by jbax          #+#    #+#                 */
/*   Updated: 2023/05/03 15:43:39 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_ascii(t_list **head, t_list *new)
{
	t_list	*temp;
	int		i;
	int		len;

	if (!(*head))
		*head = new;
	else
	{
		i = 0;
		len = ft_strlen(new->content);
		temp = *head;
		while (i != -1 && temp)
		{
			if (ft_strncmp(temp->content, new->content, len) >= 0)
			{
				ft_lstinsert(head, new, i);
				i = -2;
			}
			temp = temp->next;
			i++;
		}
		if (i != -1)
			ft_lstadd_back(head, new);
	}
}

t_list	*ft_lstnew_ascii(char **arr)
{
	int		count;
	t_list	*new;
	t_list	*head;

	count = 0;
	head = 0;
	while (arr[count])
	{
		new = ft_lstnew(arr[count]);
		if (!new)
		{
			ft_lstclear(&head, ft_not_free);
			return (NULL);
		}
		ft_lstadd_ascii(&head, new);
		count++;
	}
	return (head);
}
