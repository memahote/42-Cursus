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
	t_list	*new_elem;
	char *cont;

	new_elem = malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	cont = ft_strndup(content, len);
	if(!cont)
		return (NULL);
	new_elem -> content = cont;
	// printf("Content :%s ", list->content);
	new_elem -> len = len;
	// printf("len : %i ", list->len);
	new_elem -> type = type;
	// printf("Type : %i ", list->type);
	new_elem -> state = state;
	// printf("state : %i \n\n", list->state);
	new_elem -> next = NULL;
	new_elem -> prev = NULL;
	return (new_elem);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	current = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while(current->next != NULL)
		current = current->next;
	current->next = new;
	new->prev = current;
}

// t_list	*del_space(t_list *lst)
// {
// 	t_list	*current;
// 	t_list	*head;

// 	current = lst;
// 	head = lst;
// 	while(current->next != NULL)
// 	{
// 		if(current->type == 0 && current->state == 2)
// 		{
// 			if (current->prev != NULL)
// 				current->prev->next = current->next;
// 			else
// 				head = current ->next;
// 			free(current);
// 			current=current->next;
// 		}
// 		else
// 			current = current->next;
// 	}
// 	return (head);
// }
void del_space(t_list **head)
{
    t_list *current = *head;
    t_list *next_node;

    while (current != NULL)
	{
        next_node = current->next;

        if (current->type == 0 && current->state == 2)
		{
            if (current->prev != NULL)
			{
                current->prev->next = current->next;
            }
			else
			{
                // Si le premier élément est de type 0
                *head = current->next;
            }

            if (current->next != NULL)
			{
                current->next->prev = current->prev;
            }

            // Libérer la mémoire du nœud de type 0
            free(current);
        }

        current = next_node;
    }
}
