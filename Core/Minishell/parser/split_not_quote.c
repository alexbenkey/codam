/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split_not_quote.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 13:06:25 by jbax          #+#    #+#                 */
/*   Updated: 2023/05/05 20:11:41 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../headers/quotedef.h"

static int	dellim_index(char *str, char c)
{
	int		index;
	int		quote_mark;

	quote_mark = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] == '"' && quote_mark == NO_QUOTE)
			quote_mark = DOUBLE_QUOTE;
		else if (str[index] == '"' && quote_mark == DOUBLE_QUOTE)
			quote_mark = NO_QUOTE;
		else if (str[index] == '\'' && quote_mark == NO_QUOTE)
			quote_mark = SINGLE_QUOTE;
		else if (str[index] == '\'' && quote_mark == SINGLE_QUOTE)
			quote_mark = NO_QUOTE;
		else if (str[index] == c && quote_mark == NO_QUOTE)
		{
			return (index);
		}
		index++;
	}
	return (-1);
}

static char	**add_arr_split(char **dest, char *s, int begin, int len)
{
	char	*temp;

	temp = ft_substr(s, begin, len);
	if (!temp)
		return (NULL);
	dest = ft_arradd_index(dest, temp, ft_arrlen_c(dest));
	if (!dest)
		return (NULL);
	return (dest);
}

char	**split_quote(char *s, char c)
{
	char	**dest;
	int		len[2];

	if (!s || !*s)
		return (NULL);
	dest = 0;
	len[0] = 0;
	len[1] = dellim_index(s, c);
	while (len[1] > -1)
	{
		if (len[1])
		{
			dest = add_arr_split(dest, s, len[0], len[1]);
			if (!dest)
				return (NULL);
		}
		len[0] += len[1] + 1;
		len[1] = dellim_index(&s[len[0]], c);
	}
	if (s[len[0]])
		dest = add_arr_split(dest, s, len[0], ft_strlen(s));
	if (!dest)
		return (NULL);
	return (dest);
}
