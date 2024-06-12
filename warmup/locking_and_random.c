/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locking_and_random.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:40:16 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/12 12:36:34 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "philo.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

int	mails = 0;
pthread_mutex_t	mutex;

void*	routine()
{
	int	i;

	i = 0;
	while (i < 10000)
	{
		// pthread_mutex_lock(&mutex);
		mails++;
		// pthread_mutex_unlock(&mutex);
		i++;
	}
	return (NULL);
}

int	main(void)
{
	pthread_t		thread[8];
	int				i;
	unsigned int	seed;
	pid_t			pid;
	time_t			curr_time;

	pid = getpid();
	curr_time = time(NULL);
	seed = (unsigned int)curr_time + (unsigned int)pid;
	i = 0;
	pthread_mutex_init(&mutex, NULL);
	// srand(seed);
	// printf("Random number: %d\n", (rand() % 6) + 1);
	while (i < 8)
	{
		if (pthread_create(&thread[i], NULL, &routine, NULL) != 0)
		{
			perror("Failed to create a thread!");
			return (1);
		}
		printf("Thread %d has started\n", i);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		if (pthread_join(thread[i], NULL) != 0)
			return (2);
		printf("Thread %d has finished execution\n", i);
		i++;
	}
	pthread_mutex_destroy(&mutex);
	printf("Number of mails: %d\n", mails);
	return (0);
}

