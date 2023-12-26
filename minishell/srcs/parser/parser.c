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
	// t_list *tmp;
	int 	i;

	// tmp = *token;
	i = 0;

	while ((*token) && (*token)->type != PIPE_LINE)
	{
		if((*token)->type == WORD && (*token)->state == OUTSIDE)
		{
			args[i++] = (*token)->content;
		}
		else if ((*token)->state == IN_DQUOTE || (*token)->state == IN_SQUOTE)
		{
			args[i] = ft_strdup("");
			while((*token) && (*token)->state != OUTSIDE)
			{
				if ((*token)->type == ENV && (*token)->state == IN_DQUOTE)
				{
					if(get_env((*token)->content) != NULL)
						args[i] = ft_strjoin(args[i], get_env((*token)->content));
				}
				else
					args[i] = ft_strjoin(args[i], (*token)->content);
				(*token) = (*token)->next;
			}
			i++;
		}
		else if((*token)->type == REDIR_IN || (*token)->type == REDIR_OUT || \
		(*token)->type == HERE_DOC || (*token)->type == DREDIR_OUT)
		{
			add_back_redir(redir_l, new_redir_cont((*token)->next->content, (*token)->type));
			(*token) = (*token)->next;
		}
		if((*token))
			(*token) = (*token)->next;
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

int	parser(t_tree **tree, t_list *token, char **env)
{
	t_tree_node	*tree_node;

	tree_node = NULL;
	// Vérifiez si la liste de tokens est vide
	if (!token)
		return (EXIT_FAILURE);
	// Parsez la commande à partir des tokens
	tree_node = parser_cmd(&token, env);
	// Vérifiez si la commande a été correctement analysée
	if (!tree_node)
		return (EXIT_FAILURE);
	// Si l'arbre est vide, ajoutez la nouvelle commande comme racine
	if (!(*tree)->tree_root)
	{
		ft_putstr_fd("jss la\n", 2);
		(*tree)->tree_root = tree_node;
	}
	else
	{
		// Si la racine a déjà un côté droit, ajoutez la nouvelle commande comme côté gauche
		if (!(*tree)->tree_root->content->pipe->right)
			(*tree)->tree_root->content->pipe->right = tree_node;
		else
			(*tree)->tree_root->content->pipe->left = tree_node;
	}
	// Si le token suivant est un PIPE_LINE, parsez une nouvelle commande et mettez-la à droite de la racine
	if (token && token->type == PIPE_LINE)
	{
		tree_node = parse_pipe(&token);
		tree_node->content->pipe->right = (*tree)->tree_root;
		(*tree)->tree_root = tree_node;
	}
	return parser(tree, token, env);
}
