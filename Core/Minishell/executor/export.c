/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/20 16:58:47 by jbax          #+#    #+#                 */
/*   Updated: 2023/05/08 19:16:15 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"

void	ft_put_export(t_list *envl, int fd)
{
	char	*s;

	while (envl)
	{
		ft_putstr_fd("declare -x ", fd);
		s = ft_env_name(envl->content);
		ft_putstr_fd(s, fd);
		free(s);
		if (ft_strchr(envl->content, '='))
		{
			ft_putstr_fd("=\"", fd);
			s = ft_env_content(envl->content);
			ft_putstr_fd(s, fd);
			ft_putstr_fd("\"", fd);
			free(s);
		}
		ft_putstr_fd("\n", fd);
		envl = envl->next;
	}
}

void	ft_export_no_arguments(char **env, int output_fd)
{
	t_list	*head;

	if (!*env)
		return ;
	head = ft_lstnew_ascii(env);
	if (!head)
		exit(1);
	ft_put_export(head, output_fd);
	(void)output_fd;
	ft_lstclear(&head, ft_not_free);
}

static int	is_valid(char *arg)
{
	if (ft_isdigit(*arg) || *arg == 0)
		return (1);
	while (ft_isalnum(*arg) || *arg == '_')
		arg++;
	if (*arg)
		return (1);
	return (0);
}

static void	checkandadd(t_super *super, char **args)
{
	int		index;
	char	*var;

	while (*args)
	{
		var = ft_env_name(*args);
		index = -1;
		if (is_valid(var))
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(*args, 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			g_exit_code = 1;
		}
		else
		{
			index = ft_env_index(super->env, *args);
			if (index != -1)
				super->env = ft_arrdell_index(super->env, index, free);
			super->env = ft_arradd_index(super->env, ft_strdup(*args), 100);
		}
		free(var);
		args++;
	}
}

void	ft_export(t_super *super, char **args, int output_fd)
{
	if (!args || !args[1])
		ft_export_no_arguments(super->env, output_fd);
	else
	{
		checkandadd(super, args + 1);
	}
}
