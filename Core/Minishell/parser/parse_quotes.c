/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_quotes.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/20 15:41:52 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/04/17 16:14:32 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"

int	label_quotess(char *str, int *arr)
{
	int	iterator;
	int	quote_mark;

	quote_mark = OTHER;
	iterator = 0;
	while (str && arr && str[iterator] && arr[iterator] != EOL)
	{
		if (quote_mark != OTHER)
			arr[iterator] = quote_mark;
		if (str[iterator] == '"' && quote_mark == OTHER)
			quote_mark = QUOTE_DL;
		else if (str[iterator] == '"' && quote_mark == QUOTE_DL)
			quote_mark = OTHER;
		else if (str[iterator] == '\'' && quote_mark == OTHER)
			quote_mark = QUOTE_SL;
		else if (str[iterator] == '\'' && quote_mark == QUOTE_SL)
			quote_mark = OTHER;
		if (quote_mark != OTHER)
			arr[iterator] = quote_mark;
		iterator++;
	}
	return (-1);
}

int	*label_quotes(char *input, int *arr, int type)
{
	int		i;
	int		start;
	int		sup;
	char	d_or_s;

	if (!arr)
		return (NULL);
	sup = 0;
	i = 0;
	d_or_s = get_quote_type(type);
	while (input[i])
	{
		if (input[i] == d_or_s && sup == 0)
		{
			start = i++;
			sup = 1;
		}
		if (input[i] == d_or_s && sup == 1)
		{
			arr = label_vals(start, i, arr, type);
			sup = 0;
		}
		i++;
	}
	return (arr);
}

char	get_quote_type(int type)
{
	if (type == 0)
		return ('\'');
	else
		return ('\"');
}
