/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:56:03 by memahote          #+#    #+#             */
/*   Updated: 2023/03/28 17:11:19 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_struct
{
	t_list  *stack_a;
	t_list  *stack_b;
	int     *sta;
	int     *sorted_sta;
	int     mid;
	int     median;
	int     start;
	int     end;
	int     chunk_size;
	int     number_of_chunk;
	int     len_a;
	int     len_b;
	int     lower;
	int     upper;
	int     down;
	int     index_biggest;
	int		index_start;
	int		index_end;

}             t_struct;

void        sa(t_list **stack_a);
void        sb(t_list **stack_b);
void        ss(t_list **stack_a, t_list **stack_b);
void        pa(t_list **stack_a, t_list **stack_b);
void        pb(t_list **stack_a, t_list **stack_b);
void        ra(t_list **stack_a);
void        rb(t_list **stack_b);
void        rr(t_list **stack_a, t_list **stack_b);
void        rra(t_list **stack_a);
void        rrb(t_list **stack_b);
void        rrr(t_list **stack_a, t_list **stack_b);

// t_list      *fill_st_a( char **argv, t_list *stack);
void		fill_st_a(int argc, char **argv, t_struct *data);
int         *array_of_stack(t_list *stack);
int         *sort_array(int *array, int len);
int         nb_of_chunk(int size);
// void        initialize_struct(t_struct **data_struct, char **argv);
void		initialize_struct(t_struct *data_struct, char **argv, int argc);
int         is_int(char *str);

void	sort_three(t_struct *data);
void	sort_five(t_struct *data);
int         is_sorted(t_list *stack);
int         is_empty(t_list **stack);
int         find_index_smallest(t_list **stack);
int         find_smallest(t_list **stack);
int         find_biggest(t_struct **data);

void        sort_a_to_b(t_struct *data);
void        sort_b_to_a(t_struct **data);
void		update_values(t_struct *data);
void 		check_duplicate(t_struct *data);
void    	ft_print_error(t_struct *data);
void    ft_free(t_struct *data);
#endif
