/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:47:05 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/08 19:02:11 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	lock_print(t_philo *philo, char *msg, long time)
{
	pthread_mutex_lock(&(philo->print));
	printf("%lu %d %s\n", time, philo->id, msg);
	pthread_mutex_unlock(&(philo->print));
}

void	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->right_fork));
	lock_print(philo, "has taken a right fork", get_time() - philo->data->start_time);
}

void	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	lock_print(philo, "has taken a left fork", get_time() - philo->data->start_time);
}

void	leave_right_fork(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->right_fork));
	lock_print(philo, "has released the right fork", get_time() - philo->data->start_time);
}

void	leave_left_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	lock_print(philo, "has released the left fork", get_time() - philo->data->start_time);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	take_right_fork(philo);
	take_left_fork(philo);
	leave_right_fork(philo);
	leave_left_fork(philo);
	return (NULL);
}

void	assign_forks(t_philo **philos_array)
{
	int	i;
	int number_philos;

	i = 0;
	number_philos = philos_array[0]->data->philos_no;
	if (number_philos != 1)
	{
		while (i < number_philos - 1)
		{
			philos_array[i + 1]->left_fork = &(philos_array[i]->right_fork);
			i++;
		}
		philos_array[0]->left_fork = &(philos_array[number_philos - 1]->right_fork);
	}
}

void	create_threads(int philos_no, t_philo **philos_array)
{
	int	i;

	i = 0;
	while (i < philos_no)
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
	// while (philos_no != 1 && i < philos_no)
	// {
	// 	if (pthread_join(philos_array[i]->thread, NULL) != 0)
	// 	{
	// 		perror("Failed to join a thread\n");
	// 		return ;
	// 	}
	// 	printf("Thread %d has finished execution\n", (i + 1));
	// 	i++;
	// }
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
		philos_array[i]->id = i + 1;
		philos_array[i]->data = data;
		pthread_mutex_init(&(philos_array[i]->right_fork), NULL);
		i++;
	}
	assign_forks(philos_array);
	return (philos_array);
}

t_data	*init_data(char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->meals_no = -1;
	data->philos_no = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->eating_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	data->start_time = get_time();
	if (argv[5])
		data->meals_no = ft_atoi(argv[5]);
	return (data);
}
