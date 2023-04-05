/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:23:50 by memahote          #+#    #+#             */
/*   Updated: 2023/04/01 17:16:39 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_small(t_struct *data)
{
	int		i;

	while (data->len_a > 3)
	{
		i = 0;
		i = find_index_smallest(&data->stack_a);
		if (i <= data->len_a / 2)
		{
			while (data->stack_a->content != find_smallest(&data->stack_a))
				ra(&data->stack_a, data->print);
		}
		else
		{
			while (data->stack_a->content != find_smallest(&data->stack_a))
				rra(&data->stack_a, data->print);
		}
		pb(&data->stack_a, &data->stack_b, data->print);
		data->len_a--;
	}
	sort_three(data);
	while (!is_empty(&data->stack_b))
		pa(&data->stack_a, &data->stack_b, data->print);
}
