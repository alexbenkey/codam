/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 17:12:12 by jbax          #+#    #+#                 */
/*   Updated: 2023/05/09 17:08:14 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"
#define _POSIX_SOURCE

void	ft_pwd(int output_fd)
{
	char	*cwd;
	int		len;

	g_exit_code = 0;
	cwd = getcwd(0, 0);
	if (!cwd)
		g_exit_code = 1;
	else
	{
		len = ft_strlen(cwd);
		write(output_fd, cwd, len);
		write(output_fd, "\n", 1);
		free(cwd);
	}
}
