/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:24:33 by memahote          #+#    #+#             */
/*   Updated: 2023/11/29 16:24:33 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

#include <stdio.h>
#include "libft.h"

enum e_state
{
	IN_DQUOTE,
	IN_QUOTE,
	OUTSIDE,
};

enum e_token
{
	WORD = -1,
	SPACE,
	NEW_LINE = '\n',
	SQUOTE = '\'',
	DQUOTE = '\"',
	ESCAPE = '\\',
	ENV = '$',
	PIPE_LINE = '|',
	REDIR_IN = '<',
	REDIR_OUT = '>',
	HERE_DOC,
	DREDIR_OUT,
};

typedef struct s_list
{
	char 			*content;
	int				len;
	enum e_token	type;
	enum e_state	state;
	t_list			*next;

}	t_list ;

//lexer
int	tokenizer(char *line, int i, enum e_state	state, t_list *token);
int	is_special(char c);
t_list	*lexer(char *line);

//lexer_utils
int	extract_word(char *str, enum e_state state, t_list *token);
int	is_special(char c);
int	ft_isspace(char c);

//list_minishell
t_list	*init_list(t_list *list);
t_list	*new_cont(char *content, int len, enum e_token type, enum e_state state);
void	free_list(t_list *list);





#endif