/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:56:01 by memahote          #+#    #+#             */
/*   Updated: 2023/01/16 14:06:11 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ss(t_list **stack_a, t_list **stack_b)
{
	int		tmp;
	t_list	*st_a;
	int		tmp2;
	t_list	*st_b;

	st_a = *stack_a;
	if (!st_a || st_a ->next == NULL)
		return ;
	tmp = st_a->content;
	st_a ->content = st_a->next->content;
	st_a->next->content = tmp;
	*stack_a = st_a;
	st_b = *stack_b;
	if (!st_b || st_b ->next == NULL)
		return ;
	tmp2 = st_b->content;
	st_b ->content = st_b->next->content;
	st_b->next->content = tmp2;
	*stack_b = st_b;
	ft_printf("%s\n", "ss");
}
