/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jordan <jordan@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/09 15:45:33 by jordan        #+#    #+#                 */
/*   Updated: 2021/03/25 12:55:54 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	long unsigned int	count;

	count = 0;
	while (count < n)
	{
		(*(char *)s) = '\0';
		s++;
		count++;
	}
}
