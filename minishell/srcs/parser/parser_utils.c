/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:06:19 by memahote          #+#    #+#             */
/*   Updated: 2023/12/25 20:54:46 by memahote         ###   ########lyon.fr   */
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