#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*top_new;
	t_list	*new_list;

	top_new = NULL;
	if (!lst)
		return (top_new);
	while (lst)
	{
		new_list = ft_lstnew(f(lst->content));
		if (new_list)
			ft_lstadd_back(&top_new, new_list);
		else
		{
			ft_lstclear(&top_new, del);
			return (top_new);
		}
		lst = lst->next;
	}
	return (top_new);
}
