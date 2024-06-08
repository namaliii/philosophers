/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_think_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:10:34 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/08 21:04:37 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	decrement_meals(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->meals_mutex));
	philo->data->meals_no--;
	pthread_mutex_unlock(&(philo->data->meals_mutex));
}

int	meals_check(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->meals_mutex));
	if (philo->data->meals_no <= 0)
	{
		pthread_mutex_unlock(&(philo->data->meals_mutex));
		return(0);
	}
	else
	{
		pthread_mutex_unlock(&(philo->data->meals_mutex));
		return (1);
	}
}

void	eat_spaghetti(t_philo *philo)
{
	decrement_meals(philo);
	lock_print(philo, "is eating", get_time() - philo->data->start_time);
	ft_usleep(philo->data->eating_time);
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
