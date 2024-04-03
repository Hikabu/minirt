/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:53:19 by vfedorov          #+#    #+#             */
/*   Updated: 2024/04/03 12:26:11 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int check_for_shadow_sphere(t_entire *data, t_ray *ray, t_crd *crd)
{
	t_sphere	*sphere;
	float		lenght;

	sphere = data->sphere;
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
	t_plane	*pl;
	float	lenght;

	pl = data->plane;
	while (pl)
	{
		lenght = check_intersection_plane(pl, ray, crd);
		if (lenght > MIN_TRASHOLD && lenght < MAX_TRASHOLD) //filter out insignificant intersections 
			return (1);
		
		pl = pl->next;
	}
	return (0);
}

int	check_for_shadow_cyl(t_entire *data, t_ray *ray, t_crd *crd)
{
	t_pixel	pixel;
	t_cyl	*cyl;
	float	dist;

	cyl = data->cyl;
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
