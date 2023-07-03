/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   adjusters_2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 19:31:52 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/12/02 19:32:03 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	adjust_z_offset_increase(t_data *data)
{
	cover_image(data);
	data->z_offset += 5;
	draw_lines(data);
}

void	adjust_z_offset_decrease(t_data *data)
{
	cover_image(data);
	data->z_offset -= 5;
	draw_lines(data);
}

void	adjust_z_offset_mult(t_data *data)
{
	cover_image(data);
	data->z_offset *= 1.1;
	draw_lines(data);
}

void	adjust_z_offset_devide(t_data *data)
{
	cover_image(data);
	data->z_offset *= 0.9;
	draw_lines(data);
}
