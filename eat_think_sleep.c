/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_think_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:10:34 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/08 20:14:20 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat_spaghetti(t_philo *philo)
{
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
