/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/24 14:42:08 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/03/30 15:58:17 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"
#include "./src/libft/libft.h"

int	check_for_numbers(int it, char **string);

int	main(int argc, char **argv)
{
	size_t		i;
	ft_list		*stack_a;
	ft_list		*current;

	if (!check_for_numbers(argc, argv))
	{
		printf("ERROR");
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (argv[i] && !stack_a)
			stack_a = ft_lstnew(argv[i]);
		else if (argv[i] && stack_a)
			ft_lstadd_back(&stack_a, ft_lstnew(argv[i]));
		i++;
	}
	current = stack_a;
	while (current->next)
	{
		printf("\ncurrent number: %zu", (size_t)current->number);
		printf("\ncurrent content: %s", current->content);
		current = current->next;
	}
	if (current->number)
	{
		printf("\ncurrent number: %zu", (size_t)current->number);
		printf("\ncurrent content: %s", current->content);
	}
}

int	check_for_numbers(int it, char **string)
{
	int	i;
	int	x;
	int	r;

	r = 0;
	i = 1;
	if (string)
	{
		while (i < it)
		{
			x = ft_atoi(string[i]);
			if ((x > 0) || (x < 0))
				r = 1;
			else
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
