/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:34:36 by memahote          #+#    #+#             */
/*   Updated: 2023/10/13 20:34:36 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    t_philo *philos;

    philos = NULL;
    if (argc < 5 || argc > 6)
		  return (printf("Wrong number of arguments."));
    if(check_args_are_positive(argv) == 0)
        return(0);
}


