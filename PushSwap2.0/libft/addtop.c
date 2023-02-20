/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addtop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:49:59 by memahote          #+#    #+#             */
/*   Updated: 2023/01/16 14:26:41 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*addtop(t_list *stack, t_list *stack2)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		exit(0);
	new ->content = stack2 ->content;
	new ->next = stack;
	return (new);
}
