/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   generation.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 15:36:35 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/06/01 19:04:28 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// get this to take the superstruct, derive pos from generated.
// store new philo in philosophers[i] and store super in philo->super;

int	check_halt(t_philo *philo)
{
	if (time_stmp() - philo->last_meal >= philo->super->time_to_die)
	{
		pthread_mutex_lock(&philo->pause);
		philo->super->halt++;
		pthread_mutex_unlock(&philo->pause);
		return (1);
	}
	if (philo->super->halt > 0)
		return (1);
	return (0);
}

void	*philo_life(void *philosopher)
{
	t_philo		*philo;

	philo = (t_philo *)philosopher;
	if (philo->pos % 2 == 0)
		ft_usleep(philo->super->time_to_eat / 2);
	if (!philo->last_meal)
		philo->last_meal = time_stmp();
	while (!philo->super->halt)
	{
		start_eating(philo);
		if (!philo->super->halt)
			start_sleeping(philo);
		if (!philo->super->halt)
			print(philo, "is thinking");
	}
	return (NULL);
}

void	*routines(void *superstruct)
{
	t_super		*super;
	int			i;
	pthread_t	*threads;

	i = 0;
	super = (t_super *)superstruct;
	threads = malloc(sizeof(pthread_t) * (super->count));
	super->start_time = time_stmp();
	while (i < super->count)
	{		
		pthread_create(threads + i, NULL, &philo_life, super->philos[i]);
		i++;
	}
	i = 0;
	end_routines(super);
	i = 0;
	while (i < super->count)
		pthread_join(threads[i++], NULL);
	return (NULL);
}

int	create_philos(t_super *super)
{
	int			i;

	i = 0;
	while (i < (super->count))
	{	
		super->philos[i] = malloc(sizeof(t_philo));
		super->philos[i]->super = super;
		pthread_mutex_init(&super->philos[i]->l_fork, NULL);
		pthread_mutex_init(&super->philos[i]->pause, NULL);
		super->philos[i]->pos = i;
		super->philos[i]->meals_eaten = 0;
		super->philos[i]->last_meal = 0;
		i++;
	}
	return (1);
}
