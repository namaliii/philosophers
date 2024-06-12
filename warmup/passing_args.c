/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   passing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:27:32 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/04 18:50:38 by anamieta         ###   ########.fr       */
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

	index = *(int *)arg;
	printf("%d ", primes[index]);
	free(arg);
	return (NULL);
}

int	main(void)
{
	pthread_t	thread[10];
	int			i;

	i = 0;
	while (i < 10)
	{
		int *a = malloc(sizeof(int));
		if (!a)
		{
			perror("Memory allocation failed\n");
			return (1);
		}
		*a = i;
		if (pthread_create(&thread[i], NULL, &routine, a) != 0)
		{
			perror("Failed to create thread");
			free(a);
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (pthread_join(thread[i], NULL) != 0)
			perror("Failed to join thread");
		i++;
	}
	return (0);
}
