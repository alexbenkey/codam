/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cd.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/18 17:28:27 by jbax          #+#    #+#                 */
/*   Updated: 2023/05/05 19:28:50 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"
#define _POSIX_SOURCE

static void	get_path(t_super *super)
{
	char	*cwd;
	char	*len;
	char	**arr;

	arr = NULL;
	arr = ft_arradd_index(arr, ft_strdup("export"), 0);
	arr = ft_arradd_index(arr, ft_strdup("OLDPWD=$PWD"), 1);
	arr = arr_expander(arr, super->env, 0);
	ft_export(super, arr, 1);
	cwd = getcwd(0, 0);
	if (!cwd)
		g_exit_code = 1;
	len = ft_strjoin("PWD=", cwd);
	free(cwd);
	free(arr[1]);
	arr[1] = len;
	ft_export(super, arr, 1);
	ft_arrclear_c(arr, ft_arrlen_c(arr));
}

static char	*get_oldpwd(char **env)
{
	int		i;
	char	*home;

	home = NULL;
	i = ft_env_index(env, "OLDPWD");
	if (i == -1)
	{
		ft_putstr_fd("minishell: cd: OLDPWD not set\n", 1);
		g_exit_code = 1;
		return (0);
	}
	home = ft_env_content(env[i]);
	if (home)
		ft_putendl_fd(home, 1);
	return (home);
}

static char	*get_home(char **env)
{
	int		i;
	char	*home;

	home = NULL;
	i = ft_env_index(env, "HOME");
	if (i == -1)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 1);
		g_exit_code = 1;
		return (0);
	}
	home = ft_env_content(env[i]);
	return (home);
}

static char	*cd_cases(char **args, t_super *super)
{
	char	*path;

	if (!args || !args[1])
	{
		path = get_home(super->env);
		if (!path)
			return (0);
	}
	else if (args && args[1][0] == '-' && !args[1][1])
	{
		path = get_oldpwd(super->env);
		if (!path)
			return (0);
	}
	else if (args && args[1])
		path = ft_strdup(args[1]);
	else
		return (0);
	return (path);
}

int	ft_change_dir(char **args, t_super *super)
{
	int		i;
	char	*path;

	i = 0;
	path = cd_cases(args, super);
	if (!path)
		return (0);
	if (path[0])
		i = chdir(path);
	if (i == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		g_exit_code = 1;
	}
	else
		get_path(super);
	if (path)
		free(path);
	return (0);
}
