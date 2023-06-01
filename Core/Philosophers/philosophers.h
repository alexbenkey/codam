/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/22 18:00:18 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/06/01 19:20:37 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				pos;
	pthread_mutex_t	l_fork;
	int				meals_eaten;
	struct s_super	*super;
	long long		last_meal;
	pthread_mutex_t	pause;
}	t_philo;

typedef struct s_super
{
	int				count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_meals;
	int				halt;
	long long		start_time;
	pthread_mutex_t	p_halt;
	struct s_philo	**philos;
}	t_super;

//parses the input data and returns a super struct containing the relevant vals
//returns NULL if parsing failed.
t_super		*parse_input(int argc, char **argv);

// converts a string into an integer value if it contains only numeric values. 
// will return 0 or -1 if the value falls out of bounds of an int
int			ft_atoi(const char *str);

//prints all the of the values in the super struct.
//stops printing when the value is less than 1.
void		print_all_values(t_super *super);

//generates an array of philosophers (pointers to tructs).
//the array is stored in super->philosophers.
//returns 0 if generation failed.
int			create_philos(t_super *super);

//the main function that is executed in each thread. 
//generates a philosopher and runs the simulation untill end conditions are met.
void		*routines(void *i);

//frees the pthread_mutex_t array forks allong with its content.
void		free_forks(pthread_mutex_t(**forks));

//runs individual routine for each philosopher.
void		*philo_life(void *philosopher);

// returns current time
long long	time_stmp(void);

// sleeps for 'ms' milliseconds
void		ft_usleep(int ms);

// print a string according to the specified format
void		print(t_philo *philo, char *str);

// sleep for the specified amount of ms
void		start_sleeping(t_philo *philo);

// return 1 if the halt value is set to 1;
int			check_halt(t_philo *philo);

// end routines if one of the philosophers has died or had enough meals
void		end_routines(t_super *super);

void		is_finished(t_philo *philo);

// eat for the specified amount of ms
void		start_eating(t_philo *philo);
#endif
