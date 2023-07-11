/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:41:04 by memahote          #+#    #+#             */
/*   Updated: 2023/07/11 04:46:19 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    *do_cmd(char *cmd, char **envp)
{
    char    *path;
    char    **command;

    path = get_path(cmd, envp);
    command = ft_split(cmd, ' ');
    if (execve(path, command, envp) < 0)
    {
        ft_putstr_fd(command[0], 2);
        ft_putendl_fd(": command not found", 2);
        free(command);
        free (path);
        exit(0);
    }
    return(NULL);
}
