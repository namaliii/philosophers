/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:40:29 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/09 18:10:14 by anamieta         ###   ########.fr       */
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
	int				sleep_time;
	int				eating_time;
	int				time_to_die;
	int				meals_no;
	int				philos_no;
	long			start_time;
	pthread_mutex_t	meals_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
}	t_data;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	*left_fork;
	int				id;
	int				last_meal;
	t_data			*data;
}	t_philo;

/* args check */
int		ft_isdigit(char c);
int		ft_atoi(char *str);
int		negative_check(char **argv);
int		args_check(int argc, char **argv);
int		numeric_check(char **argv);

/* initialization */
void	assign_forks(t_philo **philos_array);
t_philo	**init_philos(char **argv, t_data *data);
t_data	*init_data(char **argv);
void	create_threads(int philos_no, t_philo **philos_array);

/* my usleep */
long	get_time(void);
void	ft_usleep(long sleep_time);

/* daily routine */
void	*routine(void *arg);
void	lock_print(t_philo *philo, char *msg, long time);
void	take_right_fork(t_philo *philo);
void	take_left_fork(t_philo *philo);
void	leave_right_fork(t_philo *philo);
void	leave_left_fork(t_philo *philo);
void	eat_spaghetti(t_philo *philo);
void	think(t_philo *philo);
void	go_to_sleep(t_philo *philo);

int		meals_check(t_philo *philo);
void	decrement_meals(t_philo *philo);
int		dead_check(t_philo *philo);

#endif