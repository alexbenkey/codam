/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 18:54:30 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/24 18:54:31 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		stringlength;
	char	*returnstring;
	int		i;

	i = 0;
	if (s == 0)
		return (0);
	stringlength = ft_strlen(s);
	returnstring = (char *)malloc((stringlength + 1) * (sizeof(char)));
	if (returnstring == 0)
		return (0);
	while (s[i])
	{
		returnstring[i] = f(i, s[i]);
		i++;
	}
	returnstring[i] = 0;
	return (returnstring);
}
