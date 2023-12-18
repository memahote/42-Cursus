/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:32:51 by memahote          #+#    #+#             */
/*   Updated: 2023/12/18 14:32:51 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_redir_list(t_list_redir **list)
{
	t_list	*tmp;
	t_list	*next;

	if (!*list)
		return ;
	tmp = *list;
	while (tmp)
	{
		next = tmp->next;
		free(tmp->file);
		free(tmp);
		tmp = next;
	}
}

t_list_redir	*new_redir_cont(char *file, enum e_token type)
{
	t_list_redir	*new_elem;

	new_elem = malloc(sizeof(t_list_redir));
	if (!new_elem)
		return (NULL);
	new_elem->file = file;
	new_elem->type = type;
	new_elem->next = NULL;
	return (new_elem);
}

