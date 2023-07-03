/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_line_tools.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 19:06:18 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/12/02 20:15:22 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

double	get_gradient(t_two_points *ttp)
{
	double	x_dif;
	double	y_dif;
	double	gradient;

	x_dif = ttp->x2 - ttp->x1;
	if (x_dif == 0)
		return (9999);
	y_dif = ttp->y2 - ttp->y1;
	if (x_dif == 0 && y_dif == 0)
		return (9999);
	gradient = y_dif / x_dif;
	if (x_dif < 0)
		switch_c(ttp);
	return (gradient);
}

void	switch_c(t_two_points *ttp)
{
	double	temp;

	temp = ttp->x1;
	ttp->x1 = ttp->x2;
	ttp->x2 = temp;
	temp = ttp->y1;
	ttp->y1 = ttp->y2;
	ttp->y2 = temp;
}

void	re_init(t_data *data, t_two_points *ttp)
{
	data->current_x = data->start_x;
	data->current_y = data->start_y;
	data->next_x = data->start_x;
	data->next_y = data->start_y;
	ttp->x1 = data->start_x;
	ttp->y1 = data->start_y;
	ttp->x2 = data->start_x;
	ttp->y2 = data->start_y;
}

void	draw_line_x_base(t_data *data, t_two_points *ttp, double g)
{
	double	tmp_point_x;
	double	tmp_point_y;

	tmp_point_x = ttp->x1;
	tmp_point_y = ttp->y1;
	while (tmp_point_x < ttp->x2)
	{
		draw_wrapper_pix(data, tmp_point_x++, tmp_point_y);
		tmp_point_y += g;
	}
}

void	draw_line_y_base(t_data *data, t_two_points *ttp, double g)
{
	double	tmp_point_x;
	double	tmp_point_y;

	tmp_point_x = ttp->x1;
	tmp_point_y = ttp->y1;
	if (g < 0)
	{
		switch_c(ttp);
		g *= -1;
		while (tmp_point_y > ttp->y1)
		{
			draw_wrapper_pix(data, tmp_point_x, tmp_point_y--);
			tmp_point_x += (1 / g);
		}
	}
	else
	{
		while (tmp_point_y <= ttp->y2)
		{
			draw_wrapper_pix(data, tmp_point_x, tmp_point_y++);
			tmp_point_x += (1 / g);
		}
	}
}
