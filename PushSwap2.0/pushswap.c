/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:39:34 by memahote          #+#    #+#             */
/*   Updated: 2023/03/31 15:15:09 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_struct	*data;

	data = ft_calloc(1, sizeof(t_struct));
	if (!data)
		exit(1);
	if (argc == 1)
		ft_free_and_exit(data);
	initialize_struct(data, argv, argc);
	if (is_sorted(data->stack_a) || data->len_a == 1)
		ft_free_and_exit(data);
	if (data->len_a == 2)
		sa(&(data->stack_a));
	else if (data->len_a == 3)
		sort_three(data);
	else if (data->len_a <= 5)
		sort_five(data);
	else
	{
		sort_a_to_b(data);
		sort_b_to_a(&data);
	}
	ft_free(data);
	return (0);
}
