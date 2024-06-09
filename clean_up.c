/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:28:05 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/09 18:49:02 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void clean_up(t_data *data)
{
    pthread_mutex_destroy(&(data->death_mutex));
    pthread_mutex_destroy(&(data->print_mutex));
    data->
}