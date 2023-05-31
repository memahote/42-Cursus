/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:55:45 by memahote          #+#    #+#             */
/*   Updated: 2023/05/31 12:10:05 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rb(t_list **stack_b, int printable)
{
	t_list	*st_b;

	st_b = *stack_b;
	if (!st_b)
		return ;
	st_b = addback(st_b, st_b->content);
	st_b = delfirst(st_b);
	*stack_b = st_b;
	if (printable == 1)
		ft_printf("%s\n", "rb");
}
