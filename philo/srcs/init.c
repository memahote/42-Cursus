/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:35:28 by memahote          #+#    #+#             */
/*   Updated: 2023/10/17 19:49:51 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init(t_philo *philos,char **argv)
{
    philos->time_to_die = ft_atoi(argv[2]);
    philos->time_to_eat = ft_atoi(argv[3]);
    philos->time_to_sleep = ft_atoi(argv[4]);
    philos->nb_time_to_eat = -1;
    if(argv[5])
        philos->nb_time_to_eat = ft_atoi(argv[5]);
}