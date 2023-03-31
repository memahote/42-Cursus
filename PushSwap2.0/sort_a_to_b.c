/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:55:37 by memahote          #+#    #+#             */
/*   Updated: 2023/03/31 13:15:28 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_a_to_b(t_struct *data)
{
	while (ft_lstsize(&data->stack_a) > 3)
	{
		if (data->stack_a->content >= data->start && \
				data->stack_a->content <= data->end)
		{
			pb(&data->stack_a, &data->stack_b);
			if (data->stack_b->content < data->median)
			{
				data->lower++;
				rb(&data->stack_b);
			}
			else
				data->upper++;
		}
		else
			ra(&data->stack_a);
		update_values(data);
	}
	sort_three(data);
}
