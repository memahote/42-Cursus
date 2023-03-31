/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:51:08 by memahote          #+#    #+#             */
/*   Updated: 2023/01/16 14:30:04 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_smallest(t_list **stack)
{
	t_list	*st_a;
	t_list	*current;
	int		nb;

	st_a = *stack;
	nb = st_a->content;
	while (st_a->next != NULL)
	{
		current = st_a ->next;
		while (current != NULL)
		{
			if (nb > current->content)
			{
				nb = current->content;
				break ;
			}
			current = current ->next;
		}
		st_a = st_a ->next;
	}
	return (nb);
}
