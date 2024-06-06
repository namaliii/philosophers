/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:47:42 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/06 18:49:05 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	**philos_array;
	t_data	*data;
	int		i;

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
	return (0);
}
