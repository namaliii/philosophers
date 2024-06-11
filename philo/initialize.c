/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:47:05 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/11 18:45:27 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	assign_forks(t_philo **philos_array)
{
	int	i;
	int	number_philos;

	i = 0;
	number_philos = philos_array[0]->data->philos_no;
	if (number_philos != 1)
	{
		while (i < number_philos - 1)
		{
			philos_array[i + 1]->left_fork = &(philos_array[i]->right_fork);
			i++;
		}
		philos_array[0]->left_fork
			= &(philos_array[number_philos - 1]->right_fork);
	}
}

void	init_philo_helper(t_philo **philos_array, t_data *data, int philos_no)
{
	int	i;

	i = 0;
	while (i < philos_no)
	{
		philos_array[i] = malloc(sizeof(t_philo));
		if (!philos_array[i])
			return ;
		philos_array[i]->id = i + 1;
		philos_array[i]->data = data;
		philos_array[i]->last_meal = 0;
		pthread_mutex_init(&(philos_array[i]->philo_mutex), NULL);
		pthread_mutex_init(&(philos_array[i]->right_fork), NULL);
		philos_array[i]->left_fork = NULL;
		i++;
	}
}

t_philo	**init_philos(char **argv, t_data *data)
{
	t_philo	**philos_array;
	int		philos_no;

	if (!data)
		return (NULL);
	philos_no = ft_atoi(argv[1]);
	philos_array = malloc(philos_no * sizeof(t_philo));
	if (!philos_array)
		return (NULL);
	init_philo_helper(philos_array, data, philos_no);
	assign_forks(philos_array);
	return (philos_array);
}

t_data	*init_data(char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->meals_no = 777;
	data->philos_no = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->eating_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	data->start_time = get_time();
	data->someone_died = 0;
	pthread_mutex_init(&(data->main_mutex), NULL);
	if (argv[5])
		data->meals_no = ft_atoi(argv[5]) * data->philos_no;
	return (data);
}
