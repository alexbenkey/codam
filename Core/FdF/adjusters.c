/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   adjusters.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 19:19:15 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/12/02 20:14:55 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	adjust_right(t_data *data)
{
	adjust_x(data, 'r');
	adjust_y(data, 'd');
}

void	adjust_left(t_data *data)
{
	adjust_x(data, 'l');
	adjust_y(data, 'd');
}

void	adjust_reset(t_data *data)
{
	adjust_x(data, 's');
	adjust_y(data, 's');
}

void	adjust_x(t_data *data, char dir)
{
	if (dir == 'l')
		data->current_x -= data->interval;
	if (dir == 'r')
		data->current_x += data->interval;
	if (dir == 's')
		data->current_x = data->start_x;
}

void	adjust_y(t_data *data, char dir)
{
	double	adjusted;

	adjusted = data->interval * tan((data->angle) * (PI / 180));
	if (dir == 'd')
		data->current_y += adjusted;
	if (dir == 'u')
		data->current_y -= adjusted;
	if (dir == 's')
		data->current_y = data->start_y;
}
