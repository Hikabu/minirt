/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 00:45:22 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/03/05 00:59:04 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	check_intersection_sphere(t_sphere *sphere, t_ray *ray, t_crd *rd)
{
	float	points[2];
	t_crd	os;

vector_subtraction(&os, &sphere->point, &(ray->point[0]));
if (!solve_quadro_eq(scalar_vector_product(rd, rd),
		2 * scalar_vector_product(rd, &os), 
		scalar_vector_product(&os, &os)
		- ((sphere->diametr /2) * (sphere->diametr / 2)), 
		points) || (points[0] < 0 && points[1] < 0))
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


t_sphere	*check_for_spheres(t_data *data, t_ray *ray, t_crd *rd, float *dist)
{
	t_sphere	*sphere;
	t_sphere	*closest_sphere;
	float		tmp;
	float		lenght;

	sphere = data->scene->obj->sphere;
	closest_sphere = 0;
	lenght = -1;
	while (sphere)
	{
		tmp = check_intersection_sphere(sphere, ray, rd);
		if (tmp > 0 && (lenght == -1 || tmp < lenght))
		{
			lenght = tmp;
			closest_sphere = sphere;
		}	
		sphere = sphere->next;
	}
	*dist = lenght;
	return (closest_sphere);
}


