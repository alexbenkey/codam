/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Push_Swap_libft.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/24 13:59:38 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/06 13:51:47 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

char	**ft_split(char const *s, char c)
{
	int		wordcnt;
	char	**words;

	if (!s)
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*newstr;
	size_t			strlen;

	i = 0;
	if (s == 0)
		return (NULL);
	strlen = ft_strlen(s);
	if (start > strlen)
		return (ft_strdup(""));
	if (len > strlen - start)
		return (ft_strdup(s + start));
	newstr = (char *)malloc((len + 1) * sizeof(char));
	if (newstr == 0)
		return (NULL);
	while (i < len)
	{
		newstr[i] = s[start + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

void	ft_lstadd_back(t_alist **lst, t_alist *new)
{
	t_alist	*current;

	current = *lst;
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	while (current->next != 0)
	{
		current = current->next;
	}
	current->next = new;
}

int	ps_atoi(const char *str)
{
	int	i;
	int	p;
	int	val;

	i = 0;
	val = 0;
	while ((*str == ' ') || (*str >= 9 && *str <= 13))
		str++;
	p = p_check(str);
	if (*str == '-' || *str == '+')
		str++;
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		val *= 10;
		val += (str[i] - 48);
		i++;
		if (i == 19 && str[i] && p == -1)
		{
			write (2, "test error", 10);
			exit (0);
		}
		//	return (0);
		else if (i == 19 && str[i])
		{
			write (2, "test error", 10);
			exit (0);
		}
			// return (-1);
	}
	return (val * p);
}

static int	p_check(const char *str)
{
	int	i;
	int	p;

	p = 1;
	i = 0;
	while ((*str == ' ') || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			p *= -1;
		str++;
	}
	return (p);
}

void	ft_lstclear(t_alist **lst)
{
	t_alist	*current;
	t_alist	*following;

	current = *lst;
	while (current)
	{
		following = current->next;
		free(current->content);
		free(current);
		current = following;
	}
	*lst = NULL;
}

