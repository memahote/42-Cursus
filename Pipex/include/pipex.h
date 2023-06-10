/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:38:07 by memahote          #+#    #+#             */
/*   Updated: 2023/06/10 16:37:12 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <sys/wait.h>
#include <stdio.h>
#include <errno.h>


typedef struct s_struct
{
    int fd_in;
    int fd_out;
    int p_fd[2];
    int first_child_pid;
    int second_child_pid;
    
}       t_struct;

char    *get_path_from_envp(char **envp);
void	ft_free_tab(char **tab);
char    *get_path(char *cmd, char **envp);
void    do_cmd(char *cmd, char **envp);
void    child_process(char **argv, int *p_fd, int in_fd, char **envp);
void    second_child_process(char **argv, int *p_fd, int out_fd, char **envp);
void    error(int fd_in, int fd_out, char **argv);

#endif