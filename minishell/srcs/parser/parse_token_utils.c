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

#include "minishell.h"

char	*get_env(char *env)
{
	char	*name;

	name = ft_strdup(env + 1);
	if(ft_strcomp(name, "?") == 0)
		return("0"); //Faire un itoa de l'exit status quand je l'aurai
	free(name);
	name = getenv(env + 1);
	return (name);
}

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
		if(tmp)
			tmp = tmp->next;
	}
	printf("i :%d\n", i);
	return (i);
}

// t_tree_node	*parse_pipe(t_list **token)
// {
// 	t_tree_node	*branch;

// 	branch = ft_calloc(sizeof(t_tree_node), 1);
// 	if (!branch)
// 		return (NULL);
// 	branch->type = PIPE;
// 	branch->content = malloc(sizeof(t_type));
// 	branch->content->pipe = malloc(sizeof(t_pipe));
// 	branch->content->pipe->left = NULL;
// 	branch->content->pipe->right = NULL;
// 	if (!branch->content->pipe->right || !branch->content->pipe->left)
// 		return (NULL);
// 	*token = (*token)->next;
// 	ft_putstr_fd("FILS DE PIPe\n", 2);
// 	return (branch);
// }

t_tree_node *parse_pipe(t_list **token)
{
    t_tree_node *branch;

    // Allocate memory for the branch
    branch = ft_calloc(sizeof(t_tree_node), 1);
    if (!branch)
        return (NULL);

    // Initialize the branch
    branch->type = PIPE;
    branch->content = NULL;

    // Allocate memory for branch->content
    branch->content = malloc(sizeof(t_type));
    if (!branch->content)
    {
        free(branch);  // Free 'branch' if allocation fails
        return (NULL);
    }

    // Initialize branch->content
    branch->content->pipe = NULL;

    // Allocate memory for branch->content->pipe
    branch->content->pipe = malloc(sizeof(t_pipe));
    if (!branch->content->pipe)
    {
        free(branch->content);  // Free 'branch->content' if allocation fails
        free(branch);  // Free 'branch' if allocation fails
        return (NULL);
    }

    // Initialize branch->content->pipe
    branch->content->pipe->left = NULL;
    branch->content->pipe->right = NULL;

    // Move to the next token
    *token = (*token)->next;
    ft_putstr_fd("FILS DE PIPe\n", 2);
    return (branch);
}


