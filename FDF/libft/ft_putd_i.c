/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putd_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:46:44 by memahote          #+#    #+#             */
/*   Updated: 2022/12/21 15:30:36 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putd_i(int nb)
{
	int		r;

	r = 0;
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write (1, "-", 1);
		r += 1;
		nb = nb * -1;
	}
	if (nb > 9)
	{
		r += ft_putd_i(nb / 10);
		r += ft_putd_i(nb % 10);
	}
	else
		r += ft_put_c(nb + '0');
	return (r);
}
