/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:00:46 by memahote          #+#    #+#             */
/*   Updated: 2023/11/28 13:00:46 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <readline/readline.h>
#include <readline/history.h>

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void)envp;
	const char *line;

	while (1)
	{
			line = readline("minishell~> ");
			if (!line)
			{
				printf("exit\n");
				exit(1);
			}
			if(ft_strlen(line) > 0)
				add_history(line);
	}
}