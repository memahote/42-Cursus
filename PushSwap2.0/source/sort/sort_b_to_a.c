/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:58:36 by memahote          #+#    #+#             */
/*   Updated: 2023/04/01 17:17:07 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	biggest_is_on_a(t_struct **data)
{
	if (ft_lstlast((*data)->stack_a)->content == \
		(*data)->sorted_sta[(*data)->index_biggest])
	{
		rra(&(*data)->stack_a, (*data)->print);
		(*data)->down--;
		(*data)->index_biggest--;
	}
	else
		(*data)->index_biggest--;
}

static void	biggest_is_top_b(t_struct **data)
{
	pa(&(*data)->stack_a, &(*data)->stack_b, (*data)->print);
	(*data)->index_biggest--;
}

static void	biggest_is_on_b(t_struct **data, int index_big)
{
	if (index_big <= ft_lstsize(&(*data)->stack_b) / 2)
		rb(&(*data)->stack_b, (*data)->print);
	else
		rrb(&(*data)->stack_b, (*data)->print);
}

void	sort_b_to_a(t_struct **data)
{
	int	index_big;

	while (ft_lstsize(&((*data)->stack_b)) > 0 || (*data)->down > 0)
	{
		index_big = find_biggest(&(*data));
		if (index_big == 0)
			biggest_is_on_a(&(*data));
		else if (index_big == 1)
			biggest_is_top_b(&(*data));
		else if ((*data)->down == 0 || \
			(*data)->stack_b->content > ft_lstlast((*data)->stack_a)->content)
		{
			pa(&(*data)->stack_a, &(*data)->stack_b, (*data)->print);
			if (index_big < ft_lstsize(&(*data)->stack_b) / 2)
				rr(&(*data)->stack_a, &(*data)->stack_b, (*data)->print);
			else
				ra(&(*data)->stack_a, (*data)->print);
			(*data)->down++;
		}
		else
			biggest_is_on_b(&(*data), index_big);
	}
}
