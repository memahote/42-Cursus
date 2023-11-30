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
	ft_lstadd_back(token, new_cont(wd, i, WORD, state));
	return (i);
}

int	squote(char *str, enum e_state state, t_list *token)
{
	
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
	if (ft_strcomp(c, '|') == 0)
		return (1);
	if (ft_strcomp(c, '>') == 0)
		return (1);
	if (ft_strcomp(c, '<') == 0)
		return (1);
	if (ft_strcomp(c, '>>') == 0)
		return (1);
	if (ft_strcomp(c, '<<') == 0)
		return (1);
	if (ft_strcomp(c, '$') == 0)
		return (1);
	if (ft_strcomp(c, ' ') == 0)
		return (1);
	if (ft_strcomp(c, '\0') == 0)
		return (1);
	if (is_space(c))
		return (1);
	return (0);
}