/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:19:57 by memahote          #+#    #+#             */
/*   Updated: 2023/12/03 14:19:57 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	check_syntax(t_list *token, enum e_token type)
{
	t_list *tmp;

	tmp = token;
	while(tmp)
	{
		//si tmp->type == dquote
		//si tmp->type == squote
			//check unclose quote

		//si tmp->type == pipe
			//check if type bef4 and after is word

		//si tmp->type == redir
			//check if type bef4 or after is a word
	}
}