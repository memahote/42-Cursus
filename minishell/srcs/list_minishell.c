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
	char *cont;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	cont = ft_strndup(content, len);
	if(!cont)
		return (NULL);
	list -> content = cont;
	// printf("Content :%s ", list->content);
	list -> len = len;
	// printf("len : %i ", list->len);
	list -> type = type;
	// printf("Type : %i ", list->type);
	list -> state = state;
	// printf("state : %i \n\n", list->state);
	list -> next = NULL;
	return (list);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!*lst)
		*lst = new;
	current = *lst;
	while(current->next != NULL)
		current = current->next;
	current->next = new;

}
