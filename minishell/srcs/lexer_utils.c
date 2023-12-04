/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:43:15 by memahote          #+#    #+#             */
/*   Updated: 2023/11/29 21:43:15 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	extract_word(char *str, enum e_state state, t_list *token)
{
	int 	i;
	char	*wd;

	i = 0;
	while(!is_special(str[i]))
		i++;
	wd = ft_substr(str, 0, i);
	ft_lstadd_back(&token, new_cont(wd, i, WORD, state));
	return (i);
}

void	check_quote(char *str, t_list *token, enum e_state *state, char flag)
{
	enum e_state quote;
	enum e_token type;

	if(flag == 'S')
	{
		quote = IN_SQUOTE;
	 	type = SQUOTE;
	}
	else if (flag == 'D')
	{
		quote = IN_DQUOTE; 
	 	type = DQUOTE;
	}
	if	(*state == OUTSIDE)
	{
		ft_lstadd_back(&token, new_cont(str, 1, type, *state)); //la quote est compter a l'exterieur
		*state = quote;
	}
	else if (*state == quote) // quand on rerelsntre dans cette fonction en tant que quote fermante simple ou double
	{
		*state = OUTSIDE;
		ft_lstadd_back(&token, new_cont(str, 1, type, *state));
	}
	else // si je suis une quote differente 
		ft_lstadd_back(&token, new_cont(str, 1, type, *state));
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\v'
		|| c == '\r' || c == '\f' || c == '\n')
		return (1);
	return (0);
}

int	is_special(char c)
{
	if (c == '|')
		return (1);
	if (c == '>')
		return (1);
	if (c == '\"')
		return (1);
	if (c == '\'')
		return (1);
	if (c == '<')
		return (1);
	if (c == '$')
		return (1);
	if (c == ' ')
		return (1);
	if (c == '\0')
		return (1);
	if (c == '\n')
		return (1);
	if (ft_isspace(c))
		return (1);
	return (0);
}

char	*ft_strndup(char *s1, int n)
{
	char	*copy;
	size_t	s1_len;
	int		i;

	i = 0;
	s1_len = ft_strlen(s1);
	copy = malloc(sizeof(char) * (s1_len + 1));
	if (!copy)
		return (NULL);
	while (s1[i] && i < n)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}