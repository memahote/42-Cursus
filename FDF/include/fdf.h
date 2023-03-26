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
# define ORANGE 0xffa500
# define YELLOW 0xFFFF00
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

    float angle_x;
    float angle_y;
    int color;
    int shift_x;
    int shift_y;
    int depth;
    int iso;

    void    *mlx_ptr;
    void    *win_ptr;
    void    *image;
    char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    char    *background;

}       t_struct;

typedef struct s_coor
{
    float   x;
    float   y;
    float   x1;
    float   y1;
    int     z;
    int     z1;
}       t_coor;


/*****read map*****/

void    read_file(char  *file_name, t_struct *data);
int     fill_matrix(int *matrix_z, char *line);
void    get_height_width(char *file_name, t_struct *data);
void    init_data(t_struct *data);

/*****draw*****/

void    draw(t_struct *data);
void    bresenham(t_coor points, t_struct *data);
void    isometric(t_coor points, t_struct *data, int z, int z1);
void    algo(t_coor points, t_struct *data, int status);

/*****deal keys*****/

int	    deal_key(int key, t_struct *t_data);
void	key_helper(int key, t_struct *t_data);


/*****init*****/

void    init_data(t_struct *data);

/****clean*****/

void	free_all(t_struct *data);
void	ft_free_tab(t_struct *data, int len);
int	    close_window(t_struct *data);

/****utils*****/

void	zoom(t_coor *points, t_struct *data);
void	shift(t_coor *points, t_struct *data);
int	    max(int x,int y);
int	    mod(int x);
void    draw_menu(t_struct *data);


void	menu(t_struct *t_data);

#endif