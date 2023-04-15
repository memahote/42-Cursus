/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:08:08 by memahote          #+#    #+#             */
/*   Updated: 2023/04/15 16:06:30 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    *get_path(char *cmd, char **envp)
{
    char    **fullpath;
    char    **command;
    char    *possible_path;
    char    *exec_cmd;
    int     i;

    fullpath = ft_split(get_path_from_envp(envp), ':');
    command = ft_split(cmd, ' ');
    i = -1;
    while (fullpath[++i])
    {
        possible_path = ft_strjoin(fullpath[i], "/");
        exec_cmd = ft_strjoin(possible_path, command[0]);
        free(possible_path);
        if(access(exec_cmd, F_OK | X_OK) == 0)
        {
            ft_free_tab(command);
            ft_free_tab(fullpath);
            return (exec_cmd);
        }
        free(exec_cmd);
    }
    ft_free_tab(command);
    ft_free_tab(fullpath);
    return (NULL);
}
