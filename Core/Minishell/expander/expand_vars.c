/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_vars.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 18:23:01 by jbax          #+#    #+#                 */
/*   Updated: 2023/05/08 19:43:18 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"
#include "../headers/quotedef.h"

int	strcmpindex(char *str, char c, int i);

static char	*rep_exit_code(char *src, int index)
{
	char	*dest;
	char	*num;
	int		len;

	num = ft_itoa(g_exit_code);
	len = ft_strlen(num) + ft_strlen(src);
	dest = malloc(len * sizeof(char));
	len = 0;
	while (*src)
	{
		if (index == len)
		{
			src += 2;
			len += ft_strlcpy(&dest[len], num, ft_strlen(num) + 1);
		}
		else
		{
			dest[len] = *src;
			src++;
			len++;
		}
	}
	dest[len] = '\0';
	free(num);
	return (dest);
}

static char	**rep_vars_inindex(char **arr, int index, int *index2, char **env)
{
	char	*var;

	if (ft_isalnum(arr[index][*index2 + 1]) || arr[index][*index2 + 1] == '_'\
		|| arr[index][*index2 + 1] == '"' || arr[index][*index2 + 1] == '\'')
	{
		arr[index] = ft_replacevar(arr[index], *index2, env);
		*index2 -= 1;
	}
	else if (arr[index][*index2 + 1] == '?')
	{
		var = rep_exit_code(arr[index], *index2);
		free(arr[index]);
		arr[index] = var;
	}
	return (arr);
}

static char	**remove_empty_args(char **arr)
{
	int	index;

	index = 0;
	while (arr && arr[index])
	{
		if (!arr[index][0])
		{
			arr = ft_arrdell_index(arr, index, free);
			if (!arr)
				exit_errbug("malloc failed", "");
		}
		index++;
	}
	return (arr);
}

char	**expend_vars(char **arr, char **env)
{
	int		index;
	int		index2;

	index = 0;
	index2 = 0;
	while (arr[index])
	{
		index2 = strcmpindex(arr[index], '$', index2);
		if (index2 > -1 && arr[index][index2 + 1])
		{
			arr = rep_vars_inindex(arr, index, &index2, env);
			index2++;
		}
		else
		{
			index2 = 0;
			index++;
		}
	}
	arr = remove_empty_args(arr);
	return (arr);
}
