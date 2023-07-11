/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:41:04 by memahote          #+#    #+#             */
/*   Updated: 2023/04/15 16:04:55 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (i == 2)
		file = open(argv, O_RDONLY, 0644);
	return (file);
}

void    do_pipe(char *argv, char **envp)
{
    int	    pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		close(p_fd[0]);
		dup2(p_fd[1], 1);
		do_cmd(argv, envp);
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
	}
}

void	here_doc(char *limiter, int argc)
{
	int	    pid;
	int		p_fd[2];
	char	*line;

	if (argc < 6)
		exit(1);
	if (pipe(p_fd) == -1)
		exit(1);
	pid = fork();
	if (pid == 0)
	{
		close(p_fd[0]);
		line = get_next_line(0);
		while (line)
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(p_fd[1], line, ft_strlen(line));
			line = get_next_line(0);
		}
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
	}
}

void	execute_last_cmd(char *cmd, char *envp[])
{
	pid_t	child;

	child = fork();
	if (child > 0)
		waitpid(child, NULL, 0);
	else
		do_cmd(cmd, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	fd_in;
	int	fd_out;

	if (argc < 5)
		exit(1);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		i = 3;
		fd_out = open_file(argv[argc - 1], 0);
		here_doc(argv[2], argc);
	}
	else
	{
		i = 2;
		fd_out = open_file(argv[argc - 1], 1);
		fd_in = open_file(argv[1], 2);
		dup2(fd_in, 0);
	}
	while (i < argc - 2)
		do_pipe(argv[i++], envp);
	dup2(fd_out, 1);
	execute_last_cmd(argv[argc - 2], envp);
	return (0);
}