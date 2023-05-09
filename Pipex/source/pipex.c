/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:52:23 by memahote          #+#    #+#             */
/*   Updated: 2023/05/09 17:08:32 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdio.h>
#include <errno.h>


int main(int argc, char **argv, char **envp) // main 
{
    int fd_in;
    int fd_out;
    int p_fd[2];
    int pid;

    if (argc != 5)
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
    {
        parent_process(argv, p_fd, fd_out, envp);
    }
}
        // waitpid(pid - 1, NULL, 0);
        // waitpid(pid, NULL, 0);

void    error(int   fd_in, int fd_out, char **argv)
{
    if (fd_in== -1 && fd_out == -1)
    {
        ft_putstr_fd(argv[4], 2);
        perror(" ");
        ft_putstr_fd(argv[1], 2);
        perror(" ");
        exit(1);
    }
    else if (fd_in >= 0 && fd_out == -1)
    {
        ft_putstr_fd(argv[4], 2);
        perror(" ");
        exit(1);
    }
    else if (fd_in == -1 && fd_out >= 0)
    {
        ft_putstr_fd(argv[1], 2);
        perror(" ");
    }
}

// reste a faire :
/*
Faire le bonus : necessite de recommencer
gestion d'erreur : return les meme erreur que bash (FAIT)
    -> gerer le fait que l'on a pas acces a certain fichier (FAIT)
faire un makeile qui marche (FAIT)
gerer les leaks

*/

/*bonus*/

// int main(int argc, char **argv, char **envp)
// {
//     int fd_in;
//     int fd_out;
//     int p_fd[2];
//     int pid;
//     int i;

    
//     if (argc < 5)
//         exit(1);
//     fd_in = open(argv[1], O_RDONLY);
//     fd_out = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
//     error(fd_in, fd_out, argv);
//     i = 2;
//     dup2(fd_in, 0);
//     while (i < argc - 2) // index dernier commande
//     {
//         if(pipe(p_fd) == -1)
//             exit (1);
//         pid = fork();
//         if (pid == -1)
//              exit (1);
//         if (pid == 0) //child
//         {
//             close(p_fd[0]);
//             dup2(p_fd[1], 1);
//             do_cmd(argv[i], envp);
//         }
//         else
//         {
//             close(p_fd[1]);
//             dup2(p_fd[0], 0);
//         }
//     }
//     dup2(fd_out, 1);
//     do_cmd(argv[argc - 2], envp);
// }

// int main(int argc, char **argv, char **envp) // main for transition for bonus 
// {
//     int fd_in;
//     int fd_out;
//     int p_fd[2];
//     int pid;
//     int i;

    
//     if (argc < 5)
//         exit(1);
//     fd_in = open(argv[1], O_RDONLY);
//     fd_out = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
//     error(fd_in, fd_out, argv);
//     dup2(fd_in, 0);
//     dup2(fd_out, 1);
//     i = 2;
//         pipe(p_fd);
//     while (i < argc - 2)
//     {
//         pid = fork();
//         if (pid < 0)
//             exit(1);
//         if (pid == 0)
//         {
//             dup2(p_fd[1], 1);
//             close(p_fd[0]);
//             do_cmd(argv[i], envp);
//         }
//         else
//         {
//             dup2(p_fd[0], 0);
//             close(p_fd[1]);
//         } 
//         i++;  
//     }
//     do_cmd(argv[argc - 2], envp);
// }