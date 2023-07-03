/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   letspipe.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 18:27:00 by jbax          #+#    #+#                 */
/*   Updated: 2023/05/08 16:47:01 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../headers/all.h"
#include "../headers/signal_list.h"

int	what_cmd1(t_tokens *bigdata, t_super *super, int pipes, int fd);

static void	set_exit_code(t_super *super, t_tokens *bigdata, int error)
{
	int	last_pipe;

	last_pipe = 0;
	if (!bigdata->next || bigdata->next->log_op != OPP_PIPE)
		last_pipe = 1;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, super->term_struct);
	tcsetattr(STDOUT_FILENO, TCSAFLUSH, super->term_struct);
	tcsetattr(STDERR_FILENO, TCSAFLUSH, super->term_struct);
	if (last_pipe && error > 0 && error < 16)
	{
		ft_putendl_fd((char *)g_signals[error], 2);
		g_exit_code = (error + 128);
	}
	else if (last_pipe)
		g_exit_code = (error / 256);
}

static void	start_child(t_tokens *bigdata, t_super *super, int *pipe, int read)
{
	int	error;

	reset_signal();
	close(pipe[0]);
	dup2(read, 0);
	if (bigdata->next && bigdata->next->log_op == OPP_PIPE)
		dup2(pipe[1], 1);
	error = what_cmd1(bigdata, super, 1, 1);
	close(pipe[1]);
	exit(g_exit_code);
}

static int	mk_pipes(t_tokens *bigdata, int readfd, t_super *super)
{
	int		pipefd[2];
	pid_t	pid;
	int		error;

	error = pipe(pipefd);
	if (error == -1)
		return (0);
	pid = fork();
	if (pid == 0)
		start_child(bigdata, super, pipefd, readfd);
	close(pipefd[1]);
	if (bigdata->next && bigdata->next->log_op == OPP_PIPE)
		mk_pipes(bigdata->next, pipefd[0], super);
	close(pipefd[0]);
	pid = waitpid(pid, &error, WCONTINUED);
	set_exit_code(super, bigdata, error);
	return (1);
}

int	what_cmd2(t_tokens *bigdata, t_super *super)
{
	static int	stdio[2] = {0, 0};

	if (!stdio[0] || !stdio[1])
	{
		stdio[1] = dup(1);
		stdio[0] = dup(0);
	}
	if (!bigdata->next || bigdata->next->log_op != OPP_PIPE)
	{
		what_cmd1(bigdata, super, 0, 1);
		dup2(stdio[1], 1);
		dup2(stdio[0], 0);
		return (0);
	}
	block_signal();
	mk_pipes(bigdata, 0, super);
	set_signal_parrent();
	return (g_exit_code);
}
