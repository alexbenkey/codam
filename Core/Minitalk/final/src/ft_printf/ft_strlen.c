/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 18:49:46 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/24 18:49:47 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *string)
{
	size_t	index;

	index = 0;
	if (!string)
		return (0);
	while (string[index] != 0)
		index++;
	return (index);
}
