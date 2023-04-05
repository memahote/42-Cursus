/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_of_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:20:40 by memahote          #+#    #+#             */
/*   Updated: 2023/04/05 13:57:31 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*array_of_stack(t_list *stack)
{
	int		*st;
	t_list	*head;
	int		i;
	int		len;

	i = 0;
	head = stack;
	len = ft_lstsize(&stack);
	st = malloc(sizeof(int) * len);
	if (!st)
		return (NULL);
	stack = head;
	while (stack != NULL)
	{
		st[i] = stack->content;
		stack = stack->next;
		i++;
	}
	return (stack = head, st);
}
