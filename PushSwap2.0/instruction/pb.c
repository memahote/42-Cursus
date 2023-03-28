/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:55:29 by memahote          #+#    #+#             */
/*   Updated: 2023/01/16 14:02:51 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	pb(t_list **stack_a, t_list **stack_b)
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
	ft_printf("%s\n", "pb");
}
