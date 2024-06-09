/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_drop_forks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:53:25 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/09 18:16:31 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->right_fork));
	lock_print(philo, "has taken a right fork",
		get_time() - philo->data->start_time);
}

void	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	lock_print(philo, "has taken a left fork",
		get_time() - philo->data->start_time);
}

void	leave_right_fork(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->right_fork));
}

void	leave_left_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
}
