/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   manipulators.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 19:11:24 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/12/02 20:16:38 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	adjust_pos_downward(t_data *data)
{
	cover_image(data);
	data->start_y += 5;
	draw_lines(data);
}

void	adjust_pos_upward(t_data *data)
{
	cover_image(data);
	data->start_y -= 5;
	draw_lines(data);
}

void	adjust_pos_left(t_data *data)
{
	cover_image(data);
	data->start_x -= 5;
	draw_lines(data);
}

void	adjust_pos_right(t_data *data)
{
	cover_image(data);
	data->start_x += 5;
	draw_lines(data);
}
