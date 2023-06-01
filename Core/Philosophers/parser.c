/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/13 18:17:03 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/06/01 15:10:13 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_super	*parse_input(int argc, char **argv)
{
	t_super	*super;
	int		i;

	i = 0;
	super = malloc(sizeof(t_super));
	super->count = ft_atoi(argv[1]);
	super->time_to_die = ft_atoi(argv[2]);
	super->time_to_eat = ft_atoi(argv[3]);
	super->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		super->number_of_meals = ft_atoi(argv[5]);
	else
		super->number_of_meals = 0;
	super->philos = malloc(sizeof(t_philo *) * (super->count));
	pthread_mutex_init(&super->p_halt, NULL);
	super->halt = 0;
	super->start_time = 0;
	return (super);
}
