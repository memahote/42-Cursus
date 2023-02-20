/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:52:22 by memahote          #+#    #+#             */
/*   Updated: 2022/11/22 15:00:33 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_u(unsigned int nb)
{
	int		r;

	r = 0;
	if (nb >= 10)
	{
		r += ft_put_u(nb / 10);
		r += ft_put_u(nb % 10);
	}
	else
		r += ft_put_c(nb + '0');
	return (r);
}
