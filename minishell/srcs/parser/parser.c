/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:59:19 by memahote          #+#    #+#             */
/*   Updated: 2023/12/17 15:59:19 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_args(t_list *token) // Size for malloc command + arg
{
	t_list *tmp;
	int		i;

	i = 0;
	while (tmp && tmp->type != PIPE_LINE)
	{
		if (tmp->type == WORD || tmp->type == ENV)
		{
			i++;
			tmp = tmp->next
		}
		else if (tmp->type == SQUOTE)
		{
			tmp = tmp->next
			while(tmp->type != SQUOTE)
				tmp = tmp->next;
			i++;
		}
		else if (tmp->type == DQUOTE)
		{
			tmp = tmp->next
			while(tmp->type != DQUOTE)
				tmp = tmp->next;
			i++;
		}
		else
			tmp = tmp->next
	}
	return (i);
}