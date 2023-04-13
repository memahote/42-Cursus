/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:41:04 by memahote          #+#    #+#             */
/*   Updated: 2023/04/13 15:16:56 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    do_cmd(char *cmd, char **envp)
{
    char    *path;
    char    **comand;

    path = get_path(cmd, envp);
    comand = ft_split(cmd, ' ');
    if (execve(path, comand, envp) < 0)
    {
        ft_putstr_fd(comand[0], 2);
        ft_putendl_fd(": comand not found", 2);
        free(comand);
        exit(0);
    }
}