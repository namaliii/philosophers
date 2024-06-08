/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:47:42 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/07 21:52:10 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	**philos_array;
	t_data	*data;
	// int		i;
	// long time1;
	// long time2;
	// long time_slept;

	if (args_check(argc, argv) == 1)
		return (1);
	data = init_data(argv);
	philos_array = init_philos(argv, data);
	if (!data || !philos_array)
		return (1);
	create_threads(data->philos_no, philos_array);
	// printf("im here 00\n");
	// i = 0;
	// time1 = get_time();
	// ft_usleep(60);
	// time2 = get_time();
	// time_slept = time2 - time1;
	// printf("time slept %ld\n", time_slept);
	return (0);
}
