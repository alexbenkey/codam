/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/06 15:13:23 by jbax          #+#    #+#                 */
/*   Updated: 2023/05/08 20:22:44 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"
#include <fcntl.h>
#include <errno.h>

static int	strsame(char *eoh, int leneof, char *line)
{
	int	len_line;

	len_line = ft_strlen(line);
	if (ft_strncmp(line, eoh, leneof))
		return (0);
	if (leneof != len_line)
		return (0);
	return (1);
}

static void	heredoc_loop(char *eoh, int leneof, int fd)
{
	char	*line;

	line = NULL;
	line = readline("> ");
	if (!line || strsame(eoh, leneof, line))
	{
		exit(0);
	}
	write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
	free(line);
	heredoc_loop(eoh, leneof, fd);
	exit(0);
}

static void	failed_heredoc(char **fdname)
{
	int	error;

	error = unlink(*fdname);
	if (error == -1)
		perror(*fdname);
	free(*fdname);
	*fdname = 0;
}

static int	mkchild(char *eoh, int fd, char **fdname)
{
	int			i;
	pid_t		id;

	id = fork();
	if (id == -1)
		exit_errbug("fork failed", "heredoc 50");
	if (!id)
	{
		reset_signal();
		heredoc_loop(eoh, ft_strlen(eoh), fd);
	}
	waitpid(id, &i, 0);
	close(fd);
	free(eoh);
	if (WIFSIGNALED(i))
	{
		failed_heredoc(fdname);
		return (0);
	}
	return (1);
}

char	*heredoc(char *eoh, int tmpfindex)
{
	static char	*basename = ".tempdir/.tmpfile_heredoc_";
	char		*fdname;
	int			fd;
	char		*num;

	while (tmpfindex)
	{
		num = ft_itoa(tmpfindex);
		fdname = ft_strjoin(basename, num);
		free(num);
		fd = open(fdname, O_RDWR | O_CREAT | O_EXCL, 0644);
		if (fd == -1)
		{
			if (errno != EEXIST)
				exit_errbug("heredoc failed", "heredoc");
		}
		else
		{
			mkchild(eoh, fd, &fdname);
			return (fdname);
		}
		tmpfindex++;
		free(fdname);
	}
	return (0);
}
