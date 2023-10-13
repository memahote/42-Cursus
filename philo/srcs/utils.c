/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:37:23 by memahote          #+#    #+#             */
/*   Updated: 2023/10/13 20:37:23 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int			i;
	long		nb;
	int			neg;

	i = 0;
	nb = 0;
	neg = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nb >= LONG_MAX / 10 && neg == 1)
			return (-1);
		if (nb < LONG_MIN / 10 && neg == -1)
			return (0);
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * neg);
}
