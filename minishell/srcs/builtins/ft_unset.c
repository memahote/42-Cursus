/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:25:42 by memahote          #+#    #+#             */
/*   Updated: 2023/12/31 21:31:24 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_env_var(t_list_env *head)
{
	t_list_env	*current;
	t_list_env	*next_node;

	current = head;
	next_node = current->next;
	if (current->prev != NULL)
		current->prev->next = current->next;
	else
		head = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;
	free(current->var);
	free(current);
	printf("unset %s\n", (head)->var);
	// printf("after unset %s\n", (head)->next->var);
}

int	ft_unset(t_list_env **env, t_cmd *cmd)
{
	int 		i;
	t_list_env 	*head;

	if (!cmd->args[1]) // unset sans arg
		return (EXIT_SUCCESS);
	head = (*env);
	i = 1;
	while (cmd->args[i])
	{
		(*env) = head;
		while ((*env))
		{
			if (ft_strcomp(((*env)->var), cmd->args[i]) == 0)
			{
				printf("hehe %s\n", (*env)->var);
				del_env_var(*env);
				break ;
			}
			(*env) = (*env)->next;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}