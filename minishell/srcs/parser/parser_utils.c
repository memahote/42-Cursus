/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:06:19 by memahote          #+#    #+#             */
/*   Updated: 2023/12/28 14:49:13 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tree	*init_tree(t_tree *tree)
{
	tree = malloc(sizeof(t_tree));
	if (!tree)
		return (NULL);
	tree->tree_root = NULL;
	return (tree);
}

t_tree_node		*new_cmd(char **args, t_list_redir *redir, char **env)
{
	t_tree_node	*node;

	node = malloc(sizeof(t_tree_node));
	node->content = malloc(sizeof(t_type));
	node->content->cmd = malloc(sizeof(t_cmd));
	if (!node || !node->content || !node->content->cmd)
		return (NULL);
	node->type = CMD;
	node->content->cmd->args = args;
	node->content->cmd->env = env;
	node->content->cmd->redir = redir;
	node->content->cmd->fd_in = 0;
	node->content->cmd->fd_out = 1;
	return (node);
}

void	free_redir_list(t_list_redir *list)
{
	while (list)
	{
		free(list->file);
		free(list);
		list = list->next;
	}
}

void	free_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i])
	{
		free(cmd->args[i]);
		i++;
	}
	free(cmd->args);
	free_redir_list(cmd->redir);
	free(cmd);
}

void	free_tree(t_tree_node *node)
{
	if (node->type == CMD)
	{
		// ft_putstr_fd("jss la\n", 2);
		free_cmd(node->content->cmd);
		free(node->content);
		free(node);
		ft_putstr_fd("COCA BIEN FREE CHAKAL\n", 2);
	}
	else if (node->type == PIPE)
	{
		// ft_putstr_fd("jss la pipe\n", 2);
		// ft_putstr_fd("entre right\n", 2);
		free_tree(node->content->pipe->right);
		// ft_putstr_fd("free right\n", 2);
		// ft_putstr_fd("entre left\n", 2);
		free_tree(node->content->pipe->left);
		// ft_putstr_fd("free left\n", 2); 
		free(node->content->pipe);
		free(node->content);
		free(node);
		ft_putstr_fd("BIEN FREE MON REUF\n", 2);
	}
}

