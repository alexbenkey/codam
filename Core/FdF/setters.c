/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setters.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 19:22:06 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/12/02 21:34:34 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	set_next_to_current(t_data *data)
{
	data->next_x = data->current_x;
	data->next_y = data->current_y;
}

void	set_current_to_start(t_data *data)
{
	data->current_x = data->start_x;
	data->current_y = data->start_y;
}

void	set_current_to_next(t_data *data)
{
	data->current_x = data->next_x;
	data->current_y = data->next_y;
}
