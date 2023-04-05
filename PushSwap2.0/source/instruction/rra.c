/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:55:50 by memahote          #+#    #+#             */
/*   Updated: 2023/04/05 13:56:44 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rra(t_list **stack_a, int printable)
{
	t_list	*st_a;

	st_a = *stack_a;
	st_a = addtop(st_a, ft_lstlast(st_a));
	dellast(st_a);
	*stack_a = st_a;
	if (printable == 1)
		ft_printf("%s\n", "rra");
}
