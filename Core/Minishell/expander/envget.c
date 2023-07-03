/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   envget.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 17:50:01 by jbax          #+#    #+#                 */
/*   Updated: 2023/03/22 18:33:54 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"

char	*ft_getvar(char *ptr, char **env)
{
	int		i;
	char	*str;

	i = 0;
	while (ft_isalnum(ptr[i]) || ptr[i] == '_')
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, ptr, i + 1);
	i = ft_env_index(env, str);
	free(str);
	if (i != -1)
		str = ft_env_content(env[i]);
	else
		str = ft_strdup("");
	if (!str)
		return (0);
	return (str);
}

char	*ft_replacevar(char *head, int index, char **env)
{
	char	*tmp[3];

	tmp[0] = ft_strdup(head);
	if (!tmp[0])
		exit_errbug("malloc failed", "envget rep 0");
	tmp[0][index] = 0;
	index++;
	tmp[1] = ft_getvar(&head[index], env);
	if (!tmp[1])
		exit_errbug("malloc failed", "envget rep 1");
	if (ft_isdigit(head[index]))
		index++;
	else
	{
		while (ft_isalnum(head[index]) || head[index] == '_')
			index++;
	}
	tmp[2] = ft_strjoin3(tmp[0], tmp[1], &head[index]);
	if (!tmp[2])
		exit_errbug("malloc failed", "envget rep 2");
	free(tmp[0]);
	free(tmp[1]);
	free(head);
	return (tmp[2]);
}
