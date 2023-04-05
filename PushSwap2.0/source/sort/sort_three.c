/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:25:46 by memahote          #+#    #+#             */
/*   Updated: 2023/04/01 17:16:25 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_three(t_struct *data)
{
	int	first;
	int	second;
	int	third;

	first = data->stack_a->content;
	second = data->stack_a->next->content;
	third = data->stack_a->next->next->content;
	if (first > second && second > third && first > third)
	{
		sa(&data->stack_a, data->print);
		rra(&data->stack_a, data->print);
	}
	else if (first > second && third > second && first > third)
		ra(&data->stack_a, data->print);
	else if (second > first && second > third && third > first)
	{
		sa(&data->stack_a, data->print);
		ra(&data->stack_a, data->print);
	}
	else if (first > second && third > second && third > first)
		sa(&data->stack_a, data->print);
	else if (second > first && second > first && first > third)
		rra(&data->stack_a, data->print);
}
