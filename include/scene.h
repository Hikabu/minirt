/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:05:37 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/03/15 21:22:13 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "parcing.h"
// # include "minirt.h"

typedef struct	s_ambient_lightning		t_amlight;
typedef struct	s_light					t_light;
typedef struct	s_plane					t_plane;
typedef struct	s_cylinder				t_cyl;
typedef struct	s_sphere				t_sphere;
typedef struct	s_entire				t_entire;
typedef struct 	s_objects				t_obj;
typedef	struct	s_pixel					t_pixel;
typedef struct 	s_camera				t_camera;
typedef enum 	e_object_id				t_object_id;

typedef	struct	s_coordinates_for_vector
{
	float	x;
	float	y;
	float	z;
}	t_crd;

typedef struct s_two_points_for_ray_direction
{
	t_crd point[2]; //the direction of the ray is the vector from point[0] to point[1] - some point.
}	t_ray;

typedef	struct s_objects
{
	t_light		*light;
	t_plane		*plane;
	t_cyl		*cyl;
	t_sphere	*sphere;
} t_obj;

typedef struct s_scene
{
	int			ambient_light_rgb;
	float		camera_fov;
	float		camera_angeles[2];
	float		ambient_light_intensiv;
	t_crd		camera_point; // from where trace the rays
	t_crd		camera_orientation; //where the camera will look this 2 like viewpoint
	t_entire	*ent;
	t_obj		*obj;
	t_camera	*camera;
}	t_scene;

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
	t_scene		*scene;
	t_img		simg;
    void		*img;
    char		*addr;
    void		*mlx;
	void		*window;
    int			bits_per_pixel;
    int			line_length;
	int			endian;
	t_entire	*ent;
}	t_data;

typedef struct s_vplane
{
	float width;
	float height;
	float x_pixel;
	float y_pixel;
	
}	t_vplane;



float		vec_product(t_crd *vec1, t_crd *vec2);
void 		vec_normalize(t_crd *vec);
float 		vec_length(t_crd *vec);
t_crd		*vecsubtraction(t_crd *vec1, t_crd *vec2);
t_crd		*crd_init(float x, float y, float z);
void		init_image(t_data *data);
void		all_exiests(t_entire *ent);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int 		key_hook(int keycode, void *param);
void		color_back(void	*img);
void		get_fov_angles(t_scene *scene);
void		pixel_computing(t_data *data, t_pixel *pixel);


void		fill_coordinates_for_camera(t_camera *camera, t_crd *camera_point);
void		initial_scene(t_scene *scene);
// camera
t_camera	*init_camera(t_crd *origin, t_crd *direction, float fov);


// scene 
t_scene		*init_scene(t_camera *camera, t_sphere *sphere);
void		check_intersection(t_data *data, t_pixel *pixel);
int			solve_quadro_eq(float a, float b, float c, float roots[2]);
t_vplane    *get_view_plane(float width, float height, float fov);

//vector 
float		vector_len(t_crd *vector);
void		vector_subtraction(t_crd *res, t_crd *a, t_crd *b);
void		norm_vector(t_crd *vec);
float		scalar_vector_product(t_crd *a, t_crd *b);
void		scalar_multiplication(t_crd *res, t_crd *vector, float lambda);
float		nearest_distance(float *points);
//intersaction 
t_sphere	*check_for_spheres(t_data *data, t_ray *ray, t_crd *rd, float *dist);
float		check_intersection_sphere(t_sphere *sphere, t_ray *ray, t_crd *rd);

//color shadow
void	pixel_plane_computing(t_data *data, t_pixel *pixel);
void	pixel_computing(t_data *data, t_pixel *pixel);
void 	pixel_computing_sphere(t_data *data, t_pixel *pixel);
void	pixel_computing_cyl(t_data *data, t_pixel *pixel);
float	pixel_comp_sphere_refl_ratio(t_data *data, t_pixel *pixel);

int		check_for_shadow(t_data *data, t_pixel *pixel);
int		check_for_shadow_cyl(t_data *data, t_ray *ray, t_crd *crd);
int		check_for_shadow_plane(t_data *data, t_ray *ray, t_crd *crd);
int 	check_for_shadow_sphere(t_data *data, t_ray *ray, t_crd *crd);

//

#endif