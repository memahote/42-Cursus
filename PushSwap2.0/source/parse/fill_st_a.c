/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_st_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:27:53 by memahote          #+#    #+#             */
/*   Updated: 2023/05/23 14:30:17 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	one_arg_filling(char **argv, t_struct *data)
{
	int		j;
	char	**tab;

	tab = ft_split(argv[1], ' ');
	j = 0;
	while (tab[j])
	{
		if (!tab[j])
			ft_free_tab_and_exit(data, tab, j);
		if (is_int(tab[j]) == 0)
			ft_free_tab_and_exit(data, tab, j);
		data->stack_a = addback(data->stack_a, ft_atol(tab[j]));
		free(tab[j]);
		j++;
	}
	free(tab);
	tab = NULL;
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
		if (!tab[j])
			ft_free_tab_and_exit(data, tab, j);
		while (tab[j])
		{
			if (is_int(tab[j]) == 0)
				ft_free_tab_and_exit(data, tab, j);
			data->stack_a = addback(data->stack_a, ft_atol(tab[j]));
			free(tab[j]);
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
