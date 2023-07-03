/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_tokanizer.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/25 17:53:12 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/04/26 13:47:26 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"

void	attach_token(t_tokens *list, int place)
{
	int	*tmp;
	int	i;

	i = 0;
	while (list->mini_tok[i] != EOL)
			i++;
	tmp = malloc(sizeof(int) * (i + 2));
	i = 0;
	while (list->mini_tok[i] != EOL)
	{
		tmp[i] = list->mini_tok[i];
		i++;
	}
	tmp[i] = list->tokens[place];
	tmp[i + 1] = EOL;
	free(list->mini_tok);
	list->mini_tok = tmp;
}

void	update_mini_tok(t_tokens *list, int i, int val)
{
	int	len;
	int	*new;
	int	j;

	len = 0;
	j = 0;
	while (list->mini_tok[len] != -2)
		len++;
	new = malloc(sizeof(int) * (len + 2));
	while (j <= i)
	{
		new[j] = list->mini_tok[j];
		j++;
	}
	new[j] = val;
	while (list->mini_tok[j] != -2)
	{
		new[j + 1] = list->mini_tok[j];
		j++;
	}
	new[j + 1] = -2;
	free(list->mini_tok);
	list->mini_tok = new;
}
