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
# include "parcing.h"
# include "scene.h"
# include "vector.h"
# include "utils.h"

# define WIDTH 500
# define HEIGHT 500



typedef struct s_global
{
	void	*mlx;
	void	*mlx_window;
	int		width;
	int		height;
}		t_global;

typedef struct s_vplane
{
	float	width;
	float	height;
	float	x_pixel;
	float	y_pixel;
}	t_vplane;

 typedef struct s_vector
{
    float x;
    float y;
    float z;
}   t_vector;

// camera
typedef struct s_camera
{
	int			id;
	float		xyz[3];
	float		norm_vec[3];
	float		fov;
	t_vector	*origin;
	t_vector	*direction;
}	t_camera;

typedef struct s_sphere
{
	int				id;
	float			xyz[3];
	float			radius;
	int				rgb[3];
	t_vector		*center;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_scene
{
	t_camera	*cameras;
	t_sphere	*sphere;
	float		width;
	float		height;
}   t_scene;

typedef struct s_ambient_lightning
{
	int		id;
	float	ratio;
	int		rgb[3];
}	t_amlight;

typedef struct s_light
{
	int		id;
	float	xyz[3];
	float	ratio;
	int		rgb[3];
}	t_light;

typedef struct s_plane
{
	int				id;
	float			xyz[3];
	float			norm_vec[3];
	int				rgb[3];
	struct s_plane	*next;
}	t_plane;

typedef struct s_cylinder
{
	int					id;
	float				xyz[3];
	float				norm_vec[3];
	float				diam;
	float				heig;
	int					rgb[3];
	struct s_cylinder	*next;
}	t_cyl;



typedef struct s_entire
{
	t_amlight	*amlight;
	t_camera	*camera;
	t_light		*light;
	t_plane		*plane;
	t_cyl		*cyl;
	t_sphere	*sphere;
}	t_entire;

void		error(char *er);
int			parc(char *line, t_entire **ent);
int			a_ligth(char *str);
int			readmap(char *str, t_entire **ent);
void		id_check(char **str, t_entire **ent);
void		count_of_split(char **str, int count);
void		free_a(char **split_str_2);
void		free_c(char **split_str_1, char **split_str_2);
void		free_l(char **split_str_1, char **split_str_3);
void		free_pl(char **split_str_1, char **split_str_2, char **split_str_3);
void		free_cy(char **split_str_1, char **split_str_2, char **split_str_5);
void		free_sp(char **split_str_1, char **split_str_3);
t_amlight	*to_struct_a(char **str);
t_camera	*to_struct_c(char **str);
t_light		*to_struct_l(char **str);
t_plane		*to_struct_pl(char **str);
t_cyl		*to_struct_cy(char **str);
t_sphere	*to_struct_sp(char **str);
void		int_range_checker(int *key, int value, int flag_range);
void		float_range_checker(float *key, float value, int flag_range);
void		id_check1(char **str, t_entire **ent);
void		error_with_free(t_entire *ent);
void		mlx_tracing(t_entire *ent);
void	init_a(t_amlight *list);
void	init_l(t_light *list);
void	init_pl(t_plane *list);
void	init_cy(t_cyl *list);
void	init_ent(t_entire *ent);

//figures
t_sphere	*init_sphere(t_vector *center, float radius);

t_vector	*vector_init(float x, float y, float z);
t_vector	*vecsubtraction(t_vector *vec1, t_vector *vec2);
float		vec_length(t_vector *vec);
void		vec_normalize(t_vector *vec);
float		vec_product(t_vector *vec1, t_vector *vec2);
int			sphere_intersect(t_camera *camera, t_vector *ray, t_sphere *sphere);
void		ray_tracing(void *mlx, void *window, t_scene *scene);
void		init_c(t_camera *list);
void		init_sp(t_sphere *list);
t_vector	*vector_init(float x, float y, float z);
float vec_product(t_vector *vec1, t_vector *vec2);
void vec_normalize(t_vector *vec);
float vec_length(t_vector *vec);
t_vector	*vecsubtraction(t_vector *vec1, t_vector *vec2);
t_vector	*vector_init(float x, float y, float z);

t_camera	*init_camera(t_vector *origin, t_vector *direction, float fov);



// scene 
t_scene	*init_scene(t_camera *camera, t_sphere *sphere, float width, float height);

void	ft_lstadd_back_plane(t_plane **lst, t_plane *new);
void	ft_lstadd_back_cyl(t_cyl **lst, t_cyl *new);
void	ft_lstadd_back_sphere(t_sphere **lst, t_sphere *new);

#endif