/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   syntax_checkers.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 18:54:10 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/05/09 17:12:11 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"

int	pipe_checker(char *input, int i)
{
	if (!input[i + 1] || !is_empty(&input[i + 1]) || !content_after(input, i))
	{
		write(2, "Minishell: syntax error near unexpected token `newline'\n", \
		56);
		g_exit_code = 258;
		return (0);
	}
	i++;
	while (ft_iswhite_space(input[i]))
		i++;
	if (ft_strrchr("|&", input[i]))
	{
		if (input[i + 1] == '|' && input[i] == '|')
			write(2, "Minishell: syntax error near unexpected token `||'\n", 51);
		else
		{
			write(2, "Minishell: syntax error near unexpected token `", 47);
			write(2, &input[i], 1);
			write(2, "'\n", 2);
		}
		g_exit_code = 258;
		return (0);
	}
	return (1);
}

int	or_error_checker(char *input, int i)
{
	if ((input[i + 2] == '|') || !content_before(input, i) || \
	!content_after(input, i + 1))
	{
		write(2, "minishell: syntax error near unexpected token `||'\n", 51);
		g_exit_code = 258;
		return (0);
	}
	return (1);
}

int	amp_checker(char *input, int i)
{
	if (input[i + 2] == '&' || !content_before(input, i) || \
	!content_after(input, i + 1))
	{
		write(2, "minishell: syntax error near unexpected token `&&'\n", 51);
		g_exit_code = 258;
		return (0);
	}
	return (1);
}

static int	pre_checker(char *input, int i)
{	
	if (input[i + 1] == input[i])
		i++;
	i++;
	if (!content_after(input, i))
	{
		write_relevant_message(input, i);
		return (0);
	}
	while (ft_iswhite_space(input[i]))
		i++;
	return (i);
}

int	red_op_checker(char *input, int i)
{
	i = pre_checker(input, i);
	if (i == 0)
		return (0);
	if (ft_strrchr("|&<>", input[i]))
	{
		write_relevant_message(input, i);
		return (0);
	}
	return (1);
}
