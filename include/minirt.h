#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../libmlx/mlx.h"
# include "get_next_line.h"
# include "utils.h"
# include "parcing.h"
# include "scene.h"
# define WIDTH 800
# define HEIGHT 600
# define BACKGROUND 1

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data
{
    void    *img;
    char    *addr;
    void	*mlx;
	void	*window;
    int     bits_per_pixel;
    int	    line_length;
	int	    endian;
    t_img	simg;
}	t_data;

// void	error(int er);

#endif