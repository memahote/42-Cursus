/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:59:19 by memahote          #+#    #+#             */
/*   Updated: 2023/12/17 15:59:19 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
// #include "parser.h"

void	fill_redirl(t_list_redir **redir_l, t_list **token)
{
	t_list	*tmp;

	tmp = *token;
	while(tmp->type != PIPE_LINE && tmp != NULL)
	{
		if(tmp->type == REDIR_IN || tmp->type == REDIR_OUT || \
		tmp->type == HERE_DOC || tmp->type == DREDIR_OUT)
		{
			add_back_redir(redir_l, new_redir_cont(tmp->next->content, \
			tmp->type));
		}
		tmp = tmp->next;
	}
}

void print_redir(t_list_redir *redirl) 
{
	while (redirl) 
	{
        printf("Type redir: %d, file: %s\n", redirl->type, redirl->file);
        redirl = redirl->next;
    }
}


int fill_cmd(t_list **token, char **args, t_list_redir **redir_l)
{
	t_list *tmp;
	int 	i;

	tmp = *token;
	i = 0;

	while (tmp && tmp->type != PIPE_LINE)
	{
		if(tmp->type == WORD && tmp->state == OUTSIDE)
		{
			args[i++] = tmp->content;
		}
		else if (tmp->state == IN_DQUOTE || tmp->state == IN_SQUOTE)
		{
			args[i] = ft_strdup("");
			while(tmp && tmp->state != OUTSIDE)
			{
				if (tmp->type == ENV && tmp->state == IN_DQUOTE)
				{
					if(get_env(tmp->content) != NULL)
						args[i] = ft_strjoin(args[i], get_env(tmp->content));
				}
				else
					args[i] = ft_strjoin(args[i], tmp->content);
				tmp = tmp->next;
			}
			i++;
		}
		else if(tmp->type == REDIR_IN || tmp->type == REDIR_OUT || \
		tmp->type == HERE_DOC || tmp->type == DREDIR_OUT)
		{
			add_back_redir(redir_l, new_redir_cont(tmp->next->content, tmp->type));
			tmp = tmp->next;
		}
		if(tmp)
			tmp = tmp->next;
	}
	args[i]=NULL;
	return (EXIT_SUCCESS);
}


void print_arg(char	**args) 
{
	int i = 0;
	while (args[i]) 
	{
        printf("arg: %s\n", args[i]);
		i++;
    }
}

t_tree_node	*parser_cmd(t_list **token, char **env)
{
	t_tree_node		*new;
	char			**args;
	int				nb_args;
	t_list_redir	*redir_l;


	redir_l = NULL;
	nb_args = count_args(*token);
	args = malloc(sizeof(char *) * (nb_args + 1));
	if(!args)
		return (NULL);
	if(fill_cmd(token, args, &redir_l) == EXIT_FAILURE)
		return (NULL);
	new = new_cmd(args, redir_l, env);
	print_arg(args);
	// print_redir(redir_l);
	return(new);
}

// int	parser(t_tree *tmp, t_list *token, char **env)
// {
// 	t_tree_node	*tree_node;

// 	tree_node = NULL;
// 	if (!token)
// 		return (EXIT_FAILURE);
// 	tree_node = parser_cmd(&token, env);
// 	if (!tree_node)
// 		return (EXIT_FAILURE);
// 	if (!(tmp)->tree_root)
// 	{
// 		ft_putstr_fd("la", 2);
// 		(tmp)->tree_root = tree_node;
// 	}
// 	else
// 	{
// 		if (!(tmp)->tree_root->content->pipe->right)
// 			(tmp)->tree_root->content->pipe->right = tree_node;
// 		else
// 			(tmp)->tree_root->content->pipe->left = tree_node;
// 	}
// 	if (token && token->type == PIPE_LINE)
// 	{
// 		tree_node = parse_pipe(&token);
// 		tree_node->content->pipe->right = (tmp)->tree_root;
// 		(tmp)->tree_root = tree_node;
// 	}
// 	parsertmp, token, env);
// 	return (EXIT_SUCCESS);
// }

int	parser(t_tree **tree, t_list *token, char **env)
{
	t_tree_node	*tree_node;
	// t_tree		*tmp;

	tree_node = NULL;
	// tmp = *tree;
	// Vérifiez si la liste de tokens est vide
	if (!token)
		return (EXIT_FAILURE);

	// Parsez la commande à partir des tokens
	tree_node = parser_cmd(&token, env);

	// Vérifiez si la commande a été correctement analysée
	if (!tree_node)
		return (EXIT_FAILURE);
	// Si l'arbre est vide, ajoutez la nouvelle commande comme racine
	// if (!(tmp)->tree_root)
	// {
		// (tmp)->tree_root = tree_node;
	// }
	// else
	// {
	// 	// Si la racine a déjà un côté droit, ajoutez la nouvelle commande comme côté gauche
	// 	if (!(tmp)->tree_root->content->pipe->right)
	// 		(tmp)->tree_root->content->pipe->right = tree_node;
	// 	else
	// 		(tmp)->tree_root->content->pipe->left = tree_node;
	// }

	// Si le token suivant est un PIPE_LINE, parsez une nouvelle commande et mettez-la à droite de la racine
	// if (token && token->type == PIPE_LINE)
	// {
	// 	tree_node = parse_pipe(&token);
	// 	tree_node->content->pipe->right = (tmp)->tree_root;
	// 	(tmp)->tree_root = tree_node;
	// }

	// Appel récursif pour traiter le reste des tokens
	return parser(tree, token, env);
}
