/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:19:03 by memahote          #+#    #+#             */
/*   Updated: 2023/07/06 13:17:23 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    child_process(char **argv, int *p_fd, int in_fd, char **envp)
{
    dup2(in_fd, 0);
    dup2(p_fd[1], 1);
    close(p_fd[0]);
    do_cmd(argv[2], envp);
    exit(1);
}

void    second_child_process(char **argv, int *p_fd, int out_fd, char **envp)
{
    dup2(out_fd, 1);
    dup2(p_fd[0], 0);
    close(p_fd[1]);
    do_cmd(argv[3], envp);
    exit(1);
}