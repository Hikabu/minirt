/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:29:19 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/03/22 18:57:11 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_obj_in_pix(t_pixel *pixel, t_plane *plane, t_sphere *sphere, t_cyl *cyl)
{
	if (!pixel)
		return ;
	pixel->plane = plane;
	pixel->cyl = cyl;
	pixel->sphere = sphere;
}

float	check_intersection_plane(t_plane *plane, t_ray *ray, t_crd *rd)
{
	float	t;
	float	dot_dn;
	t_crd	sub_ra;

	dot_dn = scalar_vector_product(rd, &(plane->norm_vec));
	if (dot_dn == 0)
		return (-1);
	vector_subtraction(&sub_ra, &(ray->point[0]), &(plane->xyz));
	t = scalar_vector_product(&sub_ra, &(plane->norm_vec)) / dot_dn;
	if (t < 0)
		return (-1);
	return (t);
}

t_plane	*check_for_planes(t_entire *data, t_ray *ray, t_crd *d, float *dist)
{
	t_plane *plane;
	t_plane	*nearest_plane;
	float	nearest_dist;

	plane = data->scene->obj->plane;   //planes?
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

void check_intersection(t_entire *data, t_pixel *pixel)
{
	float dist; //dis from cmr to the itrs pnt of a ray with an obj in the scene

	set_obj_in_pix(pixel, 0, 0, 0);
	dist = -1;//no itrs yet
	pixel->lenght = -1;
	vector_subtraction(&(pixel->coor),
						&(pixel->ray.point[0]), &(pixel->ray.point[1])); //differences
	norm_vector(&(pixel->coor)); //we know direction we simplify calculating by sainf it 1 ?
	pixel->plane = check_for_planes(data, &pixel->ray, &pixel->coor, &dist);//closest plne
	if (dist != -1)
		pixel->lenght = dist;
	pixel->sphere = check_for_spheres(data, &pixel->ray, &pixel->coor, &dist);
	if (dist > 0 && (pixel->lenght == -1 || dist < pixel->lenght))
	{
		pixel->lenght = dist;
		set_obj_in_pix(pixel, 0, pixel->sphere, 0);
	}
	// pixel->cyl = check_for_cilinder(data, pixel, &dist);
	// pixel-> = check_for_cilinder(data, pixel, &dist);
	if (dist != -1 && (pixel->lenght == -1 || dist < pixel->lenght))
	{
		pixel->lenght = dist;
		set_obj_in_pix(pixel, 0, 0, pixel->cyl);
	}
	else
		pixel->cyl = 0;
}
