/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jordan <jordan@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 15:33:46 by jordan        #+#    #+#                 */
/*   Updated: 2021/04/15 11:22:54 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*copy;

	copy = malloc(nmemb * size);
	if (copy == NULL)
		return (NULL);
	ft_bzero(copy, nmemb * size);
	return (copy);
}
