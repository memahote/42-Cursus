/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:16:27 by memahote          #+#    #+#             */
/*   Updated: 2023/10/28 15:16:27 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    philo_eat(t_philo *philo)
{
    pthread_mutex_lock(philo->fork_l);
    print_message("take a fork", philo, philo->id);
    if (philo->nb_philo == 1)
	{
		usleep(philo->t_to_die * 1000);
		pthread_mutex_unlock(philo->fork_l);
		return ;
	}
    pthread_mutex_lock(philo->fork_r);
	print_message("has taken a fork", philo, philo->id);
    print_message("is eating", philo, philo->id);
    pthread_mutex_lock(philo->meal_m);
    philo->last_meal = get_time();
    philo->meal_count++;
    pthread_mutex_unlock(philo->meal_m);
    usleep((philo->t_to_eat / 1000));
    pthread_mutex_unlock(philo->fork_l);
    pthread_mutex_unlock(philo->fork_r);
}

void    philo_sleep(t_philo *philo)
{
    print_message("is sleeping ZZZzzz", philo, philo->id);
    usleep((philo->t_to_sleep / 1000)); 
}

void    philo_think(t_philo *philo)
{
    print_message("is thinking ...", philo, philo->id);
}

int	death_status(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_m);
	if(*philo->dead == 1)
		return(pthread_mutex_unlock(philo->dead_m), 1);
	return(pthread_mutex_unlock(philo->dead_m), 0);
}

void    *routine(void *data)
{
    t_philo *philo;

    philo = data;
    if((philo->id % 2) == 0 )
        usleep(100);
    while(!death_status(philo))
    {
        philo_eat(philo);
        philo_sleep(philo);
        philo_sleep(philo);
    }
    return(NULL);
}



