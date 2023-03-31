/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index_smallest.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:17:55 by memahote          #+#    #+#             */
/*   Updated: 2023/01/16 14:29:18 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_index_smallest(t_list **stack)
{
	int		i;
	t_list	*head;

	i = 1;
	head = (*stack);
	if (!(*stack))
		return (0);
	while ((*stack)->content != find_smallest(&(*stack)))
	{
		i++;
		(*stack) = (*stack)->next;
	}
	return ((*stack) = head, i);
}
