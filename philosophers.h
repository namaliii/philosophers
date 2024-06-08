/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:40:29 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/08 19:00:19 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define MAX_PHILOS 200

typedef struct s_data
{
	int		sleep_time;
	int		eating_time;
	int		time_to_die;
	int		meals_no;
	int		philos_no;
	long	start_time;
}	t_data;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	print;
	int				id;
	t_data			*data;
}	t_philo;

int		ft_isdigit(char c);
int		ft_atoi(char *str);
int		negative_check(char **argv);
int		args_check(int argc, char **argv);
int		numeric_check(char **argv);

void	assign_forks(t_philo **philos_array);
t_philo	**init_philos(char **argv, t_data *data);
t_data	*init_data(char **argv);
void	create_threads(int philos_no, t_philo **philos_array);

long	get_time(void);
void	ft_usleep(long sleep_time);

#endif