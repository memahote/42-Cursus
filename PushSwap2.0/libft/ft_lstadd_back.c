/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:40:32 by memahote          #+#    #+#             */
/*   Updated: 2023/03/31 13:18:24 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd_back(t_list *lst, t_list *new)
{
	t_list	*lastlist;

	lastlist = lst;
	if (!lst)
	{
		lst = new;
		return (NULL);
	}
	lastlist = ft_lstlast(lst);
	lastlist -> next = new;
	lst = lastlist;
	return (lst);
}
