/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 00:42:25 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/03/09 19:12:16 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// static void	define_cul(t_cyl *cyl, t_plato *plane, t_crd, *point)
// {
// 	plane->point = *point;
// 	plane->color = cyl->color;
// 	plane->orient = cyl->orient;
// 	plane->color_amb = cyl->color;
// }

// float	chrck_intersection_cyl(t_cyl *cyl, t_pixel *pixel)
// {
// 	float	dist;
// 	// float	dist_plane;
// 	t_crd	orpoint;
// 	t_crd	direction;
// 	t_crd	point_end;

// 	pixel->cyl = NO_INTERSECT;
// 	// vector_subtraction(&orpoint, &(pixel->ray.point[0]), &(cyl->point));   vector from the cylinder's center point to the ray's starting point
// 	scalar_multiplication(&direction, &(pixel->coor), -1); //calculates the direction vector of the ray
// 	dist = intersection_cylinder_pippe(cyl, &dist, &orpoint, pixel);
// 	if (dist > 0)
// 		pixel->cyl_type = 1;
// 	define_cyl(cyl, &cyl->plato_begin, &cyl->point);
	
// 	// to calculate the intersection point between a ray and a cylinder's pipe
// }


// 	define_cylinder_plane(cylinder, &cylinder->plane_begin, &cylinder->point);
// 	dist_plane = intersection_cylinder_plane(cylinder,
// 			&cylinder->plane_begin, &(pixel->ray), &(pixel->d));
// 	scalar_multiplication(&cylinder->plane_begin.orientation,
// 		&cylinder->plane_begin.orientation, -1);
// 	if (dist_plane != -1 && (dist_plane < dist || dist == -1))
// 		dist = define_dist_type_intersection(pixel, dist_plane, PLANE_BEGIN);
// 	scalar_multiplication(&point_end, &cylinder->orientation, cylinder->height);
// 	vector_addition(&point_end, &cylinder->point, &point_end);
// 	define_cylinder_plane(cylinder, &cylinder->plane_end, &point_end);
// 	dist_plane = intersection_cylinder_plane(cylinder,
// 			&cylinder->plane_end, &(pixel->ray), &(pixel->d));
// 	if (dist_plane != -1 && (dist_plane < dist || dist == -1))
// 		dist = define_dist_type_intersection(pixel, dist_plane, PLANE_END);
// 	return (dist);
// }

// t_cyl   *check_for_cilinder(t_data *data, t_pixel *pixel, float *dist)
// {
//     t_cyl	*cyl;
// 	t_cyl	*nearest_cyl;
// 	float	nearest_dist;

// 	cyl = data->scene->obj->cyl;
// 	nearest_dist = -1;
// 	nearest_cyl = 0;
// 	while (cyl)
// 	{
// 		*dist = check_intersection_cyl(cyl, pixel);
// 		if (*dist > 0 && (nearest_dist = -1 || *dist < nearest_dist ))
// 		{
// 			nearest_dist = *dist;
// 			nearest_cyl = cyl;
// 		}
// 		cyl = cyl->next;
// 	}
// 	*dist = nearest_dist;
// 	return (nearest_cyl);
// }
