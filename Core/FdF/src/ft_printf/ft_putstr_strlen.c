/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_strlen.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 18:49:40 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/24 18:49:41 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_strlen(char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
	if (!s)
	{
		ft_putstr_strlen("(null)");
		return (6);
	}
	return (ft_strlen(s));
}
