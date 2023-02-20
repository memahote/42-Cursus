/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:39:34 by memahote          #+#    #+#             */
/*   Updated: 2023/01/16 14:31:52 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char **argv)
{
	t_struct    *data;

	if (argc == 1)
		ft_print_error(&data);
	initialize_struct(&data, argv,argc);
	if (is_sorted(data->stack_a))
	{
		ft_free(&data);
		exit(EXIT_SUCCESS);
	}
	if (data->len_a == 2)
		sa(&(data->stack_a));
	else if (data->len_a == 3)
		sort_three(&data);
	else if (data->len_a <=5)
		sort_five(&data);
	else
	{
		sort_a_to_b(&(data));
		sort_b_to_a(&(data));
	}
	ft_free(&data);
	return (0);
}
