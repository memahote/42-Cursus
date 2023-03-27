/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:25:00 by memahote          #+#    #+#             */
/*   Updated: 2023/03/27 09:55:15 by memahote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_data(t_struct *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (ft_free_tab(data, data->height - 1));
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "FDF");
	if (!data->win_ptr)
		return (ft_free_tab(data, data->height - 1));
	data->image = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	if (!data->image)
		return (mlx_destroy_window(data->mlx_ptr, data->win_ptr), \
				ft_free_tab(data, data->height - 1));
	data->addr = mlx_get_data_addr(data->image, &data->bits_per_pixel, \
			&data->line_length, &data->endian);
	data->angle_x = 0.8;
	data->angle_y = 0.8;
	data->zoom = 20 ;
	data->shift_x = 325;
	data->shift_y = 325;
	data->depth = 1;
	data->iso = 1;
	data->bits_per_pixel /= 8;
}
