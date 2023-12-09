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
#include "../libft/libft.h"

enum e_state
{
	IN_DQUOTE,
	IN_SQUOTE,
	OUTSIDE,
};

enum e_token
{
	WORD = -1,
	SPACE_T,
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
	struct s_list	*next;

}	t_list;

//lexer
int	tokenizer(char *line, int i, enum e_state	*state, t_list *token);
int	is_special(char c);
t_list	*lexer(char *line);

//lexer_utils
int	extract_word(char *str, enum e_state state, t_list **token);
int	is_special(char c);
int	ft_isspace(char c);
void	check_quote(char *str, t_list **token, enum e_state *state, char flag);
int	redir(char *line, t_list *token, enum e_state *state);

//list_minishell
t_list	*init_list(t_list *list);
t_list	*new_cont(char *content, int len, enum e_token type, enum e_state state);
void	free_list(t_list *list);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);

char	*ft_strndup(char *s1, int n);

int	check_syntax(t_list **token);

#endif