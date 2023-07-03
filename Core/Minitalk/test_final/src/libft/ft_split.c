/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 18:53:45 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/24 18:53:46 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_split_function(char *s, char c, int wordcnt, char **words);
static int	ft_wordcount(char const *s, char c);
static void	panic_free(char **words);

char	**ft_split(char const *s, char c)
{
	int		wordcnt;
	char	**words;

	if (s == NULL)
		return (0);
	wordcnt = ft_wordcount(s, c);
	words = (char **)malloc((wordcnt + 1) * sizeof(char *));
	if (words == 0 || s == 0)
		return (NULL);
	return (ft_split_function((char *)s, c, wordcnt, words));
}

static char	**ft_split_function(char *s, char c, int wordcnt, char **words)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	end = 0;
	while (i < (wordcnt))
	{
		while (s[end] == c)
			end++;
		start = end;
		while (s[end] != c && s[end] != 0)
			end++;
		words[i] = ft_substr(s, start, (end - (start)));
		if (!words[i])
		{
			panic_free(words);
			free(words);
			return (NULL);
		}			
		i++;
	}
	words[i] = ((void *)0);
	return (words);
}

static int	ft_wordcount(char const *s, char c)
{
	int	returncount;

	returncount = 0;
	while (*s)
	{
		if (*s != c && (s[1] == c || s[1] == 0))
		{
			returncount++;
		}
		s++;
	}
	return (returncount);
}

static void	panic_free(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free (words[i]);
		i++;
	}
}
