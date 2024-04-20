/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotation_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:32:10 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/20 06:58:16 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "../../include/transformation.h"

static void	rotate_vector_with_mtx(t_coord *res,
	t_coord *vec, float rotation_mtx[3][3])
{
	t_coord	vec_copy;

	if (!res || !vec || !rotation_mtx)
		return ;
	vec_copy = *vec;
	res->x = vec_copy.x * rotation_mtx[0][0] + vec_copy.y * rotation_mtx[0][1]
		+ vec_copy.z * rotation_mtx[0][2];
	res->y = vec_copy.x * rotation_mtx[1][0] + vec_copy.y * rotation_mtx[1][1]
		+ vec_copy.z * rotation_mtx[1][2];
	res->z = vec_copy.x * rotation_mtx[2][0] + vec_copy.y * rotation_mtx[2][1]
		+ vec_copy.z * rotation_mtx[2][2];
}

static void	rotate_objects_cylinders_lights(t_objects *obj,
	float rotation_matrix[3][3])
{
	while (obj->cylinders)
	{
		rotate_vector_with_mtx(&obj->cylinders->point,
			&obj->cylinders->point, rotation_matrix);
		rotate_vector_with_mtx(&obj->cylinders->orientation,
			&obj->cylinders->orientation, rotation_matrix);
		normalizing_vector(&obj->cylinders->orientation,
			&obj->cylinders->orientation);
		obj->cylinders = obj->cylinders->next;
	}
	while (obj->lights)
	{
		rotate_vector_with_mtx(&obj->lights->point,
			&obj->lights->point, rotation_matrix);
		obj->lights = obj->lights->next;
	}
}

static void	rotate_objects_speres_planes(t_objects *obj,
	float rotation_matrix[3][3])
{
	while (obj->spheres)
	{
		rotate_vector_with_mtx(&obj->spheres->point,
			&obj->spheres->point, rotation_matrix);
		obj->spheres = obj->spheres->next;
	}
	while (obj->planes)
	{
		rotate_vector_with_mtx(&obj->planes->point,
			&obj->planes->point, rotation_matrix);
		rotate_vector_with_mtx(&obj->planes->orientation,
			&obj->planes->orientation, rotation_matrix);
		normalizing_vector(&obj->planes->orientation,
			&obj->planes->orientation);
		obj->planes = obj->planes->next;
	}
}

void	apply_rotation_to_objects(t_coord *cam, t_objects *obj,
	float rotation_matrix[3][3])
{
	rotate_vector_with_mtx(cam, cam, rotation_matrix);
	rotate_objects_speres_planes(obj, rotation_matrix);
	rotate_objects_cylinders_lights(obj, rotation_matrix);
}
