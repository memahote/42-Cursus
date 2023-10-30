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

void    thread_create(t_philo *philo, pthread_mutex_t *forks)
{
    pthread_t  host_t;
    int         i;

    i = 0;
    pthread_create(&host_t, NULL, &host, philo);
    while(i < philo->nb_philo)
    {
        pthread_create(&philo[i].thread, NULL, &routine, &philo[i]);
        i++;
    }
    pthread_join(host_t, NULL);
    i = 0;
    while(i < philo->nb_philo)
    {
        pthread_join(philo[i].thread, NULL);
        i++;
    }
}

int main(int ac, char **av)
{
    pthread_mutex_t *forks;
    t_philo         *philos;
    t_mutex         mutex;

    if(!parse(ac, av)) // -> parsing testé ok
        return (0);
    forks = malloc(sizeof(pthread_mutex_t) *( philo_atoi(av[1]) + 1));
    if(!forks)
        return (0);
    init_mutex(av, forks, &mutex);
    philos = malloc(sizeof(t_philo) * ( philo_atoi(av[1]) + 1));
    if(!philos)
        return (0);
    init_data(philos, forks, &mutex, av);
    thread_create(philos, forks); 
    free(forks);
    free(philos);
}