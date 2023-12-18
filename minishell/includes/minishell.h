/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:15:09 by memahote          #+#    #+#             */
/*   Updated: 2023/11/29 17:15:09 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include "lexer.h"
# include "parser.h"

int	check_quote_input(char *line);

// typedef struct s_cmd 
// {
// 	char	*cmd;
// 	char	**args;
	

// }	t_cmd;

#endif