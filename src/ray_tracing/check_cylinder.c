/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 00:42:25 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/03/13 13:18:05 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


static float intersection_cylinder_pipee(t_cyl *cyl, t_crd *crd, t_crd *os, t_pixel *pixel);

static void	define_cyl(t_cyl *cyl, t_plane *plane, t_crd *point)
{
	plane->point = *point;
	plane->color = cyl->color;
	plane->xyz = cyl->xyz;
	plane->color_ambient = cyl->color;
}

static	float intersection_cyl_plane(t_cyl *cyl, t_plane *plane, t_ray *ray, t_crd *d_ray)
{
	float	dist_plane;
	t_crd	r;
	t_crd	p;
	t_crd	p_ctr;

	dist_plane = check_intersection_plane(plane, ray, d_ray);
	if (dist_plane == -1)
		return (-1);
	scalar_multiplication(&r, d_ray, -1 * dist_plane);
	vector_addition(&p, &(ray->point[0]), &r);
	vector_subtraction(&p_ctr, &p, &plane->point);
	if (vector_len(&p_ctr) <= cyl->diam / 2.0f)
		return (dist_plane);
	return (-1);
}

float	nearest_distance(float *points) //determine the nearest intersection point between a ray and an object in the scene.
{
	if (points[0] < 0 && points[1] < 0)
		return (-1);
	if (points[0] < 0)
		points[0] = points[1];
	else if (points[1] < 0)
		points[1] = points[0];
	if (points[0] <= points[1] && points[0] > 0)
		return (points[0]);
	if (points[1] <= points[0] && points[1] > 0)
		return (points[1]);
	return (-1);
}

static float intersection_cylinder_pipee(t_cyl *cyl, t_crd *crd, t_crd *os, t_pixel *pixel)
{
	float	points[2];
	float	dot_dv;
	float	dot_ocv;
	t_crd	coef;

	dot_dv = scalar_vector_product(crd, &(cyl->xyz));
	dot_ocv = scalar_vector_product(os, &(cyl->xyz));
	coef.x = scalar_vector_product(crd, crd) - dot_dv * dot_dv;
	coef.y = 2.0f * (scalar_vector_product(crd, os) - dot_dv * scalar_vector_product(os, &(cyl->xyz)));
	coef.z = scalar_vector_product(os, os) - dot_ocv * dot_ocv - (cyl->diam / 2) * (cyl->diam / 2);
	if (!solve_quadro_eq(coef.x, coef.y, coef.z, points))
		return (-1);
	points[0] = nearest_distance(points);
	if (points[0] == -1)
		return (-1);
	if (pixel->cyl_m < 0 || pixel->cyl_m > cyl->heig)
		return (-1);
	return (points[0]);
}

static float define_dist_type_inters(t_pixel *pixel, float dist_plane, int type)
{
	float	dist;

	dist = dist_plane;
	pixel->cyl_type = type;
	return (dist);
}   

float check_intersection_cyl(t_cyl *cyl, t_pixel *pixel)
{
	float	dist;
	float	dist_plane;
	t_crd	orpoint;
	t_crd	direction;
	t_crd	point_end;
	
	pixel->cyl_type = NO_INTERSECT;
	vector_subtraction(&orpoint, &(pixel->ray.point[0]), &(cyl->point)); // vector from the cylinder's center point to the ray's starting point
	scalar_multiplication(&direction, &(pixel->coor), -1);				 // calculates the direction vector of the ray
	dist = intersection_cylinder_pipee(cyl, &direction, &orpoint, pixel);
	if (dist > 0)
		pixel->cyl_type = PIPE;
	define_cyl(cyl, &cyl->plato_begin, &cyl->point);
	dist_plane = intersection_cyl_plane(cyl, &cyl->plato_begin, &(pixel->ray), &pixel->coor);
	scalar_multiplication(&cyl->plato_begin.xyz, &cyl->plato_begin.xyz, -1);
	if (dist_plane != -1 && (dist_plane < dist || dist == -1))
		dist = define_dist_type_inters(pixel, dist_plane, PLANE_BEGIN);
	scalar_multiplication(&point_end, &cyl->xyz, cyl->heig);
	vector_addition(&point_end, &cyl->point, &point_end);
	define_cyl(cyl, &cyl->plato_end, &point_end);
	dist_plane = intersection_cyl_plane(cyl, &cyl->plato_end, &(pixel->ray), &(pixel->coor));
	if (dist_plane != -1 && (dist_plane < dist || dist == -1))
		dist = define_dist_type_inters(pixel, dist_plane, PLANE_END);
	return (dist);
	// to calculate the intersection point between a ray and a cylinder's pipe
}

t_cyl   *check_for_cilinder(t_data *data, t_pixel *pixel, float *dist)
{
	t_cyl	*cyl;
	t_cyl	*nearest_cyl;
	float	nearest_dist;

	cyl = data->scene->obj->cyl;
	nearest_dist = -1;
	nearest_cyl = 0;
	while (cyl)
	{
		*dist = check_intersection_cyl(cyl, pixel);
		if (*dist > 0 && (nearest_dist = -1 || *dist < nearest_dist ))
		{
			nearest_dist = *dist;
			nearest_cyl = cyl;
		}
		cyl = cyl->next;
	}
	*dist = nearest_dist;
	return (nearest_cyl);
}

