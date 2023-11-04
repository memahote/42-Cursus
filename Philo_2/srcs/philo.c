/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:19:30 by memahote          #+#    #+#             */
/*   Updated: 2023/10/27 22:19:30 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    thread_create(t_data *data, pthread_mutex_t *forks, t_philo *philo)
{
    pthread_t  host_t;
    int         i;

    i = 0;
    if(pthread_create(&host_t, NULL, &host, data->philo) != 0)
        clean(philo, data, forks, THREAD);
    while(i < data->philo->nb_philo)
    {
        if(pthread_create(&data->philo[i].thread, NULL, &routine,
        &data->philo[i]) != 0)
            clean(philo, data, forks, THREAD);
        i++;
    }
    if(pthread_join(host_t, NULL) != 0)
        clean(philo, data, forks, THREAD2);
    i = 0;
    while(i < data->philo[0].nb_philo)
    {
        if(pthread_join(data->philo[i].thread, NULL) != 0)
            clean(philo, data, forks, THREAD2);
        i++;
    }
}

int main(int ac, char **av)
{
    pthread_mutex_t *forks;
    t_philo         *philo;
    t_data         data;

    if(!parse(ac, av)) // -> parsing testé ok
        return (0);
    forks = malloc(sizeof(pthread_mutex_t) *( philo_atoi(av[1]) + 1));
    if(!forks)
        return (0);
    philo = malloc(sizeof(t_philo) * ( philo_atoi(av[1]) + 1));
    if(!philo)
        return (0);
    init_data(&data, philo); // ok
    init_forks(av, forks); //ok
    init_philo(philo, forks, &data, av); //ok
    thread_create(&data, forks, philo);  //ok
    clean(philo, &data, forks, NULL);
}

//a faire : fonction clean -> qui free et detruit les thread en cas d'eereur ou non