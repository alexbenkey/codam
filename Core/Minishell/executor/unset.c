/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/29 14:35:03 by jbax          #+#    #+#                 */
/*   Updated: 2023/03/22 18:36:47 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"

static int	is_valid(char *arg)
{
	if (ft_isdigit(*arg))
		return (1);
	while (ft_isalnum(*arg) || *arg == '_')
		arg++;
	if (*arg)
		return (1);
	return (0);
}

static void	check_for_dell(t_super *super, char **args)
{
	int	index;

	while (*args)
	{
		index = -1;
		if (is_valid(*args))
		{
			ft_putstr_fd("minishel: unset: `", 2);
			ft_putstr_fd(*args, 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			g_exit_code = 1;
		}
		else
			index = ft_env_index(super->env, *args);
		if (index != -1)
			super->env = ft_arrdell_index(super->env, index, free);
		args++;
	}
}

void	ft_unset(t_super *super, char **arg)
{
	check_for_dell(super, arg + 1);
}

char	*singlearg(char *arg, int *index)
{
	int		i;
	int		j;
	int		k;
	char	*dest;

	if (!arg[*index])
		return (NULL);
	i = *index;
	j = 0;
	k = 0;
	while (arg[*index] && !j)
	{
		if (arg[*index] == '"')
			k++;
		if (ft_iswhite_space(arg[*index]) && (k % 2) == 0)
			j = 1;
		*index += 1;
	}
	if ((k % 2))
		return (NULL);
	if (ft_iswhite_space(arg[i]))
		return ("\0");
	dest = ft_calloc((*index - i) + 1, 1);
	ft_strlcpy(dest, &arg[i], (*index - i - j) + 1);
	return (dest);
}
