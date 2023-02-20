/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:05:42 by memahote          #+#    #+#             */
/*   Updated: 2023/01/16 14:28:58 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// search if the biggest element is on stack b and return his index
int	find_biggest(t_struct **data)
{
	int		i;
	t_list	*current;
	t_list	*head;

	i = 1;
	current = (*data)->stack_b;
	head = current;
	while (current != NULL)
	{
		if (current->content == (*data)->sorted_sta[(*data)->index_biggest])
			return (current = head, i);
		current = current->next;
		i++;
	}
	return (current = head, 0);
}
