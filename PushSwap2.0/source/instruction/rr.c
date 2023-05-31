/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:55:47 by memahote          #+#    #+#             */
/*   Updated: 2023/05/31 12:11:19 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rr(t_list **stack_a, t_list **stack_b, int printable)
{
	t_list	*st_a;
	t_list	*st_b;

	st_a = *stack_a;
	st_b = *stack_b;
	if (!st_a || !st_b)
		return ;
	st_a = addback(st_a, st_a->content);
	st_a = delfirst(st_a);
	*stack_a = st_a;
	st_b = addback(st_b, st_b->content);
	st_b = delfirst(st_b);
	*stack_b = st_b;
	if (printable == 1)
		ft_printf("%s\n", "rr");
}
