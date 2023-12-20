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



char	*parse_quotes(t_list *token, enum e_token type) //Recupere tout entre quote en 1 seul arg
{
	t_list	*tmp;
	char 	*arg;

	tmp = token;
	arg = ft_strdup(tmp->content);
	tmp = tmp->next;
	while (tmp->type != type)
	{
		if (tmp->type == ENV)
		{
			if(get_env(tmp->content) != NULL)
				arg = ft_strjoin(arg, get_env(tmp->content));
		}
		else
			arg = ft_strjoin(arg, tmp->content);
		tmp = tmp->next;
	}
	arg = ft_strjoin(arg, tmp->content); // join la derniere quote 
	tmp = tmp->next;
	return (arg);
}


char	*get_env(char *env)
{
	char	*name;

	name = ft_strdup(env + 1);
	if(ft_strcomp(name, "?") == 0)
		return("0"); //Faire un itoa de l'exit status quand je l'aurai
	name = getenv(env);
	return (name);
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
			args[i++] = tmp->content;
			// tmp = tmp->next;
			// while (tmp->state != OUTSIDE && tmp)
			// {
			// 	args[i] = ft_strjoin(args[i], tmp->content);
			// 	if(tmp->next == NULL)
			// 		break;
			// 	else
			// 		tmp = tmp->next;
			// }
			// i++;
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

