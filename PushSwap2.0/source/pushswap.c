/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:39:34 by memahote          #+#    #+#             */
/*   Updated: 2023/04/05 13:59:19 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
		sa(&(data->stack_a), data->print);
	else if (data->len_a <= 10)
		sort_small(data);
	else
	{
		sort_a_to_b(data);
		sort_b_to_a(&data);
	}
	ft_free(data);
	return (0);
}
