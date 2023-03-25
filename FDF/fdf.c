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

void	draw_menu(t_struct *data)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = data->mlx_ptr;
	win = data->win_ptr;
	mlx_string_put(mlx, win, 850, y += 20, WHITE, "********************");
	mlx_string_put(mlx, win, 850, y += 20, WHITE, "* Fil de Fer (FDF) *");
	mlx_string_put(mlx, win, 850, y += 20, WHITE, "********************");
	mlx_string_put(mlx, win, 850, y += 20, WHITE, "*     Zoom: +/-    *");
	mlx_string_put(mlx, win, 850, y += 20, WHITE, "*    Move: arrows  *");
    mlx_string_put(mlx, win, 850, y += 20, WHITE, "********************");
    // mlx_destroy_image(data->mlx_ptr, data->image);
	// data->image = mlx_new_image(data->mlx_ptr, 1000, 1000);
	// data->addr = mlx_get_data_addr(data->image, &data->bits_per_pixel, 
	// &data->line_length, &data->endian);
	// draw(data);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, 0, 0);
}

int	deal_key(int key, t_struct *t_data)
{
	mlx_clear_window(t_data->mlx_ptr, t_data->win_ptr);
	if (key == 65364)
		t_data->shift_y += 20;
	if (key == 65362 )
		t_data->shift_y -= 20;
	if (key == 65361)
		t_data->shift_x -= 20;
	if (key == 65363)
		t_data->shift_x += 20;
    if (key == 65307)
        ft_free_tab(t_data, t_data->height);
    key_helper(key, t_data);
	// mlx_destroy_image(t_data->mlx_ptr, t_data->image);
	// t_data->image = mlx_new_image(t_data->mlx_ptr, 1000, 1000);
	// t_data->addr = mlx_get_data_addr(t_data->image, &t_data->bits_per_pixel, 
	// &t_data->line_length, &t_data->endian);
	draw(t_data);
	// mlx_put_image_to_window(t_data->mlx_ptr, t_data->win_ptr, t_data->image, 0, 0);
	return (0);
}

// int    deal_key(int key, t_struct *data, t_coor *points)
// {
//     ft_printf("%d\n", key);
//     if (key == 65361 || key == 65362 || key == 65363 || key == 65364)
//         move_key(key, data);
//     if (key == 97 || key == 122)
//         projection(key, data, points);
//     if (key == 65453 || key == 65451)
//         zoom_key(key, data);
//     if (key == 116 || key == 117 || key == 119)
//         rotate(key, data);
//     if (key == 65307)   
//         ft_free_tab(data, data->height);
//     return (0);
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
    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.image, 0, 0);
    // mlx_key_hook(data.win_ptr, deal_key, &data);
    // mlx_mouse_hook(data->win_ptr, deal_mouse, data);
    mlx_loop(data.mlx_ptr);
    free_all(&data);
}
