/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:25:31 by memahote          #+#    #+#             */
/*   Updated: 2023/12/31 23:17:20 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// si je suis deja la jdoit aller , je fait rien

int	err_home(char *arg)
{
	if (!arg)
	{
		ft_putstr_fd("cd: HOME not set\n", 2);
		return (EXIT_SUCCESS);
	}
	if (!ft_strcomp(arg, "~"))
	{
		return (EXIT_SUCCESS);
	}
	if(ft_strcomp(arg, "HOME"))
	{
		ft_putstr_fd("cd: HOME: No such file or directory\n", 2);
		return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}


int	ft_cd(t_cmd *cmd)
{
	char	*home_path;

	home_path = get_env("HOME");
	if (cmd->nb_args > 2)
		return (ft_putstr_fd("cd: too many arguments\n", 2), EXIT_SUCCESS);
	if (cmd->nb_args == 1 || !ft_strcomp(cmd->args[1], "~") || \
		!ft_strcomp(cmd->args[1], "HOME"))
	{
		printf("VALEUR %d\n", chdir(home_path));
		if(chdir(home_path) != 0)
			err_home(cmd->args[1]);
	}
	return (EXIT_SUCCESS);
}
