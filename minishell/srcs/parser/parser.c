/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:59:19 by memahote          #+#    #+#             */
/*   Updated: 2023/12/17 15:59:19 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"

void	fill_redirl(t_list_redir **redir_l, t_list **token)
{
	t_list	*tmp;

	tmp = *token;
	while(tmp->type != PIPE_LINE && tmp != NULL)
	{
		if(tmp->type == REDIR_IN || tmp->type == REDIR_OUT || \
		tmp->type == HERE_DOC || tmp->type == DREDIR_OUT)
		{
			add_back_redir(redir_l, new_redir_cont(tmp->next->content, \
			tmp->type));
		}
		tmp = tmp->next;
	}
}

void print_redir(t_list_redir *redirl) 
{
	while (redirl) 
	{
        printf("Type redir: %d, file: %s\n", redirl->type, redirl->file);
        redirl = redirl->next;
    }
}


void fill_cmd(t_list **token, char **args, t_list_redir *redir_l)
{
	t_list *tmp;
	int 	i;
	(void)redir_l;

	tmp = *token;
	i = 0;
	while (tmp && tmp->type != PIPE_LINE)
	{
		if(tmp->type == WORD && tmp->state == OUTSIDE)
		{
			args[i++] = tmp->content;
		}
		else if (tmp->state == IN_DQUOTE || tmp->state == IN_SQUOTE)
		{
			printf("je rentre");
			args[i] = parse_quotes(args[i], tmp, tmp->type);
			printf("s :%s\n", args[i]);
			if (args[i])
				i++;
		}
		tmp = tmp->next;
		//faire une fonction qui join tous les state de meme state
		// else if (tmp->type == SQUOTE || tmp->type == DQUOTE)
		// 	args[i++]= parse_quotes(*token, tmp->type);
		// else if (tmp->type == ENV)
		// 	args[i++] = get_env(tmp->content);
		// else if (is_redir(tmp->type) != NULL)
			//t_list_redir = ajouter a la liste la redir avec le file
			// donc on avance ; tmp = tmp->next;
	}
	args[i]=NULL;
}
//gerer pour les espace dans les quotes


void print_arg(char	**args) 
{
	int i = 0;
	while (args[i]) 
	{
        printf("arg: %s\n", args[i]);
		i++;
    }
}

int	parser(t_list **token)
{
	char			**args;
	int				nb_args;
	t_list_redir	*redir_l;


	redir_l = NULL;
	nb_args = count_args(*token);
	args = malloc(sizeof(char *) * (nb_args + 1));
	if(!args)
		return (0);
	fill_cmd(token, args, redir_l);
	print_arg(args);
	// fill_redirl(&redir_l,  token);
	// print_redir(redir_l);
	return(0);
}

