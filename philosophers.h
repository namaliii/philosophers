/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:40:29 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/06 17:39:08 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

# define MAX_PHILOS 200

typedef struct s_data
{
}	t_data;

typedef struct s_philo
{
	pthread_t	philos_thread;
	int			id;
	t_data		*data;
}	t_philo;


int		ft_isdigit(char c);
int		ft_atoi(char *str);
int		negative_check(char **argv);
int		args_check(int argc, char **argv);

# endif
