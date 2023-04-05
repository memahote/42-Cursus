/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:55:29 by memahote          #+#    #+#             */
/*   Updated: 2023/04/05 13:56:30 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pb(t_list **stack_a, t_list **stack_b, int printable)
{
	t_list	*st_a;
	t_list	*st_b;

	st_a = *stack_a;
	st_b = *stack_b;
	if (!st_a)
		return ;
	st_b = addtop(st_b, st_a);
	st_a = delfirst(st_a);
	*stack_a = st_a;
	*stack_b = st_b;
	if (printable == 1)
		ft_printf("%s\n", "pb");
}
