/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:45:52 by memahote          #+#    #+#             */
/*   Updated: 2023/11/29 21:45:52 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	free_list(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		free(tmp->content);
		free(tmp);
		tmp = tmp->next;
	}
	free(list);
}

t_list	*init_list(t_list *list)
{
	list = ft_calloc(sizeof(t_list), 1);
	if (!list)
		return (NULL);
	return (list);
}

t_list	*new_cont(char *content, int len, enum e_token type, enum e_state state)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list -> content = content;
	list -> len = len;
	list -> type = type;
	list -> state = state;
	list -> next = NULL;
	return (list);
}
