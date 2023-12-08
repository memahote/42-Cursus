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

t_list	*check_close_quote(t_list **lst, enum e_token type)
{
	t_list *current;

	current = *lst;
	current = current->next;
	while(current)
	{
		if(current->type == type)
		{
			return(current);
		}
		current = current->next;
	}
	return (current);
}


void	del_space(t_list **token)
{
	t_list *current;

	current = *token;
	while(current)
	{
		if(ft_isspace(current->content) && current->state == OUTSIDE)
		{
			
		}
		current = current->next;
	}
}

int	check_syntax(t_list **token)
{
	t_list *tmp;

	tmp = *token;
	while(tmp)
	{
		// printf("type : %s\n", tmp->content);
		if (tmp->type == DQUOTE || tmp->type == SQUOTE)
		{
			if(check_close_quote(&tmp, DQUOTE) == NULL)
				return (0);
			else 
				tmp = check_close_quote(&tmp, DQUOTE);
		}
		tmp = tmp->next;
		// else if (tmp->type == PIPE_LINE)
		// 	check_pipe_syntax(tmp, PIPE_LINE);
		// //si tmp->type == dquote
		// //si tmp->type == squote
		// 	//check unclose quote

		// //si tmp->type == pipe
		// 	//check if type bef4 and after is word

		// //si tmp->type == redir
		// 	//check if type bef4 or after is a word
	}
	return(1);
}


// Pour check si les quote sont fermer , je part d'une quote et 
// je parcour la liste jusqu'a retrouver une autre quote de meme type
// si je trouve je renvoie la liste a index ou je la trouve sinon
// je return NULL et donc error;

// Pour check si les pipes sont valide , je regarde si ce qui suit
// est un mot sinon error.

// Pour les redir je regarde si ce qui precede ou succede est un 
// mot sinon error;

// Parcourir la liste et voir si on croise un & en dehors de quote
// return error


// Quand analyse de syntaxe fini, bien la tester et 
// la normer avant de passer au parser


// Voir pq le type dans le check_syntaxe est null