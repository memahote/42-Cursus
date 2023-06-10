/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:52:23 by memahote          #+#    #+#             */
/*   Updated: 2023/06/10 16:30:10 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdio.h>
#include <errno.h>
int open_file(char *file, int choice);
void	if_no_infile(t_struct *data);

int main(int argc, char **argv, char **envp) // main 
{
   t_struct data;
   
    
    if (argc != 5)
        exit(1);
    data.fd_in = open_file(argv[1], 1);
    if_no_infile(&data);
    data.fd_out = open_file(argv[argc -1], 2);
    if (data.fd_in == -1 && data.fd_out == -1)
        exit(1);
    pipe(data.p_fd);
    data.first_child_pid = fork();
    if (data.first_child_pid < 0)
        exit(1);
    if (data.first_child_pid == 0)
        child_process(argv, data.p_fd, data.fd_in, envp);
   data.second_child_pid = fork();
    if (data.second_child_pid < 0)
        exit(1);
    if (data.second_child_pid == 0)
        second_child_process(argv, data.p_fd, data.fd_out, envp);
    waitpid(data.first_child_pid, NULL, 0);
    waitpid(data.second_child_pid, NULL, 0);
}       


int open_file(char *file, int choice)
{
    int fd;
    
    fd = 0;
    if (choice == 1)
    {
        fd = open(file, O_RDONLY);
	    if (fd == -1)
		    perror(file);
	    return (fd); 
    }
    if (choice == 2)
    {
        fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	    if (fd == -1)
		    perror(file);
	    return (fd);
    }
    return(fd);
}


void	if_no_infile(t_struct *data)
{
	if (data->fd_in == -1)
	{
		pipe(data->p_fd);
		close(data->p_fd[1]);
		data->fd_in = data->p_fd[0];
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

