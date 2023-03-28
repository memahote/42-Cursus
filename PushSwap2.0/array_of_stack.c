/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_of_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:20:40 by memahote          #+#    #+#             */
/*   Updated: 2023/01/17 15:35:22 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include    "pushswap.h"

int		*array_of_stack(t_list *stack)
{
	int		*st;
	t_list	*head;
	int		i;

	i = 0;
	head = stack;
	st = malloc(sizeof(int) * ft_lstsize(&stack));
	if (!st)
		return(NULL);
	stack = head;
	while(stack != NULL)
	{
		st[i] = stack->content;
		stack = stack->next;
		i++;
	}
	return (stack = head, st);
}
