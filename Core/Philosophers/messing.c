/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   messing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 17:09:20 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/05/20 16:51:35 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_send{ 
	int 			*val;
	pthread_mutex_t	*lock
} t_send;


void	*myturn(void *arg)
{
	int *iptr = (int *)arg;
	for(int i=0; i < 8; i++)
	{
		sleep(1);
		pthread_mutex_lock(&lock);
		printf("my turn! %d, %d\n", i, *iptr);
		(*iptr)++;
		pthread_mutex_unlock(&lock);
	}
	return (iptr);
}

void	*yourturn(void *arg)
{
	int *iptr = (int *)arg;
	for(int i = 0; i < 3; i++)
	{
		sleep(1);
		pthread_mutex_lock(&lock);
		printf("your turn! %d, %d\n", i, *iptr);
		(*iptr)++;
		pthread_mutex_unlock(&lock);
	}
	return (iptr);
}

t_send *make_vals(int *v)
{
	t_send				*vals;
	//pthread_mutex_t		*lock_1 = pthread_mutex_init(NULL, NULL);
	int					*val;

	val = malloc(sizeof(int));
	val = &v;
	vals = (t_send *)malloc(sizeof(t_send));
	vals->val = val;
	//vals->lock = lock_1;
}

int	main(void)
{
	//pthread_mutex_t		lock = PTHREAD_MUTEX_INITIALIZER;
	pthread_t			newthread_1;
	pthread_t			newthread_2;
	pthread_mutex_t		lock_1 = PTHREAD_MUTEX_INITIALIZER;
	int					v;

	vals = (t_send *)malloc(sizeof(t_send));
	v = 5;
	pthread_create(&newthread_1, NULL, myturn, &vals);
	pthread_create(&newthread_2, NULL, yourturn, &vals);

	//causes the program to only exit once all threads have completed.
	pthread_join(newthread_1, NULL);
	pthread_join(newthread_2, NULL);
	printf("thead is done: v=%d", v);
}