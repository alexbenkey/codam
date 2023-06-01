/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 13:15:19 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/06/01 19:06:53 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	cleaner(t_super *super)
{
	int	i;

	i = 0;
	while (i < super->count)
	{
		pthread_mutex_destroy(&super->philos[i]->pause);
		pthread_mutex_destroy(&super->philos[i]->l_fork);
		free(super->philos[i]->super);
		free(super->philos[i]);
		free(super);
		i++;
	}
	return (0);
}

int	not_all_ints(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_super	*super;

	super = NULL;
	if (!(argc < 5 || argc > 6 || not_all_ints(argv)))
	{
		super = parse_input(argc, argv);
		create_philos(super);
		routines(super);
		cleaner(super);
	}
	else
		printf("bad input\nplease use: ./philosophers [tim_to_die] \
[time_to_eat] [time_to_sleep] [number of meals(optional)] ");
	return (0);
}
