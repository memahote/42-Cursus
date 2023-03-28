/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_st_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:27:53 by memahote          #+#    #+#             */
/*   Updated: 2023/03/28 18:10:33 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	one_arg_filling(char **argv, t_struct *data)
{
	int		i;
	int		j;
	char	**tab;
	
	i = 0;
	tab = ft_split(argv[i], ' ');
	j = 0;
	while (tab[j])
	{
		if (is_int(tab[j]) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		data->stack_a = addback(data->stack_a,ft_atol(tab[j]));
		j++;
	}
	free(tab);
	i++;
}

void	mult_arg_filling(char **argv, t_struct *data)
{
	int		i;
	int		j;
	char	**tab;

	i = 1;
	while (argv[i])
	{
		tab = ft_split(argv[i], ' ');
		j = 0;
		while (tab[j])
		{
			if (is_int(tab[j]) == 0)
			{
				ft_putstr_fd("Error\n", 2);
				exit(EXIT_FAILURE);
			}
			data->stack_a = addback(data->stack_a,ft_atol(tab[j]));
			j++;
		}
		free(tab);
		i++;
	}
}

void	fill_st_a(int argc, char **argv, t_struct *data)
{
	if (argc > 2)
		mult_arg_filling(argv, data);
	else
		one_arg_filling(argv, data);
	if (!data->stack_a)
		ft_print_error(data);
	check_duplicate(data);
}
