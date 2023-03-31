/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:55:37 by memahote          #+#    #+#             */
/*   Updated: 2023/01/16 14:32:15 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	update_values(t_struct *data)
{
	if (data->lower == data->chunk_size)
	{
		if (data->index_start - data->chunk_size < 0)
		{
			data->index_start = 0;
			data->start = data->sorted_sta[data->index_start];
		}
		else
		{
			data->index_start -= data->chunk_size;
			data->start = data->sorted_sta[data->index_start];
		}
		data->lower = 0;
	}
	else if (data->upper == data->chunk_size)
	{
		if (data->index_end + data->chunk_size >= data->index_biggest)
			data->end = data->sorted_sta[data->index_biggest];
		else
		{
			data->index_end += data->chunk_size;
			data->end = data->sorted_sta[data->index_end];
		}
		data->upper = 0;
	}
}
