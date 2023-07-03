/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zoom_adjusters.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 20:33:49 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/12/02 20:37:26 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	zoom_in(t_data *data)
{
	cover_image(data);
	data->interval *= 1.2;
	draw_lines(data);
}

void	zoom_out(t_data *data)
{
	cover_image(data);
	data->interval *= 0.8;
	draw_lines(data);
}
