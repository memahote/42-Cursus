/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 04:38:12 by memahote          #+#    #+#             */
/*   Updated: 2024/01/01 05:01:12 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sort_env(t_list_env **env)
{
	t_list_env *tmp;
	char	*val_tmp;

	tmp = ((*env));
	val_tmp = NULL;
	while ((*env)->next)
	{
		if (ft_strcomp((*env)->var, (*env)->next->var) > 0)
		{
			val_tmp = (*env)->var;
			(*env)->var = (*env)->next->var;
			(*env)->next->var = val_tmp;
			(*env) = tmp;
		}
		else
			(*env) = (*env)->next;
	}
	(*env) = tmp;
}

void	print_env_sort(t_list_env **env)
{
	t_list_env *tmp;
	
	tmp = (*env);
	sort_env(&tmp);
	while (tmp)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(tmp->var, 1);
		ft_putchar_fd('\n', 1);
		tmp = tmp->next;	
	}
}
