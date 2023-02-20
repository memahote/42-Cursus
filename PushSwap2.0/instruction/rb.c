/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:55:45 by memahote          #+#    #+#             */
/*   Updated: 2023/01/16 14:03:37 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rb(t_list **stack_b)
{
	t_list	*st_b;

	st_b = *stack_b;
	st_b = addback(st_b, st_b->content);
	st_b = delfirst(st_b);
	*stack_b = st_b;
	ft_printf("%s\n", "rb");
}
