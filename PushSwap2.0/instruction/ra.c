/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:55:42 by memahote          #+#    #+#             */
/*   Updated: 2023/01/16 14:03:18 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ra(t_list **stack_a)
{
	t_list	*st_a;

	st_a = *stack_a;
	st_a = addback(st_a, st_a->content);
	st_a = delfirst(st_a);
	*stack_a = st_a;
	ft_printf("%s\n", "ra");
}
