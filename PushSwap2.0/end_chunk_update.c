/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_chunk_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:58:05 by memahote          #+#    #+#             */
/*   Updated: 2023/01/16 14:28:08 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// int		end_chunk_update(t_struct **data)
// {
// 	int		i;
// 	int		j;
// 	int		new_end;

// 	i = 0;
// 	while ((*data)->sorted_sta[i] <= (*data)->end)
// 		i++;
// 	if ((*data)->len_a - i <= 3)
// 		return ((*data)->end);
// 	j = (*data)->len_a - i;
// 	if (j < (*data)->chunk_size)
// 		return ((*data)->sorted_sta[(*data)->index_biggest]);
// 	i = i + (*data)->chunk_size;
// 	new_end = (*data)->sorted_sta[i];
// 	return (new_end);
// }
