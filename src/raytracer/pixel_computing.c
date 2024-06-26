/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_computing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:31:50 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/22 14:10:16 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define MINIMAL_THRESHOLD 0.0001
#define MAXIMAL_THRESHOLD 0.9985

int	check_for_shadow_spheres(t_entire *global, t_ray *ray, t_coord *d)
{
	t_sphere	*sphere;
	float		length;

	sphere = global->scene->obj->spheres;
	length = -1;
	while (sphere)
	{
		length = check_intersection_sphere(sphere, ray, d);
		if (length > MINIMAL_THRESHOLD && length < MAXIMAL_THRESHOLD)
			return (1);
		sphere = sphere->next;
	}
	return (0);
}

int	check_for_shadow_planes(t_entire *global, t_ray *ray, t_coord *d)
{
	t_plane	*plane;
	float	dist;

	plane = global->scene->obj->planes;
	while (plane)
	{
		dist = check_intersection_plane(plane, ray, d);
		if (dist > MINIMAL_THRESHOLD && dist < MAXIMAL_THRESHOLD)
			return (1);
		plane = plane->next;
	}
	return (0);
}

int	check_for_shadow_cylinder(t_entire *global, t_ray *ray, t_coord *d)
{
	t_pixel		pixel;
	t_cylinder	*cylinder;
	float		dist;

	cylinder = global->scene->obj->cylinders;
	pixel.ray = *ray;
	pixel.d = *d;
	while (cylinder)
	{
		dist = check_intersection_cylinder(cylinder, &pixel);
		if (dist > MINIMAL_THRESHOLD && dist < MAXIMAL_THRESHOLD)
			return (1);
		pixel.ray = *ray;
		pixel.d = *d;
		cylinder = cylinder->next;
	}
	return (0);
}

int	check_for_shadow(t_entire *global, t_pixel *pixel_initial)
{
	// float	dist;
	t_ray	ray;
	t_coord	d;

	// dist = -1;
	ray.point[0] = pixel_initial->d;
	scalar_multiplication(&ray.point[0], &ray.point[0],
		-pixel_initial->length * 0.995);
	vector_addition(&ray.point[0], &pixel_initial->ray.point[0],
		&ray.point[0]);
	ray.point[1] = global->scene->obj->lights->point;
	vector_subtraction(&d, &(ray.point[0]), &(ray.point[1]));
	if (check_for_shadow_spheres(global, &ray, &d))
		return (1);
	if (check_for_shadow_planes(global, &ray, &d))
		return (1);
	if (check_for_shadow_cylinder(global, &ray, &d))
		return (1);
	return (0);
}

void	pixel_computing(t_entire *global, t_pixel *pixel)
{
	if (pixel->length <= 0
		|| (!pixel->plane && !pixel->sphere && !pixel->cylinder))
	{
		mlx_pixel_put(global->mlx, global->window,
			pixel->x, pixel->y, BACKGROUND_COLOR);
		return ;
	}
	pixel->intersection = pixel->d;
	scalar_multiplication(&pixel->intersection, &pixel->intersection,
		-pixel->length);
	vector_addition(&pixel->intersection, &pixel->ray.point[0],
		&pixel->intersection);
	if (pixel->plane)
		pixel_computing_plane(global, pixel);
	else if (pixel->sphere)
		pixel_computing_sphere(global, pixel);
	else if (pixel->cylinder)
		pixel_computing_cylinder(global, pixel);
}
