/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   environment.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/20 17:05:02 by jbax          #+#    #+#                 */
/*   Updated: 2023/04/13 18:07:25 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../headers/builtins_data_struct.h"

char	**copy_env(char **env)
{
	int		len;
	char	**dest;

	len = ft_arrlen_c(env);
	dest = ft_arrdup_c(env, len);
	if (!dest)
		exit(0);
	return (dest);
}

char	*ft_env_name(char *env)
{
	char	*temp;

	env = ft_strdup(env);
	if (!env)
		exit(1);
	temp = ft_strchr(env, '=');
	if (temp)
		ft_bzero(temp, 1);
	return (env);
}

char	*ft_env_content(char *env)
{
	char	*temp;

	temp = ft_strchr(env, '=');
	if (!temp)
	{
		env = ft_strdup("");
		return (env);
	}
	env = ft_strdup(&temp[1]);
	return (env);
}

int	ft_env_index(char **env, char *var)
{
	char	*d;
	int		index;
	int		i;

	i = 0;
	var = ft_env_name(var);
	d = ft_arrnstr(&env[i], var, &index);
	while (d)
	{
		d = ft_env_name(d);
		if (!ft_strncmp(var, d, ft_strlen(d)))
		{
			free(var);
			free(d);
			return (i + index);
		}
		i += index + 1;
		free(d);
		d = ft_arrnstr(&env[i], var, &index);
	}
	free(d);
	free(var);
	return (-1);
}

void	ft_put_env(t_super *super, int fd)
{
	char	**env;

	env = super->env;
	while (*env)
	{
		if (ft_strchr(*env, '='))
			ft_putendl_fd(*env, fd);
		env++;
	}
}
