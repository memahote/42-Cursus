/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:39:34 by memahote          #+#    #+#             */
/*   Updated: 2023/03/28 14:23:09 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char **argv)
{
	t_struct    *data;

	data= ft_calloc(1, sizeof(t_struct));
	if (!data)
		exit(1);
	if (argc == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	initialize_struct(data, argv, argc);
	if (is_sorted(data->stack_a))
		exit(EXIT_SUCCESS);
	if (data->len_a == 2)
		sa(&(data->stack_a));
	else if (data->len_a == 3)
		sort_three(data);
	else if (data->len_a <=5)
		sort_five(data);
	else
	{
		sort_a_to_b(data);
		sort_b_to_a(&data);
	}
	return (0);
}
