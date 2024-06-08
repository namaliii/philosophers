/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:55:58 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/08 20:10:55 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	lock_print(t_philo *philo, char *msg, long time)
{
	pthread_mutex_lock(&(philo->data->print));
	printf("%lu %d %s\n", time, philo->id, msg);
	pthread_mutex_unlock(&(philo->data->print));
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		take_right_fork(philo);
		take_left_fork(philo);
        eat_spaghetti(philo);
		leave_right_fork(philo);
		leave_left_fork(philo);
		think(philo);
		go_to_sleep(philo);
	}
	return (NULL);
}
