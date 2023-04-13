/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:38:07 by memahote          #+#    #+#             */
/*   Updated: 2023/04/13 15:35:47 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"


char    *get_path_from_envp(char **envp);
void	ft_free_tab(char **tab);
char    *get_path(char *cmd, char **envp);
void    do_cmd(char *cmd, char **envp);
void    child_process(char **argv, int *p_fd, int in_fd, char **envp);
void    parent_process(char **argv, int *p_fd, int in_fd, char **envp);
void    error(int fd_in, int fd_out, char **argv);

#endif