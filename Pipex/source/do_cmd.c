/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:41:04 by memahote          #+#    #+#             */
/*   Updated: 2023/07/20 23:35:09 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// char    *do_cmd(char *cmd, char **envp, t_struct *data)
// {
//     char    *path;
//     char    **command;
    
//     path = get_path(cmd, envp);
//     command = ft_split(cmd, ' ');
//     if (execve(path, command, envp) < 0)
//     {
//         ft_putstr_fd(command[0], 2);
//         ft_putendl_fd(": command not found", 2);
//         ft_free_tab(command);
//         free (path);
//         ft_close_all(data);
//     }
//     ft_free_tab(command);
//     return(NULL);
// }

void do_cmd(char *cmd, char **envp, t_struct *data)
{
    char *path;
    char **command;

    path = get_path(cmd, envp);
    command = ft_split(cmd, ' ');
    if(!path)
    {
        ft_close_all(data);
        ft_putstr_fd(command[0], 2);
        ft_putendl_fd(": command not found", 2);
        ft_free_tab(command);
        if (path)
            free(path);
        return ;
    }
    if (execve(path, command, envp) < 0)
    {
        ft_putstr_fd(command[0], 2);
        ft_putendl_fd(": command not found", 2);
        ft_free_tab(command);
        if (path)                                            
            free(path);
        ft_close_all(data);
    }
    if (path)
        free(path);
    ft_close_all(data);
}






