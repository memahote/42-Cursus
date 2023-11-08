/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:53:14 by memahote          #+#    #+#             */
/*   Updated: 2023/11/04 00:53:14 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    clean(t_philo *philo, t_data *data, pthread_mutex_t *forks, char *str)
{
    int i;

    i = 0;
    if(str == THREAD)
        pritnf("%s\n", THREAD);
    if(str == THREAD2)
        pritnf("%s\n", THREAD2);
    if(philo)
        free(philo);
    pthread_mutex_destroy(&data->dead_m);
    pthread_mutex_destroy(&data->meal_m);
    pthread_mutex_destroy(&data->writing);
    while(i < philo[0].nb_philo)
    {
        pthread_mutex_destroy(&forks[i]);
        i++;
    }
    free(forks);
}