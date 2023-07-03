/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing_tools.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 18:27:02 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/05/09 18:47:56 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"

int	*calloc_array(int len, int type)
{
	int	*ret;
	int	i;

	i = 0;
	if (!len || !type)
		return (NULL);
	ret = malloc((len + 1) * sizeof(int));
	while (i <= len)
	{
		ret[i] = -2;
		i++;
	}
	return (ret);
}

int	*make_arr(int len)
{
	int	i;
	int	*arr;

	i = 0;
	arr = malloc(sizeof(int) * (len + 1));
	if (!arr)
		return (NULL);
	while (i < len)
	{
		arr[i] = OTHER;
		i++;
	}
	arr[i] = EOL;
	return (arr);
}

int	*label_spaces(char *input, int *arr)
{
	int	i;

	if (!arr)
		return (NULL);
	i = 0;
	while (input[i])
	{
		if (arr[i] == OTHER && input[i] == ' ')
			arr[i] = SPC;
		i++;
	}
	return (arr);
}

void	print_array(int *arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i] != EOL)
	{
		ft_putnbr_fd(arr[i], 1);
		write(1, " ", 1);
		i++;
	}
	ft_putnbr_fd(arr[i], 1);
}

// int	print_all_tokens(t_tokens *list)
// {
// 	t_tokens	*tmp;
// 	int			i;
// 	int			j;

// 	j = 1;
// 	tmp = list;
// 	if (!list)
// 		return (0);
// 	while (tmp)
// 	{
// 		i = 0;
// 		ft_putstr_fd("node content: ", 1);
// 		ft_putstr_fd("[", 1);
// 		ft_putstr_fd(tmp->content, 1);
// 		ft_putstr_fd("]", 1);
// 		ft_putstr_fd("\n", 1);
// 		if (tmp->tokens)
// 		{
// 			ft_putstr_fd("tokens: ", 1);
// 			print_array(tmp->tokens);
// 			write(1, "\n", 1);
// 		}
// 		if (tmp->log_op)
// 			printf("log_op of node %d: %d\n", i, tmp->log_op);
// 		if (tmp->files)
// 		{
// 			while (tmp->files[i])
// 			{
// 				printf("file no. %d in node %d: [%s]\n", i, j, tmp->files[i]);
// 				i++;
// 			}
// 		}
// 		else
// 			write(1, "no_files\n", 9);
// 		i = 0;
// 		if (tmp->args)
// 		{
// 			while (tmp->args[i])
// 			{
// 				ft_putstr_fd("arg: [", 1);
// 				ft_putstr_fd(tmp->args[i], 1);
// 				ft_putstr_fd("]\n", 1);
// 				i++;
// 			}
// 		}
// 		else
// 			write(1, "no_args\n", 9);
// 		i = 0;
// 		while (tmp->mini_tok && tmp->mini_tok[i] != -2)
// 		{
// 			ft_putstr_fd("val: [", 1);
// 			ft_putnbr_fd(tmp->mini_tok[i], 1);
// 			ft_putstr_fd("]\n", 1);
// 			i++;
// 		}
// 		j++;
// 		i++;
// 		tmp = tmp->next;
// 	}
// 	return (1);
// }
