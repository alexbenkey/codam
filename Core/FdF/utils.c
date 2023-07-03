/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/18 16:30:08 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/12/02 21:34:56 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	has_char(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	get_z_val(char *line)
{
	char	**spl_ret;
	int		val;

	if (has_char(line, ','))
	{
		spl_ret = ft_split(line, ',');
		val = ft_atoi(spl_ret[0]);
		free_splitted(spl_ret);
	}
	else
		val = ft_atoi(line);
	return (val);
}

void	free_splitted(char **spl)
{
	int	i;

	while (spl[i])
	{
		free (spl[i]);
		i++;
	}
	free (spl);
}

unsigned int	double_adjuster(float value)
{
	int	y;
	int	int_cpy;

	int_cpy = value;
	if ((value - int_cpy) >= 0.5)
		y = int_cpy + 1;
	else
		y = int_cpy;
	return (y);
}

void	free_all(t_data *data)
{
	int	y;

	y = 0;
	while (y < data->height)
	{
		free(data->points[y]);
		y++;
	}
	free(data->points);
	free(data);
}
