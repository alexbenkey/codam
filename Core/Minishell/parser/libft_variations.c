/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft_variations.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/25 17:46:08 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/05/05 20:24:51 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"

int	ar_len(int *arr)
{
	int	len;

	len = 0;
	if (!arr)
		return (0);
	while (arr[len] != EOL)
		len++;
	return (len);
}

int	*ft_arrdup(int *source, int len)
{
	int	i;
	int	*dest;

	i = 0;
	dest = malloc((len + 1) * sizeof(int));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = -2;
	return (dest);
}

int	*ms_arrdup(int *arr, int len)
{
	int	*newarr;
	int	i;

	i = 0;
	if (!arr || !len)
		return (NULL);
	newarr = malloc(sizeof(int) * (len + 1));
	while (i <= len)
	{
		newarr[i] = arr[i];
		i++;
	}
	newarr[i] = -2;
	return (newarr);
}

int	*ft_subarr(int *arr, size_t start, size_t len)
{
	size_t			i;
	int				*newarr;
	size_t			arrlen;

	i = 0;
	if (!arr || len == 0)
		return (0);
	arrlen = ar_len(arr);
	if (start > arrlen)
		return (0);
	if (len > arrlen - start)
		return (ft_arrdup(arr + start, (ar_len(arr) - start)));
	newarr = calloc_array((len + 2), -2);
	if (!newarr)
	{
		ft_putendl_fd("\n malloc error!\n", 2);
		return (NULL);
	}
	while (i <= len)
	{
		newarr[i] = arr[start + i];
		i++;
	}
	newarr[i] = -2;
	return (newarr);
}
