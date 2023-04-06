/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:52:23 by memahote          #+#    #+#             */
/*   Updated: 2023/04/06 12:29:39 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
    int in_fd;
    int out_fd;
    int p_fd[2];
    int pid;

    
    if (argc < 5)
        exit(1);
    in_fd = open(argv[1], O_RDONLY);
    out_fd = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (!(in_fd || out_fd))
        exit(1);
    pipe(p_fd);
    pid = fork();
    if (pid < 0)
        exit(1);
    if (pid == 0)
        child_process(argv, p_fd, in_fd, envp);
    else
        parent_process(argv, p_fd, out_fd, envp);
}




// reste a faire :
/*
Faire le bonus : ecessite de recommencer
gestion d'erreur : return les meme erreur que bash
    -> gerer le fait que l'on a pas acces a certain fichier 
faire un makeile qui marche
gerer les leaks

*/