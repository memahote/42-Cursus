#ifndef FDF_H
# define FDF_H

# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>


# define MAX(x, y) ((x > y) ? x : y)
# define Mod(x) ((x < 0) ? -x : x)
# define WHITE 0xffffff 
# define RED 0xe80c0c
# define TEXT_COLOR 0x1A1A1D
# define MENU_BACKGROUND 0x950740
# define MINUS 65451
# define PLUS 65453

typedef struct s_struct
{
    int width;
    int height;
    int **matrix_z;
    int zoom;
    float angle;
    int color;
    int shift_x;
    int shift_y;
    int *mouse_x;
    int *mouse_y;

    void    *mlx_ptr;
    void    *win_ptr;
    void    *image;
    char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}       t_struct;


void    read_file(char  *file_name, t_struct *data);
void    fill_matrix(int *matrix_z, char *line);
int     get_width(char  *file_name);
void    get_height(char *file_name, t_struct *data);
void    init_data(t_struct *data);

void    bresenham(float x, float y, float x1, float y1, t_struct *data);
void    draw(t_struct *data);
void    isometric(float *x, float *y, int z);

void	free_all(t_struct *data);
void	ft_free_tab(t_struct *data, int len);
int	    close_window(t_struct *data);

int	    zoom_key(int key, t_struct *data);
int	    move_key(int key, t_struct *data);
int	    deal_key(int key, t_struct *data);

#endif