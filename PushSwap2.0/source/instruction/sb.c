/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:55:58 by memahote          #+#    #+#             */
/*   Updated: 2023/04/05 13:56:57 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sb(t_list **stack_b, int printable)
{
	int		tmp2;
	t_list	*st_b;

	st_b = *stack_b;
	if (!st_b || st_b ->next == NULL)
		return ;
	tmp2 = st_b->content;
	st_b ->content = st_b->next->content;
	st_b->next->content = tmp2;
	*stack_b = st_b;
	if (printable == 1)
		ft_printf("%s\n", "sb");
}
