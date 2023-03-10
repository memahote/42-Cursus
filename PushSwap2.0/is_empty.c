/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:13:11 by memahote          #+#    #+#             */
/*   Updated: 2023/01/16 14:30:41 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// check if the stack is empty
int	is_empty(t_list **stack)
{
	if ((*stack) == NULL)
		return(1);
	return (0);
}
