/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:25:36 by memahote          #+#    #+#             */
/*   Updated: 2023/12/30 22:26:06 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list_env	*new_var_env(char *var)
{
	t_list_env	*new_elem;

	new_elem = malloc(sizeof(t_list_env));
	if (!new_elem)
		return (NULL);
	new_elem->var = ft_strdup(var);
	new_elem->prev = NULL;
	new_elem->next = NULL;
	return (new_elem);
}

void	add_back_env(t_list_env **env, t_list_env *new)
{
	t_list_env	*current;

	current = *env;
	if (!*env)
	{
		*env = new;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	new->prev = current;
}

void	create_env(char **envp, t_list_env **env)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		add_back_env(env, new_var_env(envp[i]));
		i++;
	}
}

int	ft_env(t_list_env *env)
{
	while (env)
	{
		ft_putstr_fd(env->var, 1);
		ft_putchar_fd('\n', 1);
		env = env->next;
	}	
	return (EXIT_SUCCESS);
}