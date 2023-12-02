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

	while (1)
	{
			line = readline("minishell~> ");
			if (!line)
			{
				printf("exit\n");
				exit(1);
			}
			if(ft_strlen(line) > 0)
				add_history(line);
			input_line = line;
			token_list = lexer(input_line);
    		print_tokens(token_list);
	}
}

#include <stdio.h>

// Assurez-vous d'avoir les définitions appropriées pour les types utilisés dans votre code (t_list, new_cont, enum e_state, etc.)

void print_tokens(t_list *tokens) 
{
	int i = 0;
    while (tokens) 
	{
		printf("i = %d \n", i);
        printf("Type: %d, Content: %s\n", tokens->type, tokens->content);
        tokens = tokens->next;
		i++;
    }
}

