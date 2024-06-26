/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:30:33 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/22 14:09:30 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	define_nearest_objects(t_entire *global, t_pixel *pixel);

void	ft_search_objects(int x, int y, t_entire *global)
{
	t_pixel	pixel;
	float	lambda;

	global->prev_keyhook = 0;
	global->nearest_obj = NULL;
	lambda = 2 * global->scene->camera_angles[0] / WIDTH;
	pixel_cleaning(&pixel);
	new_vector(&pixel.ray.point[0], 0, 0, -1);
	new_vector(&(pixel.ray.point[1]),
		-global->scene->camera_angles[0] + lambda * x,
		global->scene->camera_angles[1] - lambda * y, 0);
	check_intersection(global, &pixel);
	define_nearest_objects(global, &pixel);
}

static void	define_nearest_objects(t_entire *global, t_pixel *pixel)
{
	if (pixel->sphere != NULL)
	{
		global->nearest_obj = pixel->sphere;
		global->nearest_type = SPHERE;
		print_spheres((t_sphere *)global->nearest_obj, 'o');
	}
	else if (pixel->plane != NULL)
	{
		global->nearest_obj = pixel->plane;
		global->nearest_type = PLANE;
		print_planes((t_plane *)global->nearest_obj, 'o');
	}
	else if (pixel->cylinder != NULL)
	{
		global->nearest_obj = pixel->cylinder;
		global->nearest_type = CYLINDER;
		print_cylinders((t_cylinder *)global->nearest_obj, 'o');
	}
}
