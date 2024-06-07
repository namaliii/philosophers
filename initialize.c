/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:47:05 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/07 19:05:52 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("Thread created for: %d\n", philo->id);
	return (NULL);
}

void	assign_forks(t_philo **philos_array)
{
	int	i;

	i = 1;
	while (philos_array[i])
	{
		if (philos_array[i + 1])
			philos_array[i + 1]->left_fork = &(philos_array[i]->right_fork);
		else
			philos_array[0]->left_fork = &(philos_array[i]->right_fork);
		i++;
	}
}

void	create_threads(int philos_no, t_philo **philos_array)
{
	int	i;

	i = 0;
	while (philos_no != 1 && i < philos_no)
	{
		if (pthread_create(&(philos_array[i]->thread),
				NULL, &routine, philos_array[i]) != 0)
		{
			perror("Failed to create a thread\n");
			return ;
		}
		i++;
	}
	i = 0;
	while (philos_no != 1 && i < philos_no)
	{
		if (pthread_join(philos_array[i]->thread, NULL) != 0)
		{
			perror("Failed to join a thread\n");
			return ;
		}
		printf("Thread %d has finished execution\n", (i + 1));
		i++;
	}
}

t_philo	**init_philos(char **argv, t_data *data)
{
	t_philo	**philos_array;
	int		philos_no;
	int		i;

	if (!data)
		return (NULL);
	philos_no = ft_atoi(argv[1]);
	philos_array = malloc(philos_no * sizeof(t_philo));
	if (!philos_array)
		return (NULL);
	i = 0;
	while (i < philos_no)
	{
		philos_array[i] = malloc(sizeof(t_philo));
		if (!philos_array[i])
			return (NULL);
		pthread_mutex_init(&(philos_array[i]->right_fork), NULL);
		philos_array[i]->id = i + 1;
		philos_array[i]->data = data;
		i++;
	}
	assign_forks(philos_array);
	create_threads(philos_no, philos_array);
	return (philos_array);
}

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->test = 777;
	return (data);
}
