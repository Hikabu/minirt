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

typedef enum e_object_id
{
    id_unset = 0,
    id_ambient,
    id_light,
    id_camera,
	id_cyl,
	id_sphere,
	id_plane,
} t_object_id;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_ambient_lightning
{
	t_object_id	id;
	float		ratio;
	t_color		rgb;
}	t_amlight;

typedef struct s_light
{
	t_object_id id;
	t_crd		xyz;
	float		ratio;
	int			color;
	t_color		rgb;
	t_light		*next;
}	t_light;

typedef struct s_camera
{
	t_object_id id;
	t_crd		xyz;
	t_crd		norm_vec;
	size_t		fov;
	t_crd		*origin;
	t_crd		*direction;
	t_crd		*crd;
}	t_camera;

typedef struct s_plane
{
	t_crd			point;
	t_object_id 	id;
	t_crd			xyz;
	t_crd			norm_vec;
	t_color			rgb;
	int				color;
	int				color_ambient;
	t_plane			*next;
}	t_plane;

typedef struct s_cylinder
{
	t_crd			point;
	t_plane			plato_begin;
	t_plane			plato_end;
	float			heig;
	t_object_id 	id;
	t_crd			xyz;
	t_crd			norm_vec;
	float			diam;
	t_color			rgb;
	int				color;
	int				color_ambient;
	t_cyl			*next;
}	t_cyl;


typedef struct s_sphere
{
	t_crd			point; //coordintes
	t_object_id		id;
	t_crd			xyz;
	float			diametr;
	t_color			rgb;
	int				color_ambient;
	int				color;
	t_sphere		*next; //if several figures
}	t_sphere;

typedef struct s_entire
{
	t_obj		*obj;
	t_amlight	*amlight;
	t_camera	*camera;
	t_scene		*scene;
	t_light		*light;
	t_plane		*plane;
	t_cyl		*cyl;
	t_sphere	*sphere;
	t_crd		*crd;
	t_color		*col;
	t_img		simg;
	t_pixel		*pixel;
    void		*img;
    char		*addr;
    void		*mlx;
	void		*window;
    int			bits_per_pixel;
    int			line_length;
	int			endian;
}	t_entire;

typedef	struct s_objects
{
	t_light		*light;
	t_plane		*plane;
	t_cyl		*cyl;
	t_sphere	*sphere;
} t_obj;

// typedef t_crd  t_color;


void		init_all(t_entire *ent);
void		translate_obj(t_scene *scene, t_crd *crd);

void		vector_addition(t_crd *result, t_crd *a, t_crd *b);
int			parse_vector(char *str, t_crd *vect);
int			parse_color(char *str, t_color *color);
int			parse_float(char *str, float *num);
int			show_parsing_error(t_entire *ent, char **arr, char *msg);
int			array_length(char *arr[]);
int			parse_ambient(t_entire *ent, char *line);
int			parse_camera(t_entire *ent, char *line);
int			parse_light(t_entire *ent, char *line);
int			parse_sphere(t_entire *ent, char *line);
int			parse_plane(t_entire *ent, char *line);
int			parse_cylinder(t_entire *ent, char *line);
void		free_array(char *arr[]);
int			parse_ulong(char *str, size_t *num);
int			str_to_int_color(char *str);
int			is_ulong(char *str);

int			parse_params(t_entire *ent, char *line);
void		error(int er);
void		count_of_split(char **str, int count);
void		float_range_checker(float *key, float value, int flag_range);
void		error_with_free(t_entire *ent);

//figures
t_cyl		*check_for_cilinder(t_entire *data, t_pixel *pixel, float *dist);
float		check_intersection_cyl(t_cyl *cyl, t_pixel *pixel);
float		check_intersection_plane(t_plane *plane, t_ray *ray, t_crd *rd);

void		ft_mlx_pixel_put_img(t_img *img, int x, int y, const int color);
// void		ft_mlx_pixel_put_img(unsigned char *data, int x, int y,  const int color);
float		ang_bet_2_vec(t_crd *a, t_crd *b);
t_color		*int_to_rgb(const int r, const int g, const int b);

//color
int			rgb_to_int(const t_color rgb);
// int 		convert_color_to_int(const t_color color);
void		print_entire(t_entire **e);

#endif