/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:10:34 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/11 17:56:01 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	decrement_meals(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->main_mutex));
	if (philo->data->meals_no != 777)
		philo->data->meals_no--;
	pthread_mutex_lock(&philo->philo_mutex);
	philo->last_meal = get_time() - philo->data->start_time;
	pthread_mutex_unlock(&philo->philo_mutex);
	pthread_mutex_unlock(&(philo->data->main_mutex));
}

int	meals_check(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->main_mutex));
	if (philo->data->meals_no <= 0)
	{
		pthread_mutex_unlock(&(philo->data->main_mutex));
		return (0);
	}
	else
	{
		pthread_mutex_unlock(&(philo->data->main_mutex));
		return (1);
	}
}

void	eat_spaghetti(t_philo *philo)
{
	decrement_meals(philo);
	pthread_mutex_lock(&(philo->data->main_mutex));
	lock_print(philo, "is eating", get_time() - philo->data->start_time);
	pthread_mutex_unlock(&(philo->data->main_mutex));
	ft_usleep(philo->data->eating_time);
}
