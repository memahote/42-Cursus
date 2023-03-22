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
void get_height(char *file_name, t_struct *data)
{
    int     fd;
    char    *line;

    data->height = 0;
    fd = open(file_name, O_RDONLY);
    line = get_next_line(fd);
    if (!line)
		return ;
    while(line != NULL)
    {
        data->height++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
}

void    fill_matrix(int *matrix_z, char *line)
{
    char    **coor;
    int     i;

    coor = ft_split(line, ' ');
    i = 0;
    while(coor[i])
    {
        matrix_z[i] = ft_atoi(coor[i]);
        free(coor[i]);
        i++;
    }
    free(coor);
}

void    read_file(char  *file_name, t_struct *data)
{
    char    *line;
    int     fd;
    int     i;

    i = 0;
    get_height(file_name, data);
    fd = open(file_name, O_RDONLY);
    line = get_next_line(fd);
    data->width  = ft_wordcount(line, ' ');
    data->matrix_z = malloc(sizeof(int *) * (data->height + 1));
    while(i <= data->height)
    {
        data->matrix_z[i] = malloc(sizeof(int *) * (data->width + 1));
        i++;
    }
    i = 0;
    while(line != NULL)
    {
        fill_matrix(data->matrix_z[i], line);
        free(line);
        i++;
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
    data->matrix_z[i] = 0;
}