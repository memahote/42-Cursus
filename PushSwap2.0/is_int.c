/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:15:30 by memahote          #+#    #+#             */
/*   Updated: 2023/01/16 14:30:56 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// check if arguments are valid
int	is_int(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && ft_isdigit(str[i + 1]))
			i++;
		while (ft_isdigit(str[i]))
			i++;
		if (str[i] != '\0')
			return (0);
	}
	if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		return (0);
	return (1);
}
