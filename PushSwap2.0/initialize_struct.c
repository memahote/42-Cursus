/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:24:34 by memahote          #+#    #+#             */
/*   Updated: 2023/01/16 14:30:25 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// initialize the stuct 
void	initialize_struct(t_struct **data_struct, char **argv, int argc)
{
	(*data_struct) = malloc(sizeof(t_struct));
	if (!(*data_struct))
		exit(1);
	(*data_struct)->stack_a = NULL;
	fill_st_a(argv,argc, &(*data_struct));
	(*data_struct)->stack_b = NULL;
	(*data_struct)->len_a = ft_lstsize(&((*data_struct)->stack_a));
	(*data_struct)->sta = array_of_stack((*data_struct)->stack_a);
	(*data_struct)->sorted_sta = sort_array((*data_struct)->sta, (*data_struct)->len_a - 1);
	(*data_struct)->lower = 0;
	(*data_struct)->upper = 0;
	(*data_struct)->number_of_chunk = nb_of_chunk((*data_struct)->len_a);
	(*data_struct)->chunk_size = ((*data_struct)->len_a) / ((*data_struct)->number_of_chunk);
	(*data_struct)->down = 0;
	(*data_struct)->mid = (*data_struct)->len_a / 2 ;
	(*data_struct)->median = (*data_struct)->sorted_sta[(*data_struct)->len_a / 2];
	(*data_struct)->index_start = (*data_struct)->mid - (*data_struct)->chunk_size;
	(*data_struct)->start = (*data_struct)->sorted_sta[(*data_struct)->index_start] ;
	(*data_struct)->index_biggest = (*data_struct)->len_a - 3;
	(*data_struct)->index_end = (*data_struct)->mid + (*data_struct)->chunk_size ;
	(*data_struct)->end = (*data_struct)->sorted_sta[(*data_struct)->index_end];
}
