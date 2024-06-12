/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:05:29 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/07 20:05:58 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_time(void)
{
	struct timeval	time;
	long			time_in_ms;

	gettimeofday(&time, NULL);
	time_in_ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (time_in_ms);
}

void	ft_usleep(long sleep_time)
{
	long	start_time;

	start_time = get_time();
	while (get_time() - start_time < sleep_time)
		usleep(30);
}
