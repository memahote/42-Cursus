/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:44:14 by memahote          #+#    #+#             */
/*   Updated: 2023/03/25 11:35:34 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_struct *data, int x, int y, int color)
{
	int	*dst;

	if (x > 1000 - 10 || y > 1000 - 10 || x < 10 || y < 10)
		return ;
	dst = (int *)data->addr;
	dst[y * 1000 + x] = color;
}


int	mod(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	max(int x,int y)
{
	if (x >= y)
		return (x);
	return (y);
}
void	zoom(t_coor *points, t_struct *data)
{
	points->x *= data->zoom;
	points->y *= data->zoom;
	points->x1 *= data->zoom;
	points->y1 *= data->zoom;
}

void	shift(t_coor *points, t_struct *data)
{
	points->x += data->shift_x;
	points->y += data->shift_y;
	points->x1 += data->shift_x;
	points->y1 += data->shift_y;
}


