/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:56:03 by memahote          #+#    #+#             */
/*   Updated: 2023/04/09 14:41:48 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_struct
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*sta;
	int		*sorted_sta;
	int		mid;
	int		median;
	int		start;
	int		end;
	int		chunk_size;
	int		number_of_chunk;
	int		len_a;
	int		print;
	int		lower;
	int		upper;
	int		down;
	int		index_biggest;
	int		index_start;
	int		index_end;
}		t_struct;

/********** Instrucions  **********/
void		sa(t_list **stack_a, int printable);
void		sb(t_list **stack_b, int printable);
void		ss(t_list **stack_a, t_list **stack_b, int printable);
void		pa(t_list **stack_a, t_list **stack_b, int printable);
void		pb(t_list **stack_a, t_list **stack_b, int printable);
void		ra(t_list **stack_a, int printable);
void		rb(t_list **stack_b, int printable);
void		rr(t_list **stack_a, t_list **stack_b, int printable);
void		rra(t_list **stack_a, int printable);
void		rrb(t_list **stack_b, int printable);
void		rrr(t_list **stack_a, t_list **stack_b, int printable);	

/**********	Parsing/Filling stack **********/
void		fill_st_a(int argc, char **argv, t_struct *data);
int			*array_of_stack(t_list *stack);
int			*sort_array(int *array, int len);
int			is_int(char *str);
void		initialize_struct(t_struct *data_struct, char **argv, int argc);
int			nb_of_chunk(int size);
void		check_duplicate(t_struct *data);

/**********	Sorting **********/
void		sort_three(t_struct *data);
void		sort_small(t_struct *data);
int			is_sorted(t_list *stack);
int			is_empty(t_list **stack);
int			find_index_smallest(t_list **stack);
int			find_smallest(t_list **stack);
int			find_biggest(t_struct **data);
void		sort_a_to_b(t_struct *data);
void		sort_b_to_a(t_struct **data);
void		update_values(t_struct *data);

/**********	Free and exit **********/
void		ft_print_error(t_struct *data);
void		ft_free(t_struct *data);
void		ft_free_and_exit(t_struct *data);
void		ft_free_tab(char **tab, int i);
void		ft_free_tab_and_exit(t_struct *data, char **tab, int j);
#endif
