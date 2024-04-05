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
# include "scene.h"
# include "utils.h"
# include "parcing.h"
# define WIDTH 800
# define HEIGHT 600
# define BACKGROUND 0
# define BACKGROUND_COLOR 0
# define MIN_TRASHOLD 0.0001
# define MAX_TRASHOLD 0.9985
# define ALBEDO 0.18
// typedef struct 	s_light 						t_light;
//typedef struct 	s_scene							t_scene;
// typedef	struct	s_coordinates_for_vector		t_crd;
// typedef struct 	s_two_points_for_ray_direction	t_ray;

typedef	struct s_pixel
{
	int			x;
	int			y;
	t_crd		coor;
	t_crd		intersection;
	float		lenght;
	t_plane		*plane;
	t_sphere	*sphere;
	t_cyl		*cyl;
	t_ray		ray;
	int			cyl_type;
	float		cyl_m;
}	t_pixel;


typedef enum e_type_object // only for clearness 
{
	NO_INTERSECT,
	PIPE,
	PLANE_BEGIN,
	PLANE_END,
	PLANE,
	SPHERE,
	CYLINDER,
}	t_type_object;


void	ray_trace(t_entire *data);
void    fill_new_vector(t_crd *result, float x, float y, float z);
void	print_scene(t_entire *ent, t_scene	*scene);
int		open_and_parse_file(t_entire *ent, const char *path);


// void	error(int er);

#endif