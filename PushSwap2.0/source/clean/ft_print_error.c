/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:24:34 by memahote          #+#    #+#             */
/*   Updated: 2023/01/16 14:30:25 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// print error message and free the stuct
void	ft_print_error(t_struct *data)
{
	ft_putstr_fd("Error\n", 2);
	ft_free(data);
	exit(EXIT_FAILURE);
}

void	ft_free_tab_and_exit(t_struct *data, char **tab, int j)
{
	ft_free_tab(tab, j);
	free(tab);
	ft_print_error(data);
}
