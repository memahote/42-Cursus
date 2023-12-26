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
// #include "../includes/parser.h"

void print_tokens(t_list *token);

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	char *line;
	char	*input_line;
	t_list	*token_list;
	t_tree	*tree;
	int i = 0;

	tree = NULL;
	tree = init_tree(tree);
	while (i < 2)
	{
			line = readline("minishell~>"); 
			if (!line || ft_strcomp(line, "exit") == 0)
			{
				printf("exit\n");
				exit(1);
			}
			if(ft_strlen(line) > 0)
				add_history(line);
			input_line = line;
			if(!check_quote_input(input_line))
				ft_putstr_fd("Error unclose quote\n", 2);
			else
			{
				token_list = lexer(input_line);
				check_syntax(&token_list);
				print_tokens(token_list);
				parser(&tree, token_list, envp);
			}
			free (line);
			free_list(&token_list);
			// free_tree(tree->tree_root);
			// free(tree);
			i++;
	}
	return (0);
}

void print_tokens(t_list *tokens) 
{
	while (tokens) 
	{
        printf("Type1: %d, Content: %s, State: %d\n", tokens->type, tokens->content, tokens->state);
        tokens = tokens->next;
    }
}


// voir pq le 1er noeud de la liste est null -> du a init
// enlever les espace dans la liste chainee -> Fait 
// check si word avant et apres un pipe -> fait
// check si word apres les redir ->fait