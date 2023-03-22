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
#include <stdio.h>

void	draw_menu(t_struct *data)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = data->mlx_ptr;
	win = data->win_ptr;
	mlx_string_put(mlx, win, 50, y += 20, WHITE, "********************");
	mlx_string_put(mlx, win, 50, y += 20, WHITE, "* Fil de Fer (FDF) *");
	mlx_string_put(mlx, win, 50, y += 20, WHITE, "********************");
	mlx_string_put(mlx, win, 15, y += 70, TEXT_COLOR, "Change Palette: C");
	mlx_string_put(mlx, win, 15, y += 50, TEXT_COLOR, "Zoom: Scroll or +/-");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move: Arrow && Mouse");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Elevation: U / D");
	mlx_string_put(mlx, win, 15, y += 60, WHITE, "Rotate:");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "X-Axis - Key 4 or 6");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Y-Axis - Key 2 or 8");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Z-Axis - Key 1 or 9");
	// projection_menu_selector(app, mlx, win, y);
	mlx_string_put(mlx, win, 15, y += 200, TEXT_COLOR, "Rotate Video: V");
}


int deal_key(int key, t_struct *data)
{
    ft_printf("%d\n", key);
    
    if (key == 122)
        data->shift_y -=10;
    if (key == 121)
        data->shift_y +=10;
    if (key == 119)
        data->shift_x -=10; 
    if (key == 120)
         data->shift_x +=10;
    if (key == 65453)
        data->zoom -= 5;
    if (key == 65451)
        data->zoom += 5;
    if (key == 65307)   
        close_window(data);
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    // mlx_destroy_image(data->mlx_ptr, data->image);
    // data->image = mlx_new_image(data->mlx_ptr, 1000, 1000);
    draw(data);
    // mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, 500, 500);
    return(0);
}

int deal_mouse(int key, t_struct *data)
{
    ft_printf("%d\n", key);
    (void)data;
    return (0);
}

int zoom(int key, t_struct *data)
{
    if (key == 4)
        data->zoom -= 5;
    return(0);
}


int main(int argc, char **argv)
{
    t_struct    *data;

    (void)argc;
    data = malloc(sizeof(t_struct));
    if (!data)
        return (0);
    read_file(argv[1], data);
    init_data(data);
    draw(data);
    mlx_hook(data->win_ptr, 17, (1l << 0), close_window, data);
    mlx_hook(data->win_ptr, 2, (1l << 0), deal_key, data);
    // mlx_key_hook(data->win_ptr, deal_key, data);
    // mlx_mouse_hook(data->win_ptr, deal_mouse, data);
    // draw_menu(data);
    // mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, 0, 0);
    mlx_loop(data->mlx_ptr);
    free_all(data);
}

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world!");
// 	img.img = mlx_new_image(mlx, 1000, 1000);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	my_mlx_pixel_put(&img, 50, 50, 0xffffff);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }