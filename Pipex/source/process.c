/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:19:03 by memahote          #+#    #+#             */
/*   Updated: 2023/05/09 15:36:57 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    child_process(char **argv, int *p_fd, int in_fd, char **envp)
{
    // copie du infile dqns l'entre standard
    dup2(in_fd, 0);
    // sortie standard devien une copie de p_fd[1] 
    dup2(p_fd[1], 1);
    // on ferme la sortie du pipe car on utilise seulement l'entre
    close(p_fd[0]);
    // trouver la commande et le chemin 
    do_cmd(argv[2], envp);
}

void    parent_process(char **argv, int *p_fd, int out_fd, char **envp)
{
    dup2(out_fd, 1);
    dup2(p_fd[0], 0);
    close(p_fd[1]);
    do_cmd(argv[3], envp);
}