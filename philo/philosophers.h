/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:40:29 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/11 18:45:59 by anamieta         ###   ########.fr       */
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
	int				someone_died;
	long			start_time;
	pthread_mutex_t	main_mutex;
}	t_data;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	philo_mutex;
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
void	init_philo_helper(t_philo **philos_array,
			t_data *data, int philos_no);
t_philo	**init_philos(char **argv, t_data *data);
t_data	*init_data(char **argv);

/* threads operaitons */
void	create_threads(int philos_no, t_philo **philos_array);
void	join_threads(int philos_no, t_philo **philos_array);

/* my usleep */
long	get_time(void);
void	ft_usleep(long sleep_time);

/* daily routine */
int		single_philo(t_philo *philo);
void	even_odd_routine(t_philo *philo);
void	*routine(void *arg);
void	lock_print(t_philo *philo, char *msg, long time);
void	pick_forks(t_philo *philo);
void	eat_spaghetti(t_philo *philo);
void	drop_forks(t_philo *philo);
void	think(t_philo *philo);
void	go_to_sleep(t_philo *philo);

/* checks and cleaning */
int		meals_check(t_philo *philo);
void	decrement_meals(t_philo *philo);
int		dead_check(t_philo *philo);
void	clean_up(t_philo **philos_array);

#endif