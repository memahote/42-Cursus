/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addback.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:10:48 by memahote          #+#    #+#             */
/*   Updated: 2023/03/30 12:29:27 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*addback(t_list *stack, int value)
{
	t_list	*current;
	t_list	*new;

	new = malloc(sizeof(t_list));
	new ->content = value;
	new ->next = NULL;
	if (stack == NULL)
		return (new);
	current = stack;
	while (current->next)
		current = current->next;
	current->next = new;
	return (stack);
	// return (free(new), stack); /* enleve les leaks mais cree des invalid read*/
}
