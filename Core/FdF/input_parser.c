/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_parser.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 00:28:39 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/11/07 23:55:48 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_plist	*get_map(char *map)
{
	t_plist	*top;
	int		fd;
	char	*line;
	char	**points;
	int		y;

	top = 0;
	y = 0;
	fd = open(map, O_RDONLY);
	if (!map)
		error_exit();
	line = get_next_line(fd);
	while (line)
	{
		points = ft_split(line, ' ');
		top = fill_list(top, points, y);
		line = get_next_line(fd);
		y++;
	}
	return (top);
}

t_plist	*fill_list(t_plist *top, char **points, int y)
{
	t_plist	*new;
	int		x;
	int		i;

	i = 0;
	x = 0;
	while (points[x])
	{
		if (!top)
			top = fdf_lstnew(x, y, ft_atoi(points[x]));
		else
		{
			new = fdf_lstnew(x, y, ft_atoi(points[x]));
			fdf_lstadd_back(&top, new);
		}
		x++;
	}
	return (top);
}

void	error_exit(void)
{
	ft_printf("\nan error occured, program was exited\n");
	exit(0);
}

t_plist	*fdf_lstnew(int x, int y, int z)
{
	t_plist	*tmp;

	tmp = malloc(sizeof(t_plist));
	if (tmp)
	{
		tmp->i_x = x;
		tmp->i_y = y;
		tmp->z = z;
		tmp->c_x = 0;
		tmp->c_y = 0;
		tmp->next = 0;
	}
	return (tmp);
}

void	fdf_lstadd_back(t_plist **lst, t_plist *new)
{
	t_plist	*current;

	current = *lst;
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	while (current->next != 0)
	{
		current = current->next;
	}
	current->next = new;
}
