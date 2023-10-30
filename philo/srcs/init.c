/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 02:10:54 by memahote          #+#    #+#             */
/*   Updated: 2023/10/28 02:10:54 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_data(t_philo *philos, pthread_mutex_t *forks, t_mutex *mutex, char **av)
{
    int i;

    i = 0;
    while (i < philo_atoi(av[1]))
    {
        philos[i].id = i + 1;
        philos[i].t_to_die = philo_atoi(av[2]);
        philos[i].t_to_eat = philo_atoi(av[3]);
        philos[i].t_to_sleep = philo_atoi(av[4]);
        philos[i].nb_meal = -1;
        if(av[5])
            philos[i].nb_meal = philo_atoi(av[5]);
        philos[i].meal_count = 0;
        philos[i].dead = &mutex->dead_status;
        philos[i].time_start = get_time();
        philos[i].fork_l = &forks[i];
        philos[i].fork_r = &forks[i + 1];
        if(philos[i].fork_r == NULL)
            philos[i].fork_l = &forks[0];
        philos[i].dead_m = &mutex->dead_m;
        philos[i].meal_m = &mutex->meal_m;
        philos[i].writing = &mutex->writing;
        i++;
    }
}

void    init_mutex(char **av, pthread_mutex_t *forks, t_mutex *mutex)
{
    int i;

    i = 0;
    while(i < philo_atoi(av[1]))
    {
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }
    mutex->dead_status = 0;
    pthread_mutex_init(&mutex->dead_m, NULL);
    pthread_mutex_init(&mutex->meal_m, NULL);
    pthread_mutex_init(&mutex->writing, NULL);
    
}