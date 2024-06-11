/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:45:33 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/11 18:46:53 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	create_threads(int philos_no, t_philo **philos_array)
{
	int	i;

	i = 0;
	while (i < philos_no)
	{
		if (pthread_create(&(philos_array[i]->thread),
				NULL, &routine, philos_array[i]) != 0)
			perror("Failed to create a thread\n");
		i++;
	}
}

void	join_threads(int philos_no, t_philo **philos_array)
{
	int	i;

	i = 0;
	while (i < philos_no)
	{
		if (pthread_join(philos_array[i]->thread, NULL) != 0)
		{
			perror("Failed to join a thread\n");
			return ;
		}
		i++;
	}
}
