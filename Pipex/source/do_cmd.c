/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:41:04 by memahote          #+#    #+#             */
/*   Updated: 2023/04/06 11:30:25 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    do_cmd(char *cmd, char **envp)
{
    char    *path;
    char    **comand;

    path = get_path(cmd, envp);
    comand = ft_split(cmd, ' ');
    if (execve(path, comand, envp))
    {
        exit(1);
    }
}