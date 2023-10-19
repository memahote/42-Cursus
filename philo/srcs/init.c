/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:35:28 by memahote          #+#    #+#             */
/*   Updated: 2023/10/19 21:14:32 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_data(t_philo *philos, pthread_mutex_t *forks, char **argv)
{
    int i;

    i = 0;
    while(i < argv[1])
    {
        philos[i].id_philo = i + 1;
        philos[i].time_to_die = ft_atoi(argv[2]);
        philos[i].time_to_eat = ft_atoi(argv[3]);
        philos[i].time_to_sleep = ft_atoi(argv[4]);
        philos[i].nb_time_to_eat = -1;
        if(argv[5])
            philos[i].nb_time_to_eat = ft_atoi(argv[5]);
        philos[i].time_start = get_time() ;// temps en ms au debut du prog
        if(philos[i].id_philo == argv[1])
        {
            philos[i].fork_l = &forks[i];
            philos[i].fork_r = &forks[0];
        }
        else
        {
            philos[i].fork_l = &forks[i];
            philos[i].fork_r = &forks[i + 1];
        }
        i++;
    }
}

void    init_forks(char **argv, pthread_mutex_t *forks)
{
    int i;

    i = 0;
    while(i < ft_atoi(argv[1]))
    {
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }
}