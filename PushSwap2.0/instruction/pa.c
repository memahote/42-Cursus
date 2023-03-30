/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:55:37 by memahote          #+#    #+#             */
/*   Updated: 2023/03/30 12:51:12 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list		*st_a;
	t_list		*st_b;

	st_a = *stack_a;
	st_b = *stack_b;
	if (!st_b)
		return ;
	// ft_lstadd_front(&st_a, ft_lstnew(st_b->content));
	st_a = addtop(st_a, st_b);
	st_b = delfirst(st_b);
	*stack_a = st_a;
	*stack_b = st_b;
	ft_printf("%s\n", "pa");
}
