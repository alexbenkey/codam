#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	current = *lst;
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	while (current->next != 0)
	{
		current = current->next;
	}
	current->next = new;
}
