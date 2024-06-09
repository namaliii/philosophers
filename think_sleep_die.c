/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_sleep_die.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:19:55 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/09 18:44:01 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	dead_check(t_philo *philo)
{
    dprintf(2, "last meal time %ld\n", get_time() - philo->data->start_time - philo->last_meal);
	pthread_mutex_lock(&(philo->data->death_mutex));
	if (get_time() - philo->data->start_time - philo->last_meal
		>= philo->data->time_to_die)
	{
		pthread_mutex_unlock(&(philo->data->death_mutex));
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&(philo->data->death_mutex));
		return (0);
	}
}

void	think(t_philo *philo)
{
	lock_print(philo, "is thinking", get_time() - philo->data->start_time);
}

void	go_to_sleep(t_philo *philo)
{
	lock_print(philo, "is sleeping", get_time() - philo->data->start_time);
	ft_usleep(philo->data->sleep_time);
}
