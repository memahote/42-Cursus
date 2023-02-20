/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:13:41 by memahote          #+#    #+#             */
/*   Updated: 2022/11/17 18:59:10 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curlist;
	t_list	*nextlist;

	if (!lst)
		return ;
	curlist = *lst;
	while (curlist)
	{
		nextlist = curlist -> next;
		ft_lstdelone(curlist, del);
		curlist = nextlist;
	}
	*lst = NULL;
}
