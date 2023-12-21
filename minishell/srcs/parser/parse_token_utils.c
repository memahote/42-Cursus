/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 07:17:26 by memahote          #+#    #+#             */
/*   Updated: 2023/12/21 07:17:26 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*get_env(char *env)
{
	char	*name;

	name = ft_strdup(env + 1);
	if(ft_strcomp(name, "?") == 0)
		return("0"); //Faire un itoa de l'exit status quand je l'aurai
	name = getenv(env);
	return (name);
}

// void	one_arg_quotes(t_list *token)
// {
// 	if (token->state)
// 		;
// }

int	count_args(t_list *token) // Size for malloc command + arg + redir
{
	t_list *tmp;
	int		i;

	i = 0;
	tmp = token;
	while (tmp && tmp->type != PIPE_LINE)
	{
		if (tmp->state == IN_SQUOTE || tmp->state == IN_DQUOTE)
		{
			i++;
			while (tmp && tmp->state != OUTSIDE)
			{
				tmp = tmp->next;
			}
		}
		else if (tmp->type == WORD || tmp->type == ENV)
		{
			i++;
		}
		// else if (tmp->type == SQUOTE)
		// {
		// 	tmp = tmp->next;
		// 	while(tmp->type != SQUOTE)
		// 		tmp = tmp->next;
		// 	i++;
		// }
		// else if (tmp->type == DQUOTE)
		// {
		// 	tmp = tmp->next;
		// 	while(tmp->type != DQUOTE)
		// 		tmp = tmp->next;
		// 	i++;
		// }
		if(tmp)
			tmp = tmp->next;
	}
	printf("i :%d\n", i);
	return (i);
}