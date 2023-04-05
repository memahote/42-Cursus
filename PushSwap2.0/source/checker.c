/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:24:09 by memahote          #+#    #+#             */
/*   Updated: 2023/03/31 17:24:09 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static	void	error_checker(char *line, t_struct *data)
{
	free(line);
	get_next_line(-1);
	ft_print_error(data);
}

static void	do_instructions(char *line, t_struct *data)
{
	if (ft_strcomp(line, "sa\n") == 0)
		sa(&data->stack_a, data->print);
	else if (ft_strcomp(line, "sb\n") == 0)
		sb(&data->stack_b, data->print);
	else if (ft_strcomp(line, "ss\n") == 0)
		ss(&data->stack_a, &data->stack_b, data->print);
	else if (ft_strcomp(line, "pa\n") == 0)
		pa(&data->stack_a, &data->stack_b, data->print);
	else if (ft_strcomp(line, "pb\n") == 0)
		pb(&data->stack_a, &data->stack_b, data->print);
	else if (ft_strcomp(line, "ra\n") == 0)
		ra(&data->stack_a, data->print);
	else if (ft_strcomp(line, "rb\n") == 0)
		rb(&data->stack_b, data->print);
	else if (ft_strcomp(line, "rr\n") == 0)
		rr(&data->stack_a, &data->stack_b, data->print);
	else if (ft_strcomp(line, "rra\n") == 0)
		rra(&data->stack_a, data->print);
	else if (ft_strcomp(line, "rrb\n") == 0)
		rrb(&data->stack_b, data->print);
	else if (ft_strcomp(line, "rrr\n") == 0)
		rrr(&data->stack_a, &data->stack_b, data->print);
	else
		error_checker(line, data);
}

void	ft_print_res(t_struct *data)
{
	if (data->stack_a)
	{
		if (!is_sorted(data->stack_a) || (is_sorted(data->stack_a) && \
			data->stack_b))
			ft_putstr_fd("KO\n", 1);
		else
			ft_putstr_fd("OK\n", 1);
	}
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_struct	*data;
	char		*line;

	line = NULL;
	data = ft_calloc(1, sizeof(t_struct));
	if (!data)
		exit(1);
	if (argc == 1)
		ft_free_and_exit(data);
	initialize_struct(data, argv, argc);
	data->print = 0;
	line = get_next_line(0);
	while (line)
	{
		if (!line)
			break ;
		do_instructions(line, data);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	ft_print_res(data);
	ft_free(data);
	return (0);
}
