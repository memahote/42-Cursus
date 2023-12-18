/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:37:19 by memahote          #+#    #+#             */
/*   Updated: 2023/12/15 13:37:19 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"
# include "lexer.h"

enum e_ast_type
{
	CMD,
	PIPE,
};

typedef struct s_list_redir
{
	char *file;
	enum e_token type;
	s_list_redir *next;
}	t_list_redir;

typedef struct s_fds
{
	int	fd_in;
	int	fd_out;
}	t_fds;


typedef struct s_cmd
{
	char	**args;
	char	**env;
	t_list_redir *redir;
	t_fds	fds;
}	t_cmd;

typedef struct s_ast_node
{
	enum e_ast_type type;
	t_cmd		*cmd;
	s_ast_node	*left;
	s_ast_node	*right;
}	t_ast_node;

#endif