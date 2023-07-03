/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstextra.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/24 16:48:00 by jbax          #+#    #+#                 */
/*   Updated: 2023/01/24 16:56:18 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_not_free(void *content)
{
	(void)content;
}

int	ft_lstputs_fd(t_list *head, int fd)
{
	if (!head)
		return (0);
	while (head)
	{
		ft_putendl_fd(head->content, fd);
		head = head->next;
	}
	return (1);
}

int	ft_lstput_promts_fd(t_list *head, char *promt, int fd)
{
	if (!head)
		return (0);
	while (head)
	{
		ft_putstr_fd(promt, fd);
		ft_putendl_fd(head->content, fd);
		head = head->next;
	}
	return (1);
}

void	ft_lstinsert(t_list **head, t_list *new, int index)
{
	int		i;
	t_list	*temp;

	if (index <= 0)
		ft_lstadd_front(head, new);
	else
	{
		if (!(*head))
			*head = new;
		else
		{
			i = 0;
			temp = *head;
			while (temp && i < index - 1)
			{
				temp = temp->next;
				i++;
			}
			new->next = temp->next;
			temp->next = new;
		}
	}
}
