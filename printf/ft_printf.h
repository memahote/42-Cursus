/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:44:30 by memahote          #+#    #+#             */
/*   Updated: 2022/12/21 15:15:27 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int			ft_printf(const char *format, ...);
int			ft_put_c(char c);
int			ft_put_s(char *str);
int			ft_putd_i(int nb);
int			ft_put_p(void *p);
int			ft_put_u(unsigned int nb);
int			ft_put_x(unsigned int nb, const char format);
int			ft_base(unsigned long nb, char *base);

#endif
