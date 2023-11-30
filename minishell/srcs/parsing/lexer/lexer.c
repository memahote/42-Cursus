/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:30:27 by memahote          #+#    #+#             */
/*   Updated: 2023/11/29 16:30:27 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	tokenizer(char *line, int i, enum e_state	state, t_list *token)
{
	if(!is_special(line[i]))
		i += extract_word(&line[i], state, token);
	else if ()
	
}



t_list	*lexer(char *line)
{
	int 			i;
	t_list			*token;
	enum e_state	state;

	i = 0;
	token = NULL;
	state = OUTSIDE;
	init_list(token);
	while(line[i])
	{
		i += tokenizer(line, i, state, token);
	}
}

