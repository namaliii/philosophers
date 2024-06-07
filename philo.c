/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:47:42 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/07 20:04:54 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	**philos_array;
	t_data	*data;
	int		i;
	long time1;
	long time2;
	long time_slept;

	if (args_check(argc, argv) == 1)
		return (1);
	data = init_data();
	philos_array = init_philos(argv, data);
	if (!data || !philos_array)
		return (1);
	i = 0;
	while (philos_array[i])
	{
		printf("ID: %d\n", philos_array[i]->id);
		printf("Data: %d\n", philos_array[i]->data->test);
		i++;
	}
	// printf("time since 1970 in milliseconds: %ld\n", get_time());
	time1= get_time();
	ft_usleep(60);
	time2 = get_time();
	time_slept = time2 - time1;
	printf("time slept %ld\n", time_slept);
	return (0);
}
