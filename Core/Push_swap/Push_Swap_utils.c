/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Push_Swap_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/24 13:59:42 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/03/27 23:17:13 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

char	**input_parser(char *string)
{
	char	**tmp;

	if (*string)
	{
		tmp = ft_split(string, ' ');
	}
	printf("tmp: %s", *tmp);
	return (tmp);
}

int	main(int argc, char *argv)
{
	int		i;
	t_list	*top;
	t_list	*current;

	while (i < argc)
	{
		if (argv[i] && !top)
			top = ft_lstnew(argv[i], 1);
		else if (argv[i] && top)
			ft_lstadd_back(top, ft_lstnew(argv[i], (top->number + 1)));
		i++;
	}
	while (top->next)
	{
		if (top->content != )
			write(1, "Error", 5);
		printf("\ncurrent content: %s", top);
		top = top->next;
	}
}

// 'Loud unbearable feedback noises' 