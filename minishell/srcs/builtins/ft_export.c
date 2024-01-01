/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:25:38 by memahote          #+#    #+#             */
/*   Updated: 2024/01/01 06:05:08 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//export test="saluttoi$HOME/dsfsdf" -> A Gerer
// export $PWD$HOME -> erreur a gerer

int	ft_export(t_list_env **env, t_cmd *cmd)
{
	int i;
	char	*str;
	// int 	len;
	t_list_env *tmp;

	i = 1;
	tmp = (*env);
	if (!cmd->args[1])
	{
		print_env_sort(env);
		return (EXIT_SUCCESS);
	}
	while (cmd->args[i])
	{
		if (!ft_isdigit(cmd->args[i][0]))
		{
			if (cmd->args[i][0] == '$')
			{
				str = get_env(cmd->args[i]);
				add_back_env(env, new_var_env(ft_strjoin(cmd->args[i - 1], str)));
			}
			else if (ft_strchr(cmd->args[i], '=') != NULL)
			{
				// if ()
				printf("dgfdgdf ;%s \n", cmd->args[i]);
				// len = ft_strlen(cmd->args[i]);
				// if (cmd->args[i][len - 1] == '=')
				// {
				// 	str = ft_strjoin(cmd->args[i - 1], cmd->args[i]);
				// 	add_back_env(env, new_var_env(str));
				// }
				// else
				// 	add_back_env(env, new_var_env(cmd->args[i]));			
			}
		}
		else
		{
			ft_putstr_fd("export: ", 2);
			ft_putstr_fd(cmd->args[i], 2);
			ft_putstr_fd(": not a valid identifier\n", 2);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
