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

int	count_args(t_list *token) // Size for malloc command + arg + redir
{
	t_list *tmp;
	int		i;

	i = 0;
	tmp = token;
	while (tmp && tmp->type != PIPE_LINE)
	{
		if (tmp->type == WORD || tmp->type == ENV)
			i++;
		else if (tmp->type == SQUOTE)
		{
			tmp = tmp->next;
			while(tmp->type != SQUOTE)
				tmp = tmp->next;
			i++;
		}
		else if (tmp->type == DQUOTE)
		{
			tmp = tmp->next;
			while(tmp->type != DQUOTE)
				tmp = tmp->next;
			i++;
		}
		tmp = tmp->next;
	}
	return (i);
}

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

int fill_cmd(t_list **token, char **args, t_list_redir redir_l)
{
	t_list *tmp;
	int 	i;

	tmp = *token;
	i = 0;
	while (tmp && tmp->type != PIPE_LINE)
	{
		if(tmp->type == WORD)
			args[i++] = ft_strdup(tmp->content);
		else if (tmp->type == SQUOTE || tmp->type == DQUOTE)
			//args[i]=
		else if (tmp->type == ENV)
			//args[i]= aller cherche valeur de env
		else if (is_redir(tmp->type) != NULL)
			//t_list_redir = ajouter a la liste la redir avec le file
			// donc on avance ; tmp = tmp->next;
		tmp = tmp->next;
	}
	args[i]=NULL;
	return (1);
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
	fill_redirl(&redir_l,  token);
	print_redir(redir_l);
	return(0);
}