/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/13 19:04:31 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/06/01 19:20:50 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print(t_philo *philo, char *str)
{
	long long	timestamp;

	if (philo->pos % 2 == 0)
		printf("\033[0;31m");
	if (!philo->super->halt)
	{
		timestamp = (time_stmp() - philo->super->start_time);
		printf("ms: %lld, philo %d, %s  \n", timestamp, philo->pos, str);
	}
	printf("\033[0m");
}

void	ft_usleep(int ms)
{
	long long	start_time;

	start_time = time_stmp();
	while ((time_stmp() - start_time) < ms)
		usleep(100);
}

long long	time_stmp(void)
{
	struct timeval	tp;
	long long		time;

	gettimeofday(&tp, NULL);
	time = (tp.tv_sec * 1000 + tp.tv_usec / 1000);
	return (time);
}
