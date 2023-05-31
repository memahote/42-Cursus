/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:55:54 by memahote          #+#    #+#             */
/*   Updated: 2023/05/31 12:14:56 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rrr(t_list **stack_a, t_list **stack_b, int printable)
{
	t_list	*st_a;
	t_list	*st_b;

	st_a = *stack_a;
	st_b = *stack_b;
	if (!st_a || !st_b)
		return ;
	st_a = addtop(st_a, ft_lstlast(st_a));
	dellast(st_a);
	*stack_a = st_a;
	st_b = addtop(st_b, ft_lstlast(st_b));
	dellast(st_b);
	*stack_b = st_b;
	if (printable == 1)
		ft_printf("%s\n", "rrr");
}
