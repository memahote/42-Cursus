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


// Ne pas oublier de DUP l'env pour que le minishell est son propre env !
void print_tokens(t_list *token);
void print_env(t_list_env *env) ;

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	char 		*line;
	char		*input_line;
	t_list		*token_list;
	t_tree		*tree;
	t_list_env	*env;
	int i = 0;

	tree = NULL;
	tree = init_tree(tree);
	env = NULL;
	while (i < 1)
	{
			line = readline("minishell~>"); 
			if (!line || ft_strcomp(line, "exit") == 0)
			{
				printf("exit\n");
				exit(1);
			}
			if(ft_strlen(line) > 0)
				add_history(line);
			create_env(envp, &env);
			input_line = line;
			if(!check_quote_input(input_line))
				ft_putstr_fd("Error unclose quote\n", 2);
			else
			{
				token_list = lexer(input_line);
				check_syntax(&token_list);
				print_tokens(token_list);
				parser(&tree, token_list, envp);
				print_tree(tree->tree_root);
			}
			ft_export(&env, tree->tree_root->content->cmd);
			print_env(env);
			free (line);
			free_list(&token_list);
			free_tree(tree->tree_root);
			free(tree);
			i++;
	}
	return (0);
}

void print_env(t_list_env *env) 
{
	while (env) 
	{
        printf("Val: %s\n", env->var);
        env = env->next;
    }
}

void print_tokens(t_list *tokens) 
{
	while (tokens) 
	{
        printf("Type1: %d, Content: %s, State: %d\n", tokens->type, tokens->content, tokens->state);
        tokens = tokens->next;
    }
}

// Voir comment gerer les heredoc dans le parsing ou exec ???
