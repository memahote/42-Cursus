/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:15:09 by memahote          #+#    #+#             */
/*   Updated: 2023/11/29 17:15:09 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include "lexer.h"
// # include "parser.h"

// Forward declaration
struct s_tree_node;

enum e_tree_type
{
    CMD,
    PIPE,
};

typedef struct s_list_redir
{
    char *file;
    enum e_token type;
    struct s_list_redir *next;
}   t_list_redir;

typedef struct s_cmd
{
    char    **args;
    char    **env;
    t_list_redir *redir;
    int fd_in;
    int fd_out;
}   t_cmd;

typedef struct s_pipe
{
    struct s_tree_node *left;
    struct s_tree_node *right;
}   t_pipe;

typedef union u_type
{
    t_pipe  *pipe;
    t_cmd   *cmd;
}   t_type;

typedef struct s_tree_node
{
    enum e_tree_type type;
    t_type  *content;
}   t_tree_node;

typedef struct s_tree
{
    t_tree_node *tree_root;
}   t_tree;

//			######------ PARSER ------######

int	parser(t_tree **tree, t_list *token, char **env);
char	*parse_quotes(char *args, t_list **token);
int	count_args(t_list *token);
char	*get_env(char *env);
t_tree_node		*new_cmd(char **args, t_list_redir *redir, char **env);
t_tree_node	*parse_pipe(t_list **token);
t_list_redir	*new_redir_cont(char *file, enum e_token type);
void	add_back_redir(t_list_redir **lst, t_list_redir *new);
char	*get_env(char *env);
t_tree	*init_tree(t_tree *tree);
int	check_quote_input(char *line);
void	free_tree(t_tree_node *node);
void	free_cmd(t_cmd *cmd);
void	fill_redirl(t_list_redir **redir_l, t_list **token);

//			######### PRINT ##########
void print_arg(char	**args);
void	print_tree_node(t_tree_node *cmd);
void	print_tree(t_tree_node *tree);
void print_redir(t_list_redir *redirl);

#endif