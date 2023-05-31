/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:55:52 by memahote          #+#    #+#             */
/*   Updated: 2023/05/31 12:12:21 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rrb(t_list **stack_b, int printable)
{
	t_list	*st_b;

	st_b = *stack_b;
	if (!st_b)
		return ;
	st_b = addtop(st_b, ft_lstlast(st_b));
	dellast(st_b);
	*stack_b = st_b;
	if (printable == 1)
		ft_printf("%s\n", "rrb");
}
