#ifndef PARCING_H
# define PARCING_H

# include "scene.h"	
#include "minirt.h"


# define ERR_TOO_MANY_CAMERAS "Too many camera params"
# define ERR_TOO_MANY_AMBIENTS "Too many ambient params"
# define ERR_INVALID_NB_PARAMS "Invalid number of params"
# define ERR_INVALID_NB_COORDS "Invalid number of coordinates values"
# define ERR_INVALID_NB_ORIENT "Invalid number of orientation values"
# define ERR_INVALID_NB_COLORS "Invalid number of color values"
# define ERR_NOT_A_ULONG "Value is not a unsigned long"
# define ERR_NOT_A_FLOAT "Value is not a float"



typedef struct	s_light						t_light;
typedef struct	s_ambient_lightning			t_amlight;
typedef struct	s_plane						t_plane;
typedef struct	s_cylinder					t_cyl;
typedef struct	s_scene						t_scene;
typedef struct	s_img						t_img;
// typedef	struct	s_coordinates_for_vector	t_crd;

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
}	t_color;

typedef struct s_ambient_lightning
{
	int		id;
	t_object_id id;
	float	ratio;
	t_color		rgb;
}	t_amlight;

typedef struct s_light
{
	int		id;
	t_object_id id;
	t_crd	xyz;
	float	ratio;
	t_color	rgb;
	t_light	*next;
}	t_light;

typedef struct s_camera
{
	int			id;
	t_object_id id;
	t_crd		xyz;
	t_crd		norm_vec;
	int			fov;
	t_crd	*origin;
	t_crd	*direction;
	t_crd	*crd;
}	t_camera;

typedef struct s_plane
{
	t_crd			point;
	int				id;
	t_object_id id;
	t_crd			xyz;
	t_crd			norm_vec;
	t_color			rgb;
	t_plane			*next;
}	t_plane;

typedef struct s_plat				//  represent the surfaces of objects in a scene
{
	t_crd	point;
	t_crd 	orient;
	int		color;
	int		color_amb;
	t_plato	*next;
} 	t_plato;

typedef struct s_cylinder
{
	t_crd			point;
	t_crd			orient;
	float			diam;
	t_plato			plato_begin;
	t_plato			plato_end;
	int				id;
	float			xyz[3]; //orinentation
	float			norm_vec[3];  //point 
	float			heig;
	int				rgb[3];
	int				color; //rgb[3]
	t_object_id id;
	t_crd				xyz;
	t_crd				norm_vec;
	float				diam;
	float				heig;
	t_color				rgb;
	t_cyl			*next;
}	t_cyl;


typedef struct s_sphere
{
	t_crd			point;
	int				id;
	t_object_id id;
	t_crd			xyz;
	float			diametr;
	t_color			rgb;
	int				color_ambient;
	// t_vector		*center;
	t_sphere		*next; //if several figures
}	t_sphere;

typedef struct s_entire
{
	t_amlight	*amlight;
	t_camera	*camera;
	t_scene		*scene;
	t_light		*light;
	t_plane		*plane;
	t_cyl		*cyl;
	t_sphere	*sphere;
	t_crd		*crd;
}	t_entire;

void		error(int er);
int			parc(char *line, t_entire **ent, t_data *data);
int			a_ligth(char *str);
int			readmap(char *str, t_entire **ent, t_data *data);
void		id_check(char **str, t_entire **ent);
// void		id_check(char **str, t_entire **ent, t_scene *scene);
void		count_of_split(char **str, int count);
void		free_a(char **split_str_2);
// void		free_c(char **split_str_1, char **split_str_2);
void		free_l(char **split_str_1, char **split_str_3);
void		free_pl(char **split_str_1, char **split_str_2, char **split_str_3);
void		free_cy(char **split_str_1, char **split_str_2, char **split_str_5);
void		free_sp(char **split_str_1, char **split_str_3);
t_amlight	*to_struct_a(char **str);
// t_camera	*to_struct_c(char **str);
t_camera	*to_struct_c(char **str, t_scene *scene);
t_light		*to_struct_l(char **str);
t_plane		*to_struct_pl(char **str);
t_cyl		*to_struct_cy(char **str);
t_sphere	*to_struct_sp(char **str);
void		int_range_checker(int *key, int value, int flag_range);
void		float_range_checker(float *key, float value, int flag_range);
void		id_check1(char **str, t_entire **ent);
void		error_with_free(t_entire *ent);

//figures
// t_sphere	*init_sphere(t_vector *center, float radius);




void	print_entire(t_entire **e);

#endif