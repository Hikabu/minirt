/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:53:19 by vfedorov          #+#    #+#             */
/*   Updated: 2024/03/23 12:37:55 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int check_for_shadow_sphere(t_entire *data, t_ray *ray, t_crd *crd)
{
	t_sphere	*sphere;
	float		lenght;

	sphere = data->scene->obj->sphere;
	lenght = -1;
	while (sphere)
	{
		lenght = check_intersection_sphere(sphere, ray, crd);
		if (lenght > MIN_TRASHOLD && lenght < MAX_TRASHOLD)
			return (1);
		sphere = sphere->next;
	}
	return (0);
}

int	check_for_shadow_plane(t_entire *data, t_ray *ray, t_crd *crd)
{
	t_plane	*plane;
	float	lenght;

	plane = data->scene->obj->plane;
	lenght = -1;
	while (data)
	{
		lenght = check_intersection_plane(plane, ray, crd);
		if (lenght > MIN_TRASHOLD && lenght < MAX_TRASHOLD)
			return (1);
		plane = plane->next;
	}
	return (0);
}

int	check_for_shadow_cyl(t_entire *data, t_ray *ray, t_crd *crd)
{
	t_pixel	pixel;
	t_cyl	*cyl;
	float	dist;

	cyl = data->scene->obj->cyl;
	pixel.ray = *ray;
	pixel.coor = *crd;
	while (cyl)
	{
		dist = check_intersection_cyl(cyl, &pixel);
		if (dist > MIN_TRASHOLD && dist < MAX_TRASHOLD)
			return (1);
		pixel.ray = *ray;
		pixel.coor = *crd;
		cyl = cyl->next;		
	}
	return (0);
}
