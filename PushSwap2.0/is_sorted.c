/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:27:03 by memahote          #+#    #+#             */
/*   Updated: 2023/01/16 14:31:10 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_sorted(t_list *stack)
{
	while (stack -> next != NULL)
	{
		if (stack ->content > stack -> next ->content)
			return (0);
		stack = stack -> next;
	}
	return (1);
}
