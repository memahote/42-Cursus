/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:16:16 by memahote          #+#    #+#             */
/*   Updated: 2023/03/02 20:16:16 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	move_key(int key, t_struct *data)
// {
// 	 if (key == 122)
//         data->shift_y -=10;
//     if (key == 121)
//         data->shift_y +=10;
//     if (key == 119)
//         data->shift_x -=10; 
//     if (key == 120)
//          data->shift_x +=10;
// 	mlx_destroy_image(data->mlx_ptr, data->image);
// 	data->image = mlx_new_image(data->mlx_ptr, 1000, 1000);
// 	data->addr = mlx_get_data_addr(data->image, &data->bits_per_pixel, 
// 	&data->line_length, &data->endian);
// 	draw(data);
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, 0, 0);
// 	return (0);
// }


// int	zoom_key(int key, t_struct *data)
// {
// 	if (key == 65453)
//         data->zoom -= 5;
//     if (key == 65451)
//         data->zoom += 5;   
// 	mlx_destroy_image(data->mlx_ptr, data->image);
// 	data->image = mlx_new_image(data->mlx_ptr, 1000, 1000);
// 	data->addr = mlx_get_data_addr(data->image, &data->bits_per_pixel, 
// 	&data->line_length, &data->endian);
// 	draw(data);
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, 0, 0);
// 	return (0);
// }

// int	deal_key(int key, t_struct *data)
// {
// 	if (key == 121 || key == 122 || key == 123 
// 	|| key == 124)
// 		move_key(key, data);
// 	// else if (key == 65453 || key == 65451)
// 	// 	zoom_key(key, data);
// 	else if (key == 65307)
// 		close_window(data);
// 	return (0);
// }