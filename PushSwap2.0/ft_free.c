/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:55:37 by memahote          #+#    #+#             */
/*   Updated: 2023/01/16 14:32:15 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void ft_free_list(t_list *list)
{
    t_list  *temp;

    while (list)
    {
        temp = list->next;
        free(list);
        list = temp;
    }
}

void    ft_free(t_struct *data)
{
        if(data->stack_a)
            ft_free_list(data->stack_a);
        if(data->stack_b)
            ft_free_list(data->stack_b);
        free(data->sta);
        free(data);
}