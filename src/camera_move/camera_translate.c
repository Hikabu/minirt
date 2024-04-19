/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:32:14 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/19 18:32:15 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "minirt.h"

/**	rotation matrix*/

void	translate_objects(t_scene *scene, t_coord *coord)
{
	t_objects	obj;

	obj = *scene->obj;
	while (obj.spheres)
	{
		vector_subtraction(&obj.spheres->point, &obj.spheres->point, coord);
		obj.spheres = obj.spheres->next;
	}
	while (obj.planes)
	{
		vector_subtraction(&obj.planes->point, &obj.planes->point, coord);
		obj.planes = obj.planes->next;
	}
	while (obj.cylinders)
	{
		vector_subtraction(&obj.cylinders->point, &obj.cylinders->point, coord);
		obj.cylinders = obj.cylinders->next;
	}
	while (obj.lights)
	{
		vector_subtraction(&obj.lights->point, &obj.lights->point, coord);
		obj.lights = obj.lights->next;
	}
}
