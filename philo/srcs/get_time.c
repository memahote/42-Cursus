/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:00:44 by memahote          #+#    #+#             */
/*   Updated: 2023/10/17 19:09:05 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
/*struct timeval {
    time_t      tv_sec;  secondes 
    suseconds_t tv_usec; microsecondes 
} */

long get_time(void)
{
    struct timeval time;

    if(gettimeofday(&time, NULL) == -1)
    {
        ft_putstr_fd("Error gettimeofday\n", 2);
        return(-1);
    }
    return(time.tv_sec * 1000 + time.tv_usec / 1000);

}
