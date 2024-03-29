/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:14:20 by memahote          #+#    #+#             */
/*   Updated: 2022/11/15 19:32:45 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57))
	{
		return (1);
	}
	else if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (2);
	}
	return (0);
}
