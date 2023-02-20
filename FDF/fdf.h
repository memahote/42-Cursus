#ifndef FDF_H
# define FDF_H

#include "minilibx-linux/mlx.h"
#include "libft/libft.h"

typedef struct s_struct
{
    int width;
    int height;
    int **matrix_z;

    void    *mlx_ptr;
    void    *win_ptr;
}       t_struct;
#endif