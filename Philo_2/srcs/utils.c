/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:18:28 by memahote          #+#    #+#             */
/*   Updated: 2023/10/27 22:18:28 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_atoi(char *str)
{
	int			i;
	long int	n;

	i = 0;
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	if (n < 0 || ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
		|| n > INT_MAX)
		return (0);
	return (n);
}

void	print_message(char *message, t_philo *philos, int id)
{
	int		time;

	pthread_mutex_lock(philos->writing);
	time = get_time() - philos->time_start;
	if(!death_status(philos))
	{
		printf("%d %d %s\n", time, id, message);
		usleep(15000);
	}
	pthread_mutex_unlock(philos->writing);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}