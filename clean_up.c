/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:28:05 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/11 17:41:51 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	clean_up(t_philo **philos_array)
{
	int	i;
	int	philos_no;

	i = 0;
	philos_no = philos_array[i]->data->philos_no;
	pthread_mutex_destroy(&(philos_array[i]->data->main_mutex));
	free(philos_array[i]->data);
	while (i < philos_no - 1)
	{
		pthread_mutex_destroy(&(philos_array[i]->right_fork));
		pthread_mutex_destroy(&(philos_array[i]->philo_mutex));
		free(philos_array[i]);
		i++;
	}
	free(philos_array);
}
