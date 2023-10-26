/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:32:15 by memahote          #+#    #+#             */
/*   Updated: 2023/10/26 16:10:46 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}

void	ft_close_all(t_struct *data)
{
	close(data->fd_in);
	close(data->fd_out);
	close(data->p_fd[0]);
	close(data->p_fd[1]);
}

void	exit_fork(t_struct *data)
{
	ft_close_all(data);
	ft_putstr_fd("FORK : Error\n", 2);
	exit(1);
}

void	exit_pipe(t_struct *data)
{
	ft_close_all(data);
	ft_putstr_fd("PIPE : Error\n", 2);
	exit(1);
}

void	check_dup(int fd, int input)
{
	if (dup2(fd, input) == -1)
	{
		perror("DUP : Error\n");
		exit(EXIT_FAILURE);
	}
}
