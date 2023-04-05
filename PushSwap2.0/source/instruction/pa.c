/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:55:37 by memahote          #+#    #+#             */
/*   Updated: 2023/04/05 13:56:23 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pa(t_list **stack_a, t_list **stack_b, int printable)
{
	t_list		*st_a;
	t_list		*st_b;

	st_a = *stack_a;
	st_b = *stack_b;
	if (!st_b)
		return ;
	st_a = addtop(st_a, st_b);
	st_b = delfirst(st_b);
	*stack_a = st_a;
	*stack_b = st_b;
	if (printable == 1)
		ft_printf("%s\n", "pa");
}
