/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_st_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:27:53 by memahote          #+#    #+#             */
/*   Updated: 2023/01/16 14:28:35 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


static void	clear_tab(char **strs, int i)
{
	if (strs[i])
	{
		while (i >= 0)
		{
			free(strs[i]);
			i--;
		}
		free(strs);
	}
}

// fill the stack a and check if argument are valid
void	fill_st_a( char **argv, int argc, t_struct **data)
{
	char	**tab;
	int		i;
	int		j;

	if (argc > 2)
	{
		i = 1;
		while (argv[i])
		{
			tab = ft_split(argv[i], ' ');
			j = 0;
			while (tab[j])
			{
				if (is_int(tab[j]) == 0)
				{
					clear_tab(tab, j);
					ft_print_error(&(*data));
				}
				(*data)->stack_a = addback((*data)->stack_a,ft_atol(tab[j]));
				free(tab[j]);
				j++;
			}
			free(tab);
			i++;
		}
	}
	else 
	{
		i = 1;
		while (argv[i])
		{
			tab = ft_split(argv[i], ' ');
			j = 0;
			while (tab[j])
			{
				if (is_int(tab[j]) == 0)
				{
					clear_tab(tab, j);
					ft_print_error(&(*data));
				}
				(*data)->stack_a = addback((*data)->stack_a,ft_atol(tab[j]));
				j++;
			}
			clear_tab(tab, j);
			i++;
		}
	}
	if ((*data)->stack_a == NULL)
		ft_print_error(&(*data));
	check_duplicate(&(*data));
}

// pas de leaks pour 559 3 sdf9

