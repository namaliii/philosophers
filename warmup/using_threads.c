/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:27:32 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/04 19:15:08 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

int	primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void	*routine(void *arg)
{
	int	index;
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	index = *(int *)arg;
	while (i < 5)
	{
		sum += primes[index + i];
		i++;
	}
	printf("Local sum: %d\n", sum);
	*(int *)arg = sum;
	return (arg);
}

int	main(void)
{
	pthread_t	thread[10];
	int			i;
	int 		globalSum;

	i = 0;
	while (i < 2)
	{
		int *a = malloc(sizeof(int));
		if (!a)
		{
			perror("Memory allocation failed\n");
			return (1);
		}
		*a = i * 5;
		if (pthread_create(&thread[i], NULL, &routine, a) != 0)
		{
			perror("Failed to create thread");
			free(a);
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < 2)
	{
		// void *r;
		int *r;
		if (pthread_join(thread[i], (void**)&r) != 0)
			perror("Failed to join thread");
		// else
		// {
			// int	*result = (int *)r;
			// globalSum += *result;
			globalSum += *r;
			free(r);
		// }
		i++;
	}
	printf("Global sum: %d\n", globalSum);
	return (0);
}
