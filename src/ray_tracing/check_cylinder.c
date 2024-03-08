/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 00:42:25 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/03/06 16:47:30 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	chrck_intersection_cyl(t_cyl *cyl, t_pixel *pixel)
{
	float	dist;
	float	dist_plane;
	t_crd	orpoint;
	t_crd	direction;
	t_crd	point_end;

	pixel->cyl = NO_INTERSECT;
	vector_subtraction(&orpoint, &(pixel->ray.point[0]), &(cyl->point));
	scalar_multiplication(&direction, &(pixel->coor), -1);
	dist = intersection_cylinder_pippe(cyl, &dist, &orpoint, pixel);
	if (dist > 0)
		pixel->cyl_type = 1;
	define_cyl_plane(cyl, &cyl->plane)
}


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
	return (nearest_cyl)
}
