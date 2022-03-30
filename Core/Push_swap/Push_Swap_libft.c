/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Push_Swap_libft.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/24 13:59:38 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/03/29 19:16:11 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

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

size_t	ft_strlen(const char *string)
{
	size_t	index;

	index = 0;
	while (string[index] != 0)
		index++;
	return (index);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*newstr;

	i = 0;
	while (s[i])
		i++;
	newstr = malloc((i + 1) * sizeof(char));
	if (newstr == 0)
		return (NULL);
	i = 0;
	while (s[i])
	{
		newstr[i] = s[i];
		i++;
	}
	newstr[i] = '\0';
	return ((char *)newstr);
}

t_list	*ft_lstnew(void	*content, size_t *number)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->content = content;
		tmp->number = *number;
		tmp->next = 0;
	}
	return (tmp);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

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

int	ft_atoi(const char *str)
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
			return (0);
		else if (i == 19 && str[i])
			return (-1);
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

void	ft_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*following;

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

int	check_for_numbers(int it, char **string)
{
	int	i;
	int	x;
	int	r;

	r = 0;
	i = 1;
	if (string)
	{
		while (i < it)
		{
			x = ft_atoi(string[i]);
			if ((x > 0) || (x < 0))
				r = 1;
			else
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
