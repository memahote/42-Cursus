/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:58:36 by memahote          #+#    #+#             */
/*   Updated: 2023/03/30 09:47:44 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_b_to_a(t_struct **data)
{
	int	index_big;

	while (ft_lstsize(&((*data)->stack_b)) > 0 || (*data)->down > 0)
	{
		index_big = find_biggest(&(*data));
		if (index_big == 0)
		{
			if (ft_lstlast((*data)->stack_a)->content == \
                (*data)->sorted_sta[(*data)->index_biggest])
			{
				rra(&(*data)->stack_a);
				(*data)->down--;
				(*data)->index_biggest--;
			}
			else
				(*data)->index_biggest--;
		}
		else if (index_big == 1)
		{
			pa(&(*data)->stack_a, &(*data)->stack_b);
			(*data)->index_biggest--;
		}
		else if((*data)->down == 0 ||\
		    (*data)->stack_b->content > ft_lstlast((*data)->stack_a)->content)
		{
			pa(&(*data)->stack_a, &(*data)->stack_b);
			if (index_big < ft_lstsize(&(*data)->stack_b) / 2)
				rr(&(*data)->stack_a, &(*data)->stack_b);
			else
				ra(&(*data)->stack_a);
			(*data)->down++;
		}
		else
		{
			if (index_big <= ft_lstsize(&(*data)->stack_b) / 2)
				rb(&(*data)->stack_b);
			else
				rrb(&(*data)->stack_b);
		}
	}
}
