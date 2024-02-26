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
# include "vector.h"

# define WIDTH 500
# define HEIGHT 500


t_vector	*vector_init(float x, float y, float z);

typedef struct s_global
{
	void	*mlx;
	void	*mlx_window;
	int		width;
	int		height;
}		t_global;

void	init_ent(t_entire *ent);

#endif