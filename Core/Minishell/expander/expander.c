/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 18:15:23 by jbax          #+#    #+#                 */
/*   Updated: 2023/05/08 19:20:32 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"
#include "../headers/quotedef.h"

char	**expend_quotes(char **arr);
char	**expend_vars(char **arr, char **env);

int	strcmpindex(char *str, char c, int i)
{
	int	index;
	int	quote_mark;

	quote_mark = 0;
	index = i;
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
		else if (str[index] == '$' && c == '$' && quote_mark == DOUBLE_QUOTE
			&& str[index + 1] != '"')
			return (index);
		else if (str[index] == '$' && c == '$' && quote_mark < DOUBLE_QUOTE)
			return (index);
		else if (str[index] == '*' && c == '*' && quote_mark < DOUBLE_QUOTE)
			return (index);
		index++;
	}
	return (-1);
}

static char	**add_list_to_arr(t_list *list, char **arr, int *index)
{
	while (list)
	{
		arr = ft_arradd_index(arr, list->content, *index);
		list = list->next;
		*index += 1;
	}
	return (arr);
}

static char	**expand_wildcard(char **arr, int *file_error, int is_file)
{
	int		index;
	int		has_wildcard;
	t_list	*head;

	index = 0;
	has_wildcard = 0;
	while (arr[index])
	{
		has_wildcard = strcmpindex(arr[index], '*', 0);
		if (has_wildcard > -1)
		{
			head = get_wildcard(arr[index]);
			if (is_file && !head && *file_error == -1)
				*file_error = index;
			if (is_file && head && ft_lstsize(head) != 1 && *file_error == -1)
				*file_error = index;
			arr = ft_arrdell_index(arr, index, free);
			arr = add_list_to_arr(head, arr, &index);
			index--;
			ft_lstclear(&head, ft_not_free);
		}
		index++;
	}
	return (arr);
}

char	**arr_expander(char **arr, char **env, int is_file)
{
	char	**temp;
	int		file_error;

	file_error = -1;
	if (!arr || !*arr)
		return (arr);
	if (is_file)
		temp = ft_arrdup_c(arr, ft_arrlen_c(arr));
	arr = expend_vars(arr, env);
	arr = expand_wildcard(arr, &file_error, is_file);
	if (is_file && file_error > -1)
	{
		printf("bash: %s: ambiguous redirect", temp[file_error]);
		g_exit_code = 1;
		ft_arrclear_c(temp, ft_arrlen_c(temp));
		ft_arrclear_c(arr, ft_arrlen_c(arr));
		return (NULL);
	}
	if (is_file)
		ft_arrclear_c(temp, ft_arrlen_c(temp));
	arr = expend_quotes(arr);
	return (arr);
}

// bash: temp[int]: ambiguous redirect