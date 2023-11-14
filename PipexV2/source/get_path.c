/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:08:08 by memahote          #+#    #+#             */
/*   Updated: 2023/11/14 16:01:24 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

char	*get_path(char *cmd, char **envp)
{
	char	**fullpath;
	char	**command;
	char	*possible_path;
	char	*exec_cmd;
	int		i;

	fullpath = ft_split(get_path_from_envp(envp), ':');
	command = ft_split(cmd, ' ');
	if (!fullpath)
	{
		ft_putstr_fd(command[0], 2);
		ft_putstr_fd(":No such file or directory\n", 2);
	}
	if (command[0][0] == '/' || (command[0][0] == '.' && command[0][1] == '/'))
	{
		if (access(command[0], F_OK | X_OK) == -1)
			return (NULL);
		return (command[0]);
	}
	i = -1;
	while (fullpath[++i])
	{
		possible_path = ft_strjoin(fullpath[i], "/");
		exec_cmd = ft_strjoin(possible_path, command[0]);
		free(possible_path);
		if (access(exec_cmd, F_OK | X_OK) == 0)
			return (ft_free_tab(command), ft_free_tab(fullpath), exec_cmd);
		free(exec_cmd);
	}
	return (ft_free_tab(command), ft_free_tab(fullpath), NULL);
}
