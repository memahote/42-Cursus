/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:55:56 by memahote          #+#    #+#             */
/*   Updated: 2023/01/16 14:05:19 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sa(t_list **stack_a)
{
	int		tmp;
	t_list	*st_a;

	st_a = *stack_a;
	if (!st_a || st_a ->next == NULL)
		return ;
	tmp = st_a->content;
	st_a ->content = st_a->next->content;
	st_a->next->content = tmp;
	*stack_a = st_a;
	ft_printf("%s\n", "sa");
}
