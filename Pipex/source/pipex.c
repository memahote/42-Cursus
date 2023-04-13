/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:52:23 by memahote          #+#    #+#             */
/*   Updated: 2023/04/13 15:46:05 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
    int fd_in;
    int fd_out;
    int p_fd[2];
    int pid;

    
    if (argc < 5)
        exit(1);
    fd_in = open(argv[1], O_RDONLY);
    fd_out = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
    error(fd_in, fd_out, argv);
    pipe(p_fd);
    pid = fork();
    if (pid < 0)
        exit(1);
    if (pid == 0)
        child_process(argv, p_fd, fd_in, envp);
    else
        parent_process(argv, p_fd, fd_out, envp);
}


void    error(int   fd_in, int fd_out, char **argv)
{
    if (fd_in== -1 && fd_out == -1)
    {
        ft_putstr_fd(argv[4], 2);
        ft_putendl_fd(": Permission denied", 2);
        ft_putstr_fd(argv[1], 2);
        ft_putendl_fd(": Permission denied", 2);
        exit(1);
    }
    else if (fd_in >= 0 && fd_out == -1)
    {
        ft_putstr_fd(argv[4], 2);
        ft_putendl_fd(": Permission denied", 2);
        exit(1);
    }
    else if (fd_in == -1 && fd_out >= 0)
    {
        ft_putstr_fd(argv[1], 2);
        ft_putendl_fd(": Permission denied", 2);
    }
}

// reste a faire :
/*
Faire le bonus : necessite de recommencer
gestion d'erreur : return les meme erreur que bash (FAIT)
    -> gerer le fait que l'on a pas acces a certain fichier (FAIT)
faire un makeile qui marche
gerer les leaks

*/