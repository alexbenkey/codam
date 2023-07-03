/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expend_quotes.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 16:40:27 by jbax          #+#    #+#                 */
/*   Updated: 2023/04/12 17:36:52 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/quotedef.h"
#include "../libft/libft.h"

static int	nb_of_non_quotes(char *str)
{
	int	index;
	int	quote_mark;
	int	nb_non_quotes;

	nb_non_quotes = 0;
	quote_mark = NO_QUOTE;
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
		else
			nb_non_quotes++;
		index++;
	}
	return (nb_non_quotes);
}

static int	is_quote_2btrimed(char c, int *quote_mark)
{
	if (c == '"' && *quote_mark == NO_QUOTE)
	{
		*quote_mark = DOUBLE_QUOTE;
		return (1);
	}
	else if (c == '"' && *quote_mark == DOUBLE_QUOTE)
	{
		*quote_mark = NO_QUOTE;
		return (1);
	}
	else if (c == '\'' && *quote_mark == NO_QUOTE)
	{
		*quote_mark = SINGLE_QUOTE;
		return (1);
	}
	else if (c == '\'' && *quote_mark == SINGLE_QUOTE)
	{
		*quote_mark = NO_QUOTE;
		return (1);
	}
	return (0);
}

static char	*trim_quotes(char *str)
{
	int		index;
	int		quote_mark;
	int		dest_index;
	char	*dest;

	dest = malloc((nb_of_non_quotes(str) + 1) * sizeof(char));
	dest_index = 0;
	quote_mark = NO_QUOTE;
	index = 0;
	while (str[index])
	{
		if (!is_quote_2btrimed(str[index], &quote_mark))
		{
			dest[dest_index] = str[index];
			dest_index++;
		}
		index++;
	}
	dest[dest_index] = '\0';
	return (dest);
}

char	**expend_quotes(char **arr)
{
	int		index;
	int		quote_mark;
	char	*temp;

	quote_mark = NO_QUOTE;
	index = 0;
	while (arr[index])
	{
		if (ft_strchr(arr[index], '\''))
			quote_mark = SINGLE_QUOTE;
		if (ft_strchr(arr[index], '"'))
			quote_mark = DOUBLE_QUOTE;
		if (quote_mark)
		{
			temp = trim_quotes(arr[index]);
			arr = ft_arrdell_index(arr, index, free);
			arr = ft_arradd_index(arr, temp, index);
		}
		quote_mark = NO_QUOTE;
		index++;
	}
	return (arr);
}
