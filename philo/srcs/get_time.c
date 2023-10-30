/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:00:44 by memahote          #+#    #+#             */
/*   Updated: 2023/10/30 02:03:25 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int get_time(void)
{
    struct timeval time;

    if(gettimeofday(&time, NULL) == -1)
        write(2, "gettimeofday() error\n", 22);
    return(time.tv_sec * 1000 + time.tv_usec / 1000);
}
