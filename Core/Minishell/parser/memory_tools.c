/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memory_tools.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/25 17:49:28 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/05/02 12:34:10 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"

void	*ms_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (void *) malloc(sizeof(size));
	if (ptr == NULL)
		return (NULL);
	while (i < size)
	{
		ptr[i] = nmemb;
		i++;
	}
	return (ptr);
}

void	free_arr_null(char ***ptr)
{
	free(**ptr);
	**ptr = 0;
}

void	free_str_null(char **ptr)
{
	free(*ptr);
	*ptr = 0;
}

void	free_some_stuff(char **args)
{
	int	j;

	j = 0;
	while (args[j])
	{
		free(args[j]);
		args[j] = 0;
		j++;
	}
	free (*args);
}
