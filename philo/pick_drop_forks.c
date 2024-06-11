/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_drop_forks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:53:25 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/11 18:29:04 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	pick_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&(philo->right_fork));
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(&philo->data->main_mutex);
		lock_print(philo, "has taken a fork", get_time()
			- philo->data->start_time);
		lock_print(philo, "has taken a fork", get_time()
			- philo->data->start_time);
		pthread_mutex_unlock(&philo->data->main_mutex);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(&(philo->right_fork));
		pthread_mutex_lock(&philo->data->main_mutex);
		lock_print(philo, "has taken a fork", get_time()
			- philo->data->start_time);
		lock_print(philo, "has taken a fork", get_time()
			- philo->data->start_time);
		pthread_mutex_unlock(&philo->data->main_mutex);
	}
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->right_fork));
	pthread_mutex_unlock(philo->left_fork);
}
