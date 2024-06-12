/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_thread_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:20:48 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/04 16:14:35 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

pthread_mutex_t	mutex;
int value = 0;

void	*roll_dice()
{
	pthread_mutex_lock(&mutex);
	value = (rand() % 6) + 1;
	printf("Random value: %d\n", value);
	pthread_mutex_unlock(&mutex);
	return ((void*)(intptr_t)value);
}

int	main(void)
{
	int	i;

	i = 0;
	pthread_t thread[8];
	pthread_mutex_init(&mutex, NULL);
	while (i < 8)
	{
		printf("Thread %d has started\n", i);
		if (pthread_create(&thread[i], NULL, &roll_dice, NULL) != 0)
		{
			perror("Failed to create a thread!");
			return (1);
		}
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
	// pthread_mutex_destroy(&mutex);
	// printf("Number of mails: %d\n", mails);
	// printf("Main result address: %p\n", res);
	// printf("Result: %d\n", *res);
	// free(res);
	pthread_mutex_destroy(&mutex);
	return (0);
}
