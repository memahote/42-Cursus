/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:05:20 by memahote          #+#    #+#             */
/*   Updated: 2023/02/21 16:05:20 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


// void	menu(t_struct *t_data)
// {
// 	t_data->background = "./background.xpm";
// 	t_data->image = mlx_xpm_file_to_image(t_data->mlx_ptr, t_data->background,
// 		&t_data->height, &t_data->width);
// 	mlx_put_image_to_window(t_data->mlx_ptr, t_data->win_ptr, t_data->image, 0, 0);
// }



int main(int argc, char **argv)
{
    t_struct    data;

    (void)argc;
    ft_bzero(&data, sizeof (t_struct));
    read_file(argv[1], &data);
    init_data(&data);
    data.image = mlx_new_image(data.mlx_ptr, 1000, 1000);
    draw(&data);
    mlx_hook(data.win_ptr, 17, (1l << 0), close_window, &data);
    mlx_hook(data.win_ptr, 2, (1l << 0), deal_key, &data);
    mlx_loop(data.mlx_ptr);
    free_all(&data);
}
