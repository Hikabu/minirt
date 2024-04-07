/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 00:45:22 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/07 21:11:08 by vfedorov         ###   ########.fr       */
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
	t_crd	orpoint;

	// printf("sphere is color %d\n", sphere->color);
	vector_subtraction(&orpoint, &sphere->xyz, &(ray->point[0]));

	float f1 = scalar_vector_product(rd, rd);
	printf("f1 = %f\n", f1);
	float f2 = 2 * scalar_vector_product(rd, &orpoint) + 10;
	printf("f2 = %f\n", f2);
	float f3 = scalar_vector_product(&orpoint, &orpoint) - ((sphere->diametr /2) * (sphere->diametr / 2));
	printf("f3 = %f\n", f3);

	if ((!(int)solve_quadro_eq(f1, f2, f3, points) && printf("stex\n")) || !printf("points[0] = %f, points[1] = %f\n", points[0], points[1]) || (points[0] < 0.0f && points[1] < 0.0f && printf("@ndex\n")))
	{
		printf("INIF\n");
		return (-1);
		
	}
		
	printf("----WORKING-----\n");
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

	// sphere = data->sphere;
	closest_sphere = 0;
	lenght = -1;

    t_objj *current = data->objj; //
	// while (sphere)
	// printf("current = %p" , current);
    while (current != NULL) //
	{
		t_sphere *sphere; //
		sphere = (t_sphere *)&(current->object.sphere);
		// printf ("in sphere color = %d\n", current->object.sphere.color);
		// printf("printf( = %d\n", sphere->color);
		tmp = check_intersection_sphere(sphere, ray, rd);
		printf ("tmp = %f\n", tmp);
		exit(1); // TODO delete thbis line
		if (tmp > 0 && (lenght == -1 || tmp < lenght))
		{
			printf("if (tmp > 0 && (lenght == -1 || tmp < lenght))");
			lenght = tmp;
			// closest_sphere = spher
			closest_sphere = (t_sphere *)&(current->object.sphere);
		}	
		// sphere = sphere->next;
        current = current->next; //
		printf ("im here\n");
		printf ("closest sphere color = %d\n", closest_sphere->color);
	}
	*dist = lenght;
	return (closest_sphere);
}


