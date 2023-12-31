/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:25:38 by memahote          #+#    #+#             */
/*   Updated: 2023/12/31 00:17:24 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//ft_export

//ajoute une nouvelle var a la suite de la liste chainé de env
// Si n'est pas de la forme export var=valeur ne fait rien

int	ft_export(t_list_env **env, t_cmd *cmd)
{
	int i;

	i = 0;
	if (!cmd->args[1]) // Export sans arg
		return (EXIT_SUCCESS);
	else
	{
		while (cmd->args[i])
		{
			if (ft_strchr(cmd->args[i], '=') != NULL)
				add_back_env(env, new_var_env(cmd->args[i]));
			i++;
		}
	}
	return (EXIT_SUCCESS);
}