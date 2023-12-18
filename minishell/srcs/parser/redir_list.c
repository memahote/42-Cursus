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
#include "lexer.h"
#include "parser.h"

// void	free_redir_list(t_list_redir **list)
// {
// 	t_list	*tmp;
// 	t_list	*next;

// 	if (!*list)
// 		return ;
// 	tmp = *list;
// 	while (tmp)
// 	{
// 		next = tmp->next;
// 		free(tmp->file);
// 		free(tmp);
// 		tmp = next;
// 	}
// }

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

void	add_back_redir(t_list_redir **lst, t_list_redir *new)
{
	t_list_redir	*current;

	current = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}