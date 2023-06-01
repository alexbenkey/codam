/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/25 18:08:59 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/06/01 18:51:26 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	eat(t_philo *philo)
{
	long long	start_time;

	print(philo, "is eating");
	start_time = time_stmp();
	ft_usleep(philo->super->time_to_eat);
}

void	start_eating(t_philo *philo)
{
	if (philo->pos == (philo->super->count - 1))
		pthread_mutex_lock(&(philo->super->philos[0]->l_fork));
	else
		pthread_mutex_lock(&(philo->super->philos[philo->pos + 1]->l_fork));
	print(philo, "has taken a fork");
	pthread_mutex_lock(&(philo->l_fork));
	print(philo, "has taken a fork");
	pthread_mutex_lock(&philo->pause);
	philo->meals_eaten++;
	philo->last_meal = time_stmp();
	pthread_mutex_unlock(&philo->pause);
	if (!philo->super->halt)
		eat(philo);
	pthread_mutex_unlock(&(philo->l_fork));
	if (philo->pos == (philo->super->count - 1))
		pthread_mutex_unlock(&(philo->super->philos[0]->l_fork));
	else
		pthread_mutex_unlock(&(philo->super->philos[philo->pos + 1]->l_fork));
}

void	start_sleeping(t_philo *philo)
{
	print(philo, "is sleeping");
	ft_usleep(philo->super->time_to_eat);
}

void	is_finished(t_philo *philo)
{
	if (philo->last_meal == 0)
			philo->last_meal = time_stmp();
	if ((time_stmp() - philo->last_meal) > philo->super->time_to_die)
	{
		pthread_mutex_lock(&philo->super->p_halt);
		printf("\033[0;36m");
		print(philo, "has died");
		printf("\033[0;0m");
		philo->super->halt = 1;
		exit (0);
		pthread_mutex_unlock(&philo->super->p_halt);
	}
	if (philo->meals_eaten >= philo->super->number_of_meals \
				&& philo->super->number_of_meals > 0)
	{
		pthread_mutex_lock(&philo->super->p_halt);
		printf("\033[0;32m");
		print(philo, "has exceeded the max number of meals");
		printf("\033[0;0m");
		philo->super->halt = 1;
		exit (0);
		pthread_mutex_unlock(&philo->super->p_halt);
	}
}

void	end_routines(t_super *super)
{
	int	i;

	while (!super->halt)
	{
		i = 0;
		while (i < super->count)
			is_finished(super->philos[i++]);
	}
}
