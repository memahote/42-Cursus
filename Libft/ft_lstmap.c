/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:54:44 by memahote          #+#    #+#             */
/*   Updated: 2022/11/17 19:01:28 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*t;

	if (!lst || !f)
		return (0);
	newlst = 0;
	while (lst)
	{
		t = ft_lstnew(f(lst -> content));
		if (!t)
		{
			ft_lstclear(&newlst, del);
			return (0);
		}
		ft_lstadd_back(&newlst, t);
		t = t -> next;
		lst = lst -> next;
	}
	return (newlst);
}
