/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:00:46 by memahote          #+#    #+#             */
/*   Updated: 2023/11/28 13:00:46 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>
#include "../includes/lexer.h"
#include "../includes/minishell.h"

void print_tokens(t_list *token);

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void)envp;
	char *line;
	char	*input_line;
	t_list	*token_list;
	// t_list	*head;

	while (1)
	{
			line = readline("minishell~>");
			if (!line)
			{
				printf("exit\n");
				exit(1);
			}
			if(ft_strlen(line) > 0)
				add_history(line);
			input_line = line;
			// head = token_list;
			token_list = lexer(input_line);
			// token_list = head;
			if(!check_syntax(&token_list))
				ft_putstr_fd("Error unclose quote\n", 2);
    		print_tokens(token_list);
	}
}

void print_tokens(t_list *tokens) 
{
	while (tokens) 
	{
        printf("Type: %d, Content: %s, State: %d\n", tokens->type, tokens->content, tokens->state);
        tokens = tokens->next;
    }
}

// voir pq le 1er noeud de la liste est null