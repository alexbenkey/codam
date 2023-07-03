/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jordan <jordan@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/14 13:00:52 by jordan        #+#    #+#                 */
/*   Updated: 2021/04/14 17:23:40 by jordan        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		count;

	copy = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	count = 0;
	while (s[count] != '\0')
	{
		copy[count] = s[count];
		count++;
	}
	copy[count] = '\0';
	return (copy);
}
