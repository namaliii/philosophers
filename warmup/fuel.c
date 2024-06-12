/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuel.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:13:07 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/04 20:50:35 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

pthread_mutex_t mutexFuel;
pthread_cond_t condFuel;
int fuel = 0;

void* fuel_filling(void* arg)
{
	for (int i = 0; i < 5; i++) {
		pthread_mutex_lock(&mutexFuel);
		fuel += 30;
		printf("Filling fuel... %d\n", fuel);
		pthread_mutex_unlock(&mutexFuel);
		pthread_cond_broadcast(&condFuel);
		sleep(1);
	}
	return (NULL);
}

void* car(void* arg)
{
	printf("Here to get fuel. Waiting...\n");
	pthread_mutex_lock(&mutexFuel);
	while (fuel < 40) {
		printf("No fuel. Waiting...\n");
		pthread_cond_wait(&condFuel, &mutexFuel);
		// sleep(1);
	}
	fuel -= 40;
	printf("Got fuel. Now left: %d\n", fuel);
	pthread_mutex_unlock(&mutexFuel);
	return (NULL);
}

int main(void)
{
    pthread_t th[6];
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_cond_init(&condFuel, NULL);
    for (int i = 0; i < 6; i++) {
        if (i == 4 || i == 5) {
            if (pthread_create(&th[i], NULL, &fuel_filling, NULL) != 0) {
                perror("Failed to create thread");
            }
        } else {
            if (pthread_create(&th[i], NULL, &car, NULL) != 0) {
                perror("Failed to create thread");
            }
        }
    }

    for (int i = 0; i < 6; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }
    pthread_mutex_destroy(&mutexFuel);
    pthread_cond_destroy(&condFuel);
    return 0;
}