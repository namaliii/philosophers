/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:47:42 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/06 17:39:01 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	**init_philos(char **argv, t_data *data)
{
	t_philo	**philos_array;
	int		philos_no;
	int		i;

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
		// pthread_create(philos_array[i]->philos_thread, NULL, &some_function, NULL);
		i++;
	}
	return (philos_array);
}

int	main(int argc, char **argv)
{
	t_philo	**philos_array;
	t_data	*data;
	int		i;

	i = 0;
	if (args_check(argc, argv) == 1)
		return (1);
	philos_array = init_philos(argv, data);
	if (philos_array == NULL)
		return (1);
	while (philos_array[i])
	{
		printf("ID: %d\n", philos_array[i]->id);
		i++;
	}
	return (0);
}
