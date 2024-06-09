/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:55:58 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/09 18:42:45 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	if (philo->data->philos_no == 1)
	{
		take_right_fork(philo);
		lock_print(philo, "died", philo->data->time_to_die);
		return (NULL);
	}
	while (meals_check(philo) == 1 && dead_check(philo) == 0)
	{
		if (philo->id % 2 != 0)
			ft_usleep(10);
		take_right_fork(philo);
		take_left_fork(philo);
		dprintf(2, "%d death check: %d\n", philo->id, dead_check(philo));
		eat_spaghetti(philo);
		leave_right_fork(philo);
		leave_left_fork(philo);
		go_to_sleep(philo);
		think(philo);
	}
	if (dead_check(philo) == 1)
		lock_print(philo, "died", get_time() - philo->data->start_time);
	return (NULL);
}
