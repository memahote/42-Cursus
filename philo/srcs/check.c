/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:26:47 by memahote          #+#    #+#             */
/*   Updated: 2023/10/13 20:26:47 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int check_args_are_numbers(char **argv)
{
    int i;
    int j;

    i = 0;
    while(argv[i])
    {
        j = 0;
        if(argv[i][j] == '-')
            j++;
        while(argv[i][j])
        {
            if(ft_isdigit(argv[i][j]) == 0)
                return(0);
            j++;
        }
        i++;
    }
    return(1);
}

int check_args_are_positive(char **argv)
{
    if(check_args_are_numbers(argv[1]) == 0 || ft_atoi(argv[1]) <= 0)
        return(ft_putstr_fd("Invalid number of Philo\n", 2), 0);
    else if(check_args_are_numbers(argv[2]) == 0 || ft_atoi(argv[2]) <= 0)
        return(ft_putstr_fd("Invalid time to die\n", 2), 0);
    else if(check_args_are_numbers(argv[3]) == 0 || ft_atoi(argv[3]) <= 0)
        return(ft_putstr_fd("Invalid time to eat\n", 2), 0);
    else if(check_args_are_numbers(argv[4]) == 0 || ft_atoi(argv[4]) <= 0)
        return(ft_putstr_fd("Invalid time to sleep\n", 2), 0);
    else if(argv[5])
        if(check_args_are_numbers(argv[5]) == 0 || ft_atoi(argv[5]) <= 0)
            return(ft_putstr_fd("Invalid number of times to eat\n", 2), 0);
    return (1);
}