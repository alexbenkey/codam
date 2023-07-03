/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   openfiles.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 12:49:00 by jbax          #+#    #+#                 */
/*   Updated: 2023/05/08 15:42:39 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"
#include <fcntl.h>
#include <errno.h>

int	setfd_read(char *filename)
{
	int		i;

	i = open(filename, O_RDONLY);
	if (i == -1)
	{
		write(2, "minishell: ", 11);
		perror(filename);
		g_exit_code = 1;
		return (1);
	}
	dup2(i, 0);
	close(i);
	return (0);
}

int	setfd_write(char *filename)
{
	int		i;

	i = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (i == -1)
	{
		write(2, "minishell: ", 11);
		perror(filename);
		g_exit_code = 1;
		return (1);
	}
	dup2(i, 1);
	close(i);
	return (0);
}

int	setfd_append(char *filename)
{
	int		i;

	i = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (i == -1)
	{
		write(2, "minishell: ", 11);
		perror(filename);
		g_exit_code = 1;
		return (1);
	}
	dup2(i, 1);
	close(i);
	return (0);
}
