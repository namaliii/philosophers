/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:55:58 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/11 18:36:21 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	lock_print(t_philo *philo, char *msg, long time)
{
	pthread_mutex_lock(&philo->philo_mutex);
	if (philo->data->someone_died == 0)
		printf("%lu %d %s\n", time, philo->id, msg);
	pthread_mutex_unlock(&philo->philo_mutex);
}

int	single_philo(t_philo *philo)
{
	if (philo->data->philos_no == 1)
	{
		pthread_mutex_lock(&philo->data->main_mutex);
		lock_print(philo, "has taken a fork", get_time()
			- philo->data->start_time);
		pthread_mutex_unlock(&philo->data->main_mutex);
		ft_usleep(philo->data->time_to_die);
		pthread_mutex_lock(&philo->data->main_mutex);
		lock_print(philo, "died", get_time() - philo->data->start_time);
		pthread_mutex_unlock(&philo->data->main_mutex);
		return (1);
	}
	return (0);
}

void	even_odd_routine(t_philo *philo)
{
	if (philo->id % 2 == 1)
	{
		pick_forks(philo);
		eat_spaghetti(philo);
		drop_forks(philo);
		go_to_sleep(philo);
		think(philo);
	}
	else
	{
		go_to_sleep(philo);
		think(philo);
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->main_mutex);
	pthread_mutex_unlock(&philo->data->main_mutex);
	if (single_philo(philo) == 1)
		return (NULL);
	even_odd_routine(philo);
	while (meals_check(philo) == 1)
	{
		pthread_mutex_lock(&philo->data->main_mutex);
		if (philo->data->someone_died == 1 || philo->data->meals_no <= 0)
		{
			pthread_mutex_unlock(&philo->data->main_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->data->main_mutex);
		pick_forks(philo);
		eat_spaghetti(philo);
		drop_forks(philo);
		go_to_sleep(philo);
		think(philo);
	}
	return (NULL);
}
