/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:18:43 by memahote          #+#    #+#             */
/*   Updated: 2023/02/20 14:18:43 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// return la longueur
int get_height(char *file_name)
{
    int     height;
    int     fd;

    height = 0;
    fd = open(file_name, O_RDONLY);
    while(get_next_line(fd))
    {
        height++;
    }
    close(fd);
    return(height);
}

//return la largeur
int get_width(char  *file_name)
{
    int     width;
    int     fd;
    int     i;
    char    *line;

    width = 0;
    fd = open(file_name, O_RDONLY);
    line = get_next_line(fd);
    while(line[i])
    {
        if(line[i] == ' ')
            while(line[i] == ' ')
                i++;
        else
        {
            while(line[i] != ' ')
                i++;
            width++;
        }
    }
    free(line);
    close(fd);
    return (width);
}

void    fill_matrix(t_struct *data, char *line)
{
    char    *high;
    int     i;
}

void    read_file(char  *file_name, t_struct *data)
{
    char    *line;
    int     fd;
    int     i;

    i = 0;
    data->height = get_height(file_name);
    data->width  = get_width(file_name);
    data->matrix_z = malloc(sizeof(int *) * (data->height + 1));
    while(i <= data->height)
    {
        data->matrix_z[i] = malloc(sizeof(int *) * (data->width + 1));
        i++;
    }
    i = 0;
    fd = fd = open(file_name, O_RDONLY);

}