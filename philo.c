/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:47:42 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/09 16:30:21 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	create_threads(data->philos_no, philos_array);
	return (0);
}
