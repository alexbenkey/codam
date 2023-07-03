/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 18:51:54 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/24 18:51:54 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	char	*str;

	str = (char *)malloc(elsize * nelem);
	if (str == 0)
		return (NULL);
	ft_bzero(str, (elsize * nelem));
	return (str);
}
