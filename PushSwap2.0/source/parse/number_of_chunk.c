/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_of_chunk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:48:59 by memahote          #+#    #+#             */
/*   Updated: 2023/04/05 14:01:47 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	nb_of_chunk(int size)
{
	if (size <= 10)
		return (5);
	else if (size <= 150)
		return (10);
	else
		return (14);
}
