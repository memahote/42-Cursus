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

void    thread_create(t_data *data, pthread_mutex_t *forks)
{
    pthread_t  host_t;
    int         i;

    i = 0;
    pthread_create(&host_t, NULL, &host, data->philo);
    while(i < data->philo->nb_philo)
    {
        pthread_create(&data->philo[i].thread, NULL, &routine, &data->philo[i]);
        i++;
    }
    pthread_join(host_t, NULL);
    i = 0;
    while(i < data->philo[0].nb_philo)
    {
        pthread_join(data->philo[i].thread, NULL);
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
    thread_create(&data, forks);  //ko
    free(forks);
    free(philo);
}