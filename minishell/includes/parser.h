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

typedef struct s_list_redir
{
	char *file;
	enum e_token type;
	s_list_redir *next;
}	t_list_redir;

typedef struct s_tree
{
	char *comand;
	char **args;

}	t_tree;

#endif