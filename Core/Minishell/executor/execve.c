/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execve.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 15:19:09 by jbax          #+#    #+#                 */
/*   Updated: 2023/05/08 20:21:17 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"
#include "../headers/signal_list.h"
#include <errno.h>
#include <sys/stat.h>

static int	put_set_err(char *arg)
{
	struct stat	st;

	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(arg, 2);
	if (!stat(arg, &st))
	{
		if (S_ISDIR(st.st_mode))
		{
			ft_putstr_fd(": is a directory\n", 2);
			return (126);
		}
	}
	if (errno == EACCES)
	{
		ft_putstr_fd(": Permission denied\n", 2);
		return (126);
	}
	ft_putstr_fd(": command not found\n", 2);
	return (127);
}

static int	execcmd(char **arg, t_super *super)
{
	int		i;
	int		index;
	char	*location;
	char	**path;

	location = ft_replacevar(ft_strdup("$PATH"), 0, super->env);
	path = ft_split(location, ':');
	i = -1;
	index = 0;
	if (ft_strchr(*arg, '/'))
		i = 1;
	while (i == -1 && path && path[index])
	{
		free(location);
		location = ft_strjoin3(path[index], "/", arg[0]);
		i = execve(location, &arg[0], super->env);
		index++;
	}
	if (i == 1)
		i = execve(arg[0], &arg[0], super->env);
	i = put_set_err(*arg);
	return (i);
}

static pid_t	ft_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_errbug("fork error", "execve 47");
	return (pid);
}

static int	lets_fork(char **arg, t_super *super)
{
	pid_t	pid;
	int		error;

	block_signal();
	pid = ft_fork();
	if (pid == 0)
	{
		reset_signal();
		error = execcmd(arg, super);
		exit(error);
	}
	pid = waitpid(pid, &error, WCONTINUED);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, super->term_struct);
	tcsetattr(STDOUT_FILENO, TCSAFLUSH, super->term_struct);
	tcsetattr(STDERR_FILENO, TCSAFLUSH, super->term_struct);
	return (error);
}

void	ft_othercmd(char **arg, t_super *super, int ispipe, int fd)
{
	int		error;

	if (!ispipe)
	{
		error = lets_fork(arg, super);
		if (error > 0 && error < 16)
		{
			ft_putendl_fd((char *)g_signals[error], 2);
			g_exit_code = (error + 128);
		}
		else
			g_exit_code = (error / 256);
		set_signal_parrent();
	}
	else
	{
		error = execcmd(arg, super);
		exit(error);
	}
	(void)fd;
}
