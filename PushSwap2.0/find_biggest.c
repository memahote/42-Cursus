/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:05:42 by memahote          #+#    #+#             */
/*   Updated: 2023/03/31 14:14:31 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
