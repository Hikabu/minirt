#include "minirt.h"

static void	rotate_vector_with_mtx(t_crd *res, t_crd *vec, float rotation_mtx[3][3])
{
	t_crd	vec_copy;

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

static void	rotate_objects_speres_planes(t_objj *obj,
	float rotation_matrix[3][3])
{
	while (obj->sphere)
	{
		rotate_vector_with_mtx(&obj->sphere->xyz,
			&obj->sphere->xyz, rotation_matrix);
		obj->sphere = obj->sphere->next;
	}
	while (obj->plane)
	{
		rotate_vector_with_mtx(&obj->plane->xyz,
			&obj->plane->xyz, rotation_matrix);
		rotate_vector_with_mtx(&obj->plane->norm_vec,
			&obj->plane->norm_vec, rotation_matrix);
		norm_vector(&obj->plane->norm_vec);
		obj->plane = obj->plane->next;
	}
}

static void	rotate_objects_cylinders_lights(t_objj *obj,
	float rotation_matrix[3][3])
{
	while (obj->cylinder)
	{
		rotate_vector_with_mtx(&obj->cylinder->xyz,
			&obj->cylinder->xyz, rotation_matrix);
		rotate_vector_with_mtx(&obj->cylinder->norm_vec,
			&obj->cylinder->norm_vec, rotation_matrix);
		norm_vector(&obj->cylinder->norm_vec);
		obj->cylinder = obj->cylinder->next;
	}
	// while (obj->light)
	// {
	// 	rotate_vector_with_mtx(&obj->light->xyz,
	// 		&obj->light->xyz, rotation_matrix);
	// 	// obj->light = obj->light->next;
	// }
}


void	apply_rotation_to_objects(t_crd *cam, t_objj *obj,
	float rotation_matrix[3][3])
{
	rotate_vector_with_mtx(cam, cam, rotation_matrix);
	rotate_objects_speres_planes(obj, rotation_matrix);
	rotate_objects_cylinders_lights(obj, rotation_matrix);
}

