/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:17:39 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/23 12:12:33 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h> 
# include <sys/uio.h> 
# include <stdio.h> 
# include <stdlib.h>
# include <math.h>

# include "../libft/libft.h"
# include "get_next_line.h"
# include "vector.h"
# include "scene.h"
# include "parcing.h"
# include "../libmlx/mlx.h"
# include "transformation.h"

# define WIDTH 500
# define HEIGHT 600

# define BACKGROUND_COLOR 0

/* set mlx events */
# define ON_DESTROY 17
# define ON_KEYDOWN 2
# define ON_BUTTONPRESS 4

# define ESC 53
# define W_KEYHOOK 13
# define A_KEYHOOK 0
# define S_KEYHOOK 1
# define D_KEYHOOK 2
# define X_KEYHOOK 7
# define Y_KEYHOOK 16
# define Z_KEYHOOK 6
# define H_KEYHOOK 4
# define GREATER 47
# define LESS 43
# define UP 126
# define DOWN  125
# define LEFT 123
# define RIGHT 124

# define STEP_TRANSLATE 0.5
# define STEP_ROTATE 0.1
# define STEP_RESIZE 0.1

typedef struct s_parser t_parser;


typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_entire
{
	t_scene		*scene;
	void		*mlx;
	void		*window;
	void		*nearest_obj;
	int			nearest_type;
	int			prev_keyhook;
	t_img		img;
}	t_entire;

typedef enum e_type_object
{
	NO_INTERSECT,
	PIPE,
	PLANE_BEGIN,
	PLANE_END,
	PLANE,
	SPHERE,
	CYLINDER,
}	t_type_object;

typedef struct s_pixel
{
	int			x;
	int			y;
	t_ray		ray;
	t_coord		d;
	float		length;
	t_coord		intersection;
	t_plane		*plane;
	t_sphere	*sphere;
	t_cylinder	*cylinder;
	int			cylinder_type;
	float		cylinder_m;
}	t_pixel;

t_scene		*parser(int argc, char **argv);
void		free_scene(t_scene *scene);
int			minirt_close(t_entire *data);

void		rotate_objects(t_scene *scene, t_coord *coord);
void		translate_objects(t_scene *scene, t_coord *coord);

/* 	./image/image.c 
	functions for mlx management with image*/
void		ft_mlx_pixel_put_img(t_img	*img, int x, int y, int color);
void		init_image(t_entire *data);
void		new_image(void *img);

/* 	./image/hook.c
	manage events*/
int			hook(t_entire *data);
int			key_print_hook(int keycode, t_entire *data);

/* ./image/search_objects.c.c
	search objects for hook */
void		ft_search_objects(int x, int y, t_entire *global);

/* ./image/resize_objects.c
	resize objects for hook */
void		ft_resize_object(int mousecode, t_entire	*global);
void		change_height_cylinder(int keycode, t_entire *global);

/* ./image/change_objects.c */
void		change_sphere(int keycode, t_entire *global);
void		change_cylinder(int keycode, t_entire *global);
void		change_plane(int keycode, t_entire *global);

/*	./raytracing/check_intersection.c
	functions check intersection with objects */
void		check_intersection(t_entire *global, t_pixel *pixel);

t_sphere	*check_for_spheres(t_entire *global, t_ray *ray,
				t_coord *d, float *dist);
t_plane		*check_for_planes(t_entire *global, t_ray *ray,
				t_coord *d, float *dist);
t_cylinder	*check_for_cylinder(t_entire *global, t_pixel *pixel, float *dist);
t_scene		*parser_createscene(t_parser *p);

/*	 ./raytracing/intersection.c
	 function returns distance to plane and sphere */
float		check_intersection_plane(t_plane *plane, t_ray *ray, t_coord *d);
float		check_intersection_sphere(t_sphere *sphere, t_ray *ray, t_coord *d);
float		nearest_distance(float	*points);

/* ./raytracing/intersection_cylinder.c */
float		check_intersection_cylinder(t_cylinder	*cylinder, t_pixel *pixel);

/*	./raytracer/rayracer.c */
void		raytracer(t_entire *global);

/*	./raytracer/pixel_computing.c */
void		pixel_computing(t_entire *global, t_pixel *pixel);
int			check_for_shadow(t_entire *global, t_pixel *pixel_initial);

/*	./raytracer/compute_pixel_cyliner.c */

void		pixel_computing_cylinder(t_entire *global, t_pixel *pixel);

/*	./raytracer/compute_pixel_sphere.c */
void		pixel_cleaning(t_pixel *pixel);
int			color_diffusal(int color_sum, int color1,
				int color2, float intensity);
void		pixel_computing_sphere(t_entire *global, t_pixel *pixel);
float		pixel_computing_sphere_diffusal_recflect_ratio(t_entire *global,
				t_pixel *pixel);

/*	./raytracer/compute_pixel_plane.c */
void		pixel_computing_plane(t_entire *global, t_pixel *pixel);
float		pixel_computing_plane_diffusal_recflect_ratio(t_entire *global,
				t_pixel *pixel);

/*	 ./raytracing/solver.c
	 solver of equations*/
int			solve_quadratic_equation(float a, float b, float c, float roots[2]);

/* utils */
void		print_scene(t_scene	*scene);
void		print_spheres(t_sphere	*sp, char type);
void		print_cylinders(t_cylinder	*cy, char type);
void		print_planes(t_plane	*pl, char type);
void		print_coordinate(t_coord *coord, char *endchar);
void		print_tips(void);

#endif