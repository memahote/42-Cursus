/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:55:54 by itouil            #+#    #+#             */
/*   Updated: 2024/02/18 16:32:25 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_has_heredoc(t_minishell *ms)
{
	if (ms->cmd_lst->has_heredoc == YES)
	{
		ft_free_heredoc(0, ms);
		signal(SIGINT, ft_handler_heredoc);
		signal(SIGQUIT, SIG_IGN);
	}
}

int	ft_perror(t_minishell *ms, char *error, int free_flag, char *cmd)
{
	dup2(STDERR_FILENO, STDOUT_FILENO);
	if (error && !ft_strcmp(error, E_CMD))
		printf("%s: %s\n", cmd, error);
	else if (error)
	{
		g_exit_status = 1;
		if (!ft_strcmp(error, E_HEREDOC))
			printf("minishell: %s (wanted '%s')\n", E_HEREDOC, cmd);
		else
			printf("minishell: %s\n", error);
		if (!ft_strcmp(error, E_SYNTAX))
			g_exit_status = 2;
	}
	if (free_flag == YES)
		ft_free_all(ms, NO, YES);
	return (EXIT_FAILURE);
}

int	ft_everything_is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_space(str[i]) == NO)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	ft_count_redir(t_token *first, t_type type1, t_type type2)
{
	int		n_redirs;
	t_token	*curr;

	n_redirs = 0;
	curr = first;
	while (curr && curr->type != T_PIPE)
	{
		if (curr->type == type1 || curr->type == type2)
			n_redirs++;
		curr = curr->next;
	}
	return (n_redirs);
}
