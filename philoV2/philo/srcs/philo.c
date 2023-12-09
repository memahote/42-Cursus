/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:19:30 by memahote          #+#    #+#             */
/*   Updated: 2023/11/24 19:53:11 by memahote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean(t_philo *philo, t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->dead_m);
	pthread_mutex_destroy(&data->meal_m);
	pthread_mutex_destroy(&data->writing);
	while (i < philo[0].nb_philo)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	if (philo)
		free(philo);
	free(forks);
}

int	thread_create(t_data *data)
{
	pthread_t	host_t;
	int			i;

	i = 0;
	if (pthread_create(&host_t, NULL, &host, data->philo) != 0)
		return (printf("%s\n", THREAD), 1);
	while (i < data->philo->nb_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL, &routine, \
					&data->philo[i]) != 0)
		{
			printf("%s\n", THREAD);
			break ;
		}
		i++;
	}
	if (pthread_join(host_t, NULL) != 0)
		return (printf("%s\n", THREAD), 1);
	while (i > 0)
	{
		i--;
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			return (printf("%s\n", THREAD), 1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	pthread_mutex_t	*forks;
	t_philo			*philo;
	t_data			data;

	if (!parse(ac, av))
		return (0);
	forks = malloc(sizeof(pthread_mutex_t) *(philo_atoi(av[1]) + 1));
	if (!forks)
		return (0);
	philo = malloc(sizeof(t_philo) * (philo_atoi(av[1]) + 1));
	if (!philo)
		return (0);
	init_data(&data, philo);
	init_forks(av, forks);
	init_philo(philo, forks, &data, av);
	thread_create(&data);
	clean(philo, &data, forks);
}
