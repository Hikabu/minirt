/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:35:15 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/19 18:35:16 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCENE_H
# define SCENE_H

# include "minirt.h"

typedef struct s_light		t_light;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;
typedef struct s_scene		t_scene;
typedef struct s_objects	t_objects;

typedef struct s_coord
{
	float	x;
	float	y;
	float	z;
}	t_coord;

typedef struct s_ray
{
	t_coord	point[2];
}	t_ray;

struct s_light
{
	t_coord	point;
	float	lighting_ratio;
	int		color;
	t_light	*next;
};

struct s_sphere
{
	t_coord		point;
	float		diameter;
	int			color;
	int			color_ambient;
	t_sphere	*next;
};

struct s_plane
{
	t_coord	point;
	t_coord	orientation;
	int		color;
	int		color_ambient;
	t_plane	*next;
};

struct s_cylinder
{
	t_coord		point;
	t_coord		orientation;
	float		diameter;
	float		height;
	int			color;
	int			color_ambient;
	t_plane		plane_begin;
	t_plane		plane_end;
	t_cylinder	*next;
};

struct s_objects
{
	t_light		*lights;
	t_sphere	*spheres;
	t_plane		*planes;
	t_cylinder	*cylinders;
};

struct s_scene
{
	t_coord		camera_point;
	t_coord		camera_orientation;
	float		camera_fov;
	float		camera_angles[2];
	float		ambient_light_intensity;
	int			ambient_light_rgb;
	t_objects	*obj;
};

#endif