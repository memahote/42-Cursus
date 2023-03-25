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

void	key_helper(int key, t_struct *t_data)
{
	if (key == 97)
	{
		if (t_data->iso == 1)
			t_data->iso -= 1;
		else if (t_data->iso == 0)
			t_data->iso += 1;
	}
	if (key == 113)
		t_data->angle_x += 0.2;
	if (key == 119)
		t_data->angle_y += 0.2;
	if (key == 107)
		t_data->depth += 1;
	if (key == 106)
		t_data->depth -= 1;
    if (key == 65453)
    {
        if (t_data->zoom < 10)
            t_data->zoom = 10;
        t_data->zoom -= 5;
    }
    if (key == 65451)
        t_data->zoom += 5;
}


// void	rotate(int key, t_struct *data)
// {
// 	if (key == 119)
// 		data->angle_y -= 0.2;
// 	if (key == 115)
// 		data->angle_y += 0.2;
// 	if (key == 116)
// 		data->angle_x -= 0.2;
// 	if (key == 117)
// 		data->angle_x += 0.2;
// 	mlx_destroy_image(data->mlx_ptr, data->image);
// 	data->image = mlx_new_image(data->mlx_ptr, 1000, 1000);
// 	data->addr = mlx_get_data_addr(data->image, &data->bits_per_pixel, 
// 	&data->line_length, &data->endian);
//     draw_menu(data);
// 	draw(data);
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, 0, 0);
// }

// void	projection(int key, t_struct *data, t_coor *points)
// {
//     if (key == 97)
//         data->coef_z += 0.1;
//     if (key == 122)
//      data->coef_z -= 0.1;
//     if (key == 32)
//     {
//         points->x = points->y;
//         points->y = points->x1;
//     }
// 	mlx_destroy_image(data->mlx_ptr, data->image);
// 	data->image = mlx_new_image(data->mlx_ptr, 1000, 1000);
// 	data->addr = mlx_get_data_addr(data->image, &data->bits_per_pixel, 
// 	&data->line_length, &data->endian);
//     draw_menu(data);
// 	draw(data);
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, 0, 0);
// }

// void    zoom_key(int key, t_struct *data)
// {
//     if (key == 65453)
//     {
//         if (data->zoom < 10)
//             data->zoom = 10;
//         data->zoom -= 5;
//     }
//     if (key == 65451)
//         data->zoom += 5;
//     mlx_destroy_image(data->mlx_ptr, data->image);
// 	data->image = mlx_new_image(data->mlx_ptr, 1000, 1000);
// 	data->addr = mlx_get_data_addr(data->image, &data->bits_per_pixel, 
// 	&data->line_length, &data->endian);
//     draw_menu(data);
// 	draw(data);
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, 0, 0);
// }

// void    move_key(int key, t_struct *data)
// {
//     if (key == 65362)
//         data->shift_y -=10;
//     if (key == 65364)
//         data->shift_y +=10;
//     if (key == 65361)
//         data->shift_x -=10; 
//     if (key == 65363)
//          data->shift_x +=10;
//     mlx_destroy_image(data->mlx_ptr, data->image);
// 	data->image = mlx_new_image(data->mlx_ptr, 1000, 1000);
// 	data->addr = mlx_get_data_addr(data->image, &data->bits_per_pixel, 
// 	&data->line_length, &data->endian);
//     draw_menu(data);
// 	draw(data);
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, 0, 0);
// }


