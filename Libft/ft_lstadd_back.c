/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:40:32 by memahote          #+#    #+#             */
/*   Updated: 2022/11/17 18:58:12 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastlist;

	lastlist = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lastlist = ft_lstlast(*lst);
	lastlist -> next = new;
}
