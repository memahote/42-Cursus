/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:19:03 by memahote          #+#    #+#             */
/*   Updated: 2023/11/10 17:25:04 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, t_struct *data, char **envp)
{

	if(data->fd_in < 0)
		exit(1);
	check_dup(data->fd_in, 0);
	check_dup(data->p_fd[1], 1);
	close(data->p_fd[0]);	
	do_cmd(argv[2], envp, data);
	ft_close_all(data);
	exit(1);
}

void	second_child_process(char **argv, t_struct *data, char **envp)
{
	check_dup(data->fd_out, 1);
	check_dup(data->p_fd[0], 0);
	close(data->p_fd[1]);
	do_cmd(argv[3], envp, data);
	ft_close_all(data);
	exit(1);
}
