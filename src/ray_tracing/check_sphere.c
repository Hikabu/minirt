/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 00:45:22 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/08 22:20:01 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


/* mathematical equation of a sphere
	(x - c_x)^2 + (y - c_y)^2 + (z - c_z)^2 = r^2
	(c_x, c_y, c_z) is the center of the sphere and r is its radius.
	to check for intersection between a ray and a sphere,we use  parametric equation of a ray
	P = O + t * D (P is a point on the ray, O is the origin of the ray, D is its direction,
	 and t is a parameter that varies along the length of the ray.
	so
	Solving this quadratic equation for t gives us the values of t at which
	 the ray intersects the sphere. If there are no real roots, the ray does 
	 not intersect the sphere. If there are two roots- ray intersects 
	 the sphere at two points (entering and exiting). If - one root, 
	  the ray is tangent to the sphere at that point.
*/

float	check_intersection_sphere(t_sphere *sphere, t_ray *ray, t_crd *rd)
{
	float	points[2];
	t_crd	orpoint; //points from the ray's starting point towards the center of the sphere.

	vector_subtraction(&orpoint, &sphere->xyz, &(ray->point[0]));
	float f1 = scalar_vector_product(rd, rd);
	float f2 = 2 * scalar_vector_product(rd, &orpoint);
	float f3 = scalar_vector_product(&orpoint, &orpoint) - ((sphere->diametr /2) * (sphere->diametr / 2));

	if ((!(int)solve_quadro_eq(f1, f2, f3, points) ))
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


t_sphere	*check_for_spheres(t_entire *data, t_ray *ray, t_crd *rd, float *dist)
{
	t_sphere	*closest_sphere;
	float		tmp;
	float		lenght;
	
	closest_sphere = 0;
	lenght = -1;

    t_objj *current = data->objj; ///
    while (current != NULL)
	{
		t_sphere *sphere;
		sphere = (t_sphere *)&(current->object.sphere);
		tmp = check_intersection_sphere(sphere, ray, rd);
		if (tmp > 0 && (lenght == -1 || tmp < lenght))
		{
			lenght = tmp;
			closest_sphere = (t_sphere *)&(current->object.sphere);
		}	
        current = current->next;
	}
	*dist = lenght;
	return (closest_sphere);
}


