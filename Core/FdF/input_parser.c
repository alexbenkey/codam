/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_parser.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 00:28:39 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/30 01:37:19 by avon-ben      ########   odam.nl         */
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

	top = NULL;
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
		{
			top = fdf_lstnew(x, y, ft_atoi(points[x]));
			//ft_printf("coordinate %i: x: %i y: %i z: %i\n", i++, top->x, top->y, top->z);
		}
		else
		{
			new = fdf_lstnew(x, y, ft_atoi(points[x]));
			fdf_lstadd_back(&top, new);
			//ft_printf("coordinate %i: x: %i y: %i z: %i\n", i++, new->x, new->y, new->z);
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
		tmp->x = x;
		tmp->y = y;
		tmp->z = z;
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
