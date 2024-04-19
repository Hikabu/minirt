/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:35:59 by vfedorov          #+#    #+#             */
/*   Updated: 2024/03/15 21:17:07 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	translate_obj(t_objj *objj, t_crd *crd)
{
    // t_objj   *obj;
	printf ("im here\n");
	printf ("obj %f\n", objj->object.sphere.xyz.z);
	printf ("objl %f\n", objj->sphere->xyz.x);
    // obj = objj->object;
	objj->sphere = &objj->object.sphere;
    while (objj->sphere)
    {
        vector_subtraction(&objj->sphere->xyz, &objj->sphere->xyz, crd);
        objj->sphere = objj->sphere->next;
    }
    while (objj->plane)
    {
        vector_subtraction(&objj->plane->xyz, &objj->plane->xyz, crd);
        objj->plane = objj->plane->next;
    }
    // while (objj->cyl)
    // {
    //     vector_subtraction(&objj->cyl->xyz, &objj->cyl->xyz, crd);
    //     objj->cyl = objj->cyl->next;
    // }

    // while (objj.light)
    // {
    //     vector_subtraction(&objj.light->xyz, &objj.light->xyz, crd);
    //     // obj.light = obj.light->next;
    // }
}


static void	fill_angles(t_crd *r_sin, t_crd *r_cos, t_crd *cam)
{
	*r_sin = *cam;
	fill_new_vector(r_cos, 0, 0, 1);
	vector_multiplication(r_sin, r_cos, r_sin);
	r_cos->x = cos(asin(r_sin->x));
	r_cos->y = cos(asin(r_sin->y));
	r_cos->z = cos(asin(r_sin->z));
}

static void	fill_rotation_matrix(float rotation_matrix[3][3], t_crd *coord)
{
	t_crd	r_cos;
	t_crd	r_sin;

	fill_angles(&r_sin, &r_cos, coord);
	rotation_matrix[0][0] = r_cos.y * r_cos.z;
	rotation_matrix[0][1] = -r_sin.z * r_cos.y;
	rotation_matrix[0][2] = r_sin.y;
	rotation_matrix[1][0] = r_sin.x * r_sin.y * r_cos.z + r_sin.z * r_cos.x;
	rotation_matrix[1][1] = -r_sin.x * r_sin.y * r_sin.z + r_cos.x * r_cos.z;
	rotation_matrix[1][2] = -r_sin.x * r_cos.y;
	rotation_matrix[2][0] = r_sin.x * r_sin.z - r_sin.y * r_cos.x * r_cos.z;
	rotation_matrix[2][1] = r_sin.x * r_cos.z + r_sin.y * r_sin.z * r_cos.x;
	rotation_matrix[2][2] = r_cos.x * r_cos.y;
}

void	rotate_obj(t_entire *scene, t_crd *coord)
{
	t_objj		obj;
	t_crd		tmp;
	float		rotation_matrix[3][3];

	// obj = *scene->obj;
	if (coord->z < 0)
	{
		fill_new_vector(&tmp, 0, 0, 1);
		fill_rotation_matrix(rotation_matrix, &tmp);
		rotation_matrix[1][1] = -1;
		rotation_matrix[2][2] = -1;
		apply_rotation_to_objects(&scene->camera->norm_vec,
			&obj, rotation_matrix);
	}
	fill_rotation_matrix(rotation_matrix, coord);
	apply_rotation_to_objects(&scene->camera->norm_vec,
		&obj, rotation_matrix); 
}

