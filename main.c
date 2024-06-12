/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:47:42 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/11 18:47:27 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	main_thread_control(t_philo **philos_array)
{
	int	i;

	i = 0;
	while (philos_array[0]->data->philos_no != 1)
	{
		if (i == philos_array[i]->data->philos_no - 1)
			i = 0;
		if (dead_check(philos_array[i]) == 1)
			break ;
		else if (meals_check(philos_array[i]) == 0)
			break ;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_philo	**philos_array;
	t_data	*data;

	if (args_check(argc, argv) == 1)
		return (1);
	data = init_data(argv);
	philos_array = init_philos(argv, data);
	if (!data || !philos_array)
		return (1);
	pthread_mutex_lock(&data->main_mutex);
	create_threads(data->philos_no, philos_array);
	pthread_mutex_unlock(&data->main_mutex);
	main_thread_control(philos_array);
	join_threads(data->philos_no, philos_array);
	clean_up(philos_array);
	return (0);
}
