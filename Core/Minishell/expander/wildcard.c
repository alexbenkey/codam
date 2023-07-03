/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wildcard.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 14:46:19 by jbax          #+#    #+#                 */
/*   Updated: 2023/04/05 16:42:02 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "../headers/all.h"
#define ERROR 0
#define FOUND 1
#define NOT_FOUND 0

static int	strcmpwild(char *card, char *s);

static int	qq(char *card, char *s)
{
	while (*card == '*')
		card++;
	if (!*card)
		return (FOUND);
	while (*s)
	{
		while (*s && *card != *s)
			s++;
		if (strcmpwild(card, s))
			return (FOUND);
		if (*s)
			s++;
	}
	return (NOT_FOUND);
}

static int	strcmpwild(char *card, char *s)
{
	while (*card)
	{
		if (!*s && *card && *card != '*')
			return (NOT_FOUND);
		if (*card == '*')
		{
			return (qq(card, s));
		}
		else if (*card == *s)
		{
			card++;
			s++;
		}
		else
		{
			return (NOT_FOUND);
		}
	}
	if (!*s && !*card)
		return (FOUND);
	return (NOT_FOUND);
}

t_list	*get_wildcard(char *wild)
{
	DIR				*dirp;
	struct dirent	*dp;
	size_t			len;
	t_list			*cards;
	t_list			*card;

	dirp = opendir(".");
	if (dirp == 0)
		return (ERROR);
	len = strlen(wild);
	dp = readdir(dirp);
	cards = 0;
	while (dp != 0)
	{
		if (strcmpwild(wild, dp->d_name))
		{
			card = ft_lstnew(ft_strdup(dp->d_name));
			ft_lstadd_back(&cards, card);
		}
		dp = readdir(dirp);
	}
	(void)closedir(dirp);
	return (cards);
}

// int	main(int argc, char *argv[])
// {
// 	t_list	*card;

// 	if (argc != 2)
// 	{
// 		ft_putnbr_fd(argc, 1);
// 		for (int i = 0; i < argc ; i++)
// 			ft_putendl_fd(argv[i], 1);
// 		return 0;
// 	}
// 	card = get_wildcard(argv[1]);
// 	system("leaks -q testwild");
// 	while (card)
// 	{
// 		ft_putstr_fd(card->content, 1);
// 		ft_putchar_fd(' ', 1);
// 		card = card->next;
// 	}
// 	ft_putchar_fd('\n', 1);
// 	// free(card);
// 	return 0;
// }
