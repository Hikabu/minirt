/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:31:31 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/23 12:20:58 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_objects_in_pixel(t_pixel *pixel, t_plane *plane,
	t_sphere *sphere, t_cylinder *cylinder)
{
	if (!pixel)
		return ;
	pixel->plane = plane;
	pixel->sphere = sphere;
	pixel->cylinder = cylinder;
}

void	check_intersection(t_entire *global, t_pixel *pixel)
{
	float		dist; 
	
	set_objects_in_pixel(pixel, 0, 0, 0); //init
	dist = -1; // no itrs yet
	pixel->length = -1;
	vector_subtraction(&(pixel->d),
		&(pixel->ray.point[0]), &(pixel->ray.point[1])); //differences
	normalizing_vector(&(pixel->d), &(pixel->d));
	pixel->plane = check_for_planes(global, &pixel->ray, &(pixel->d), &dist); 
	if (dist != -1)
		pixel->length = dist;
	pixel->sphere = check_for_spheres(global, &pixel->ray, &pixel->d, &dist);
	if (dist > 0 && (pixel->length == -1 || dist < pixel->length))
	{
		pixel->length = dist;
		set_objects_in_pixel(pixel, 0, pixel->sphere, 0);
	}
	pixel->cylinder = check_for_cylinder(global, pixel, &dist);
	if (dist != -1 && (pixel->length == -1 || dist < pixel->length))
	{
		pixel->length = dist;
		set_objects_in_pixel(pixel, 0, 0, pixel->cylinder);
	}
	else
		pixel->cylinder = 0;
}

t_sphere	*check_for_spheres(t_entire *global, t_ray *ray,
					t_coord *d, float *dist)
{
	t_sphere	*sphere;
	t_sphere	*closest_sphere;
	float		tmp;
	float		length;

	sphere = global->scene->obj->spheres;
	closest_sphere = 0;
	length = -1;
	while (sphere)
	{
		tmp = check_intersection_sphere(sphere, ray, d);
		if (tmp > 0 && (length == -1 || tmp < length))
		{
			length = tmp;
			closest_sphere = sphere;
		}
		sphere = sphere->next;
	}
	*dist = length;
	return (closest_sphere);
}

t_plane	*check_for_planes(t_entire *global, t_ray *ray,
					t_coord *d, float *dist)
{
	t_plane	*plane;
	t_plane	*nearest_plane;
	float	nearest_dist;

	plane = global->scene->obj->planes;
	nearest_dist = -1;
	nearest_plane = 0;
	while (plane)
	{
		*dist = check_intersection_plane(plane, ray, d);
		if (*dist > -1 && (nearest_dist == -1 || *dist < nearest_dist))
		{
			nearest_dist = *dist;
			nearest_plane = plane;
		}
		plane = plane->next;
	}
	*dist = nearest_dist;
	return (nearest_plane);
}

t_cylinder	*check_for_cylinder(t_entire *global, t_pixel *pixel, float *dist)
{
	t_cylinder	*cylinder;
	t_cylinder	*nearest_cylinder;
	float		nearest_dist;

	cylinder = global->scene->obj->cylinders;
	nearest_dist = -1;
	nearest_cylinder = 0;
	while (cylinder)
	{
		*dist = check_intersection_cylinder(cylinder, pixel);
		if (*dist > 0 && (nearest_dist == -1 || *dist < nearest_dist))
		{
			nearest_dist = *dist;
			nearest_cylinder = cylinder;
		}
		cylinder = cylinder->next;
	}
	*dist = nearest_dist;
	return (nearest_cylinder);
}
