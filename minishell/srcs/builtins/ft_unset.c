/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:25:42 by memahote          #+#    #+#             */
/*   Updated: 2023/12/31 02:49:27 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	ft_unset(t_list_env **env, t_cmd *cmd)
// {
// 	int 		i;
// 	t_list_env 	*head;

// 	if (!cmd->args[1]) // unset sans arg
// 		return (EXIT_SUCCESS);
// 	head = (*env);
// 	while (env)
// 	{
// 		i = 0;
// 		while (cmd->args[i])
// 		{
// 			if (ft_strcomp(((*env)->var), cmd->args[i]))
// 				//suppr la variable	et break	
// 			i++;
// 		}
// 		env = env->next;
// 	}
// 	return (EXIT_SUCCESS);
// }