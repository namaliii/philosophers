/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:55:58 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/08 21:28:03 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_id_is_even(t_philo *philo)
{
	if (philo->id % 2 == 0)
		return (1);
	else
		return (0);
}

void	lock_print(t_philo *philo, char *msg, long time)
{
	pthread_mutex_lock(&(philo->data->print_mutex));
	printf("%lu %d %s\n", time, philo->id, msg);
	pthread_mutex_unlock(&(philo->data->print_mutex));
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (meals_check(philo) == 1)
	{
		// if (philo->id % 2 != 0)
		// 	ft_usleep(1);
		take_right_fork(philo);
		take_left_fork(philo);
		eat_spaghetti(philo);
		leave_right_fork(philo);
		leave_left_fork(philo);
		go_to_sleep(philo);
		think(philo);
	}
	return (NULL);
}
