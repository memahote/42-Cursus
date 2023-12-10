/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:19:57 by memahote          #+#    #+#             */
/*   Updated: 2023/12/03 14:19:57 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		check_pipe_syntaxe(t_list **token)
{
	t_list *tmp;

    tmp = *token;
	while(tmp)
	{
		if (tmp->type == PIPE_LINE)
		{
            if (tmp->prev == NULL || tmp->next == NULL || tmp->prev->type != -1\
			|| tmp->next->type != -1 )
                return (0);
        }
		tmp = tmp->next;
	}
	return (1);
}

int	check_redir_syntax(t_list **token)
{
	t_list *tmp;

    tmp = *token;
	while (tmp)
	{
		 if (tmp->type == 60 || tmp->type == 62 || tmp->type == 63 || tmp->type == 64)
		{
            if (tmp->next == NULL || tmp->next->type != -1)
				return(0);
        }
		tmp = tmp->next;
	}
	return (1);
}


int check_syntax(t_list **token)
{
    if(!check_pipe_syntaxe(token))
		return (1);
	else if(!check_redir_syntax(token))
		return (2);
	else
		return (0);
}
