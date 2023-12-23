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
	struct s_list_redir *next;
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
}	t_cmd;

typedef struct s_ast_node
{
	enum e_ast_type type;
	t_cmd		*cmd;
	struct s_ast_node	*left;
	struct s_ast_node	*right;
}	t_ast_node;

//parser
int	parser(t_list **token);

//parse_token
char	*parse_quotes(char *arg, t_list **token, enum e_state state);

//utils
int	count_args(t_list *token);
char	*get_env(char *env);

//redir list
t_list_redir	*new_redir_cont(char *file, enum e_token type);
void	free_redir_list(t_list_redir **list);
void	add_back_redir(t_list_redir **lst, t_list_redir *new);

char	*get_env(char *env);
#endif