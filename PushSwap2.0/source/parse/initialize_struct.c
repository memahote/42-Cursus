/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:24:34 by memahote          #+#    #+#             */
/*   Updated: 2023/04/01 17:08:58 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	initialize_struct(t_struct *data_struct, char **argv, int argc)
{
	data_struct->stack_a = NULL;
	fill_st_a(argc, argv, data_struct);
	data_struct->stack_b = NULL;
	data_struct->len_a = ft_lstsize(&data_struct->stack_a);
	data_struct->sta = array_of_stack(data_struct->stack_a);
	data_struct->sorted_sta = sort_array(data_struct->sta, data_struct->len_a);
	data_struct->lower = 0;
	data_struct->upper = 0;
	data_struct->number_of_chunk = nb_of_chunk(data_struct->len_a);
	data_struct->chunk_size = (data_struct->len_a) / \
		(data_struct->number_of_chunk);
	data_struct->down = 0;
	data_struct->mid = data_struct->len_a / 2 ;
	data_struct->median = data_struct->sorted_sta[data_struct->len_a / 2];
	data_struct->index_start = data_struct->mid - data_struct->chunk_size;
	data_struct->start = data_struct->sorted_sta[data_struct->index_start];
	data_struct->index_end = data_struct->mid + data_struct->chunk_size;
	data_struct->end = data_struct->sorted_sta[data_struct->index_end];
	data_struct->index_biggest = data_struct->len_a - 4;
	data_struct->print = 1;
}
