/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:37:47 by memahote          #+#    #+#             */
/*   Updated: 2023/03/31 12:53:29 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// check if there are duplicates argument
void	check_duplicate(t_struct *data)
{
	t_list	*st_a;
	t_list	*current;

	st_a = data->stack_a;
	while (st_a->next != NULL)
	{
		current = st_a ->next;
		while (current != NULL)
		{
			if (st_a ->content == current->content)
				ft_print_error(data);
			current = current ->next;
		}
		st_a = st_a ->next;
	}
}
