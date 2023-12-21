/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 07:16:27 by memahote          #+#    #+#             */
/*   Updated: 2023/12/21 07:16:27 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*parse_quotes(char *arg, t_list *token, enum e_token type) //Recupere tout entre quote en 1 seul arg
{
	t_list	*tmp;

	tmp = token;
	while (tmp->type != type && tmp)
	{
		if (!arg)
			arg = ft_strdup("");
		if (tmp->type == ENV && tmp->state == IN_DQUOTE)
		{
			if(get_env(tmp->content) != NULL)
				arg = ft_strjoin(arg, get_env(tmp->content));
		}
		else
			arg = ft_strjoin(arg, tmp->content);
		tmp = tmp->next;
	}
	return (arg);
}