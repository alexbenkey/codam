/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoinx.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/11 10:56:59 by jbax          #+#    #+#                 */
/*   Updated: 2023/02/28 16:05:59 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static void	loop_content(char **dest, char const *s, int *i)
{
	while (*s != '\0')
	{
		dest[0][*i] = *s;
		*i += 1;
		s++;
	}
}

static int	joinlenn(va_list arg, int x)
{
	va_list	temp;
	int		len;

	len = 0;
	va_copy(temp, arg);
	while (x)
	{
		len += ft_strlen(va_arg(temp, char *));
		x--;
	}
	va_end(temp);
	return (len);
}

char	*ft_strjoinx(int x, ...)
{
	va_list	arg;
	char	*dest;
	int		n;
	int		count;

	va_start(arg, x);
	count = 0;
	n = joinlenn(arg, x) + 1;
	dest = malloc(n * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (x)
	{
		loop_content(&dest, va_arg(arg, char *), &count);
		x--;
	}
	dest[count] = '\0';
	va_end(arg);
	return (dest);
}
