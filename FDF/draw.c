/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:58:07 by memahote          #+#    #+#             */
/*   Updated: 2023/02/21 18:58:07 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    isometric(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.8);
    *y = (*x + *y) * sin(0.8) - z;
}

void    bresenham(float x, float y, float x1, float y1, t_struct *data)
{
    float   x_steps;
    float   y_steps;
    int     Max;
    int     z;
    int     z1;

    z = data->matrix_z[(int)y][(int)x];
    z1 = data->matrix_z[(int)y1][(int)x1];
    //ZOOM
    x *= data->zoom;
    y *= data->zoom;
    x1 *= data->zoom;
    y1 *= data->zoom;
    //COLOR
    data->color = (z || z1) ? RED : WHITE;
    // //3D
    isometric(&x, &y, z);
    isometric(&x1, &y1, z1);
    // // //shift
    x += data->shift_x;
    y += data->shift_y;
    x1 += data->shift_x;
    y1 += data->shift_y;

    x_steps = x1 - x;
    y_steps = y1 - y;
    Max = MAX(Mod(x_steps), Mod(y_steps));
    x_steps /= Max;
    y_steps /= Max;
    while((int)(x - x1) || (int)(y - y1))
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
        x += x_steps;
        y += y_steps;
    }
}

void    draw(t_struct *data)
{
    int x;
    int y;

    y = 0;
    while (y < data->height)
    {
        x = 0;
        while (x < data->width)
        {
            if (x < data->width - 1)
                bresenham(x, y, x + 1, y, data);
            if (y < data->height - 1)
                bresenham(x, y, x, y + 1, data);
            x++;
        }
        y++;
    }

}