/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_sleep_die.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:19:55 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/11 18:38:02 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	dead_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_mutex);
	if (get_time() - philo->data->start_time
		- philo->last_meal > philo->data->time_to_die)
	{
		pthread_mutex_unlock(&philo->philo_mutex);
		pthread_mutex_lock(&philo->data->main_mutex);
		lock_print(philo, "died", get_time() - philo->data->start_time);
		philo->data->someone_died = 1;
		pthread_mutex_unlock(&(philo->data->main_mutex));
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&philo->philo_mutex);
		return (0);
	}
}

void	think(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->main_mutex));
	lock_print(philo, "is thinking", get_time() - philo->data->start_time);
	pthread_mutex_unlock(&(philo->data->main_mutex));
}

void	go_to_sleep(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->main_mutex));
	lock_print(philo, "is sleeping", get_time() - philo->data->start_time);
	pthread_mutex_unlock(&(philo->data->main_mutex));
	ft_usleep(philo->data->sleep_time);
}
