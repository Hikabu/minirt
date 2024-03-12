// #include "minirt.h"

// void	print_entire(t_entire **ent);

// void	id_check3(char **str, t_entire **ent)
// {
// 	void	*tmp;

// 	tmp = NULL;
// 	if (!ft_strcmp(str[0], "sp"))
// 	{
// 		if ((*ent)->sphere)
// 		{
// 			tmp = (*ent)->sphere;
// 			ft_lstadd_back_sphere(&((*ent)->sphere), to_struct_sp(str));
// 		}
// 		(*ent)->sphere = to_struct_sp(str);
// 		if (tmp)
// 			(*ent)->sphere = tmp;
// 	}
// 	else if (!ft_strncmp(str[0], "#", 1))
// 		return ;
// 	else
// 		error_with_free(*ent);
// }

// void	print_entire(t_entire **e)
// {
// 	t_entire *ent = *e;

// 	if(ent->amlight)
// 	{
// 		printf("\namlight\nid = %d\n", ent->amlight->id);
// 		printf("ratio = %f\n", ent->amlight->ratio);
// 		printf("rgb = %d,%d,%d\n", ent->amlight->rgb[0], ent->amlight->rgb[1], ent->amlight->rgb[2]);
// 	}
	
// // 	if(ent->scene->camera)
// // 	{
// // 		printf("\ncamera\nid = %d\n", ent->scene->camera->id);
// // 		printf("xyz = %f,%f,%f\n", ent->scene->camera->xyz[0], ent->scene->camera->xyz[1], ent->scene->camera->xyz[2]);
// // 		printf("norm_vec = %f,%f,%f\n", ent->scene->camera->norm_vec[0], ent->scene->camera->norm_vec[1], ent->scene->camera->norm_vec[2]);
// // 		printf("fov = %d\n", ent->scene->camera->fov);
// // 	}

// 	if(ent->light)
// 	{
// 		printf("\nlight\nid = %d\n", ent->light->id);
// 		printf("xyz = %f,%f,%f\n", ent->light->xyz[0], ent->light->xyz[1], ent->light->xyz[2]);
// 		printf("ratio = %f\n", ent->light->ratio);
// 		printf("rgb = %d,%d,%d\n", ent->light->rgb[0], ent->light->rgb[1], ent->light->rgb[2]);
// 	}

// 	while(ent->plane)
// 	{
// 		printf("\nplane\nid = %d\n", ent->plane->id);
// 		printf("xyz = %f,%f,%f\n", ent->plane->xyz[0], ent->plane->xyz[1], ent->plane->xyz[2]);
// 		printf("norm_vec = %f,%f,%f\n", ent->plane->norm_vec[0], ent->plane->norm_vec[1], ent->plane->norm_vec[2]);
// 		printf("rgb = %d,%d,%d\n", ent->plane->rgb[0], ent->plane->rgb[1], ent->plane->rgb[2]);
// 		ent->plane = ent->plane->next;
// 	}

// 	while(ent->cyl)
// 	{
// 		printf("\ncyl\nid = %d\n", ent->cyl->id);
// 		printf("xyz = %f,%f,%f\n", ent->cyl->xyz[0], ent->cyl->xyz[1], ent->cyl->xyz[2]);
// 		printf("norm_vec = %f,%f,%f\n", ent->cyl->norm_vec[0], ent->cyl->norm_vec[1], ent->cyl->norm_vec[2]);
// 		printf("diam = %f\n", ent->cyl->diam);
// 		printf("heig = %f\n", ent->cyl->heig);
// 		printf("rgb = %d,%d,%d\n", ent->cyl->rgb[0], ent->cyl->rgb[1], ent->cyl->rgb[2]);
// 		ent->cyl = ent->cyl->next;
// 	}

// 	while(ent->sphere)
// 	{
// 		printf("\nsphere\nid = %d\n", ent->sphere->id);
// 		printf("xyz = %f,%f,%f\n", ent->sphere->xyz[0], ent->sphere->xyz[1], ent->sphere->xyz[2]);
// 		printf("diametr = %f\n", ent->sphere->diametr);
// 		printf("rgb = %d,%d,%d\n", ent->sphere->rgb[0], ent->sphere->rgb[1], ent->sphere->rgb[2]);
// 		ent->sphere = ent->sphere->next;
// 	}

// }

// void	id_check2(char **str, t_entire **ent)
// {
// 	void	*tmp;

// 	tmp = NULL;
// 	if (!ft_strcmp(str[0], "cy"))
// 	{
// 		if ((*ent)->cyl)
// 		{
// 			tmp = (*ent)->cyl;
// 			ft_lstadd_back_cyl(&((*ent)->cyl), to_struct_cy(str));
// 		}
// 		(*ent)->cyl = to_struct_cy(str);
// 		if (tmp)
// 			(*ent)->cyl = tmp;
// 	}
// 	else
// 		id_check3(str, ent);
// }

// void	id_check1(char **str, t_entire **ent)
// {
// 	void	*tmp;

// 	tmp = NULL;
// 	if (!ft_strcmp(str[0], "L"))
// 	{
// 		if ((*ent)->light)
// 			error_with_free(*ent);
// 		(*ent)->light = to_struct_l(str);
// 	}
// 	else if (!ft_strcmp(str[0], "pl"))
// 	{
// 		if ((*ent)->plane)
// 		{
// 			tmp = (*ent)->plane;
// 			ft_lstadd_back_plane(&((*ent)->plane), to_struct_pl(str));
// 		}
// 		(*ent)->plane = to_struct_pl(str);
// 		if (tmp)
// 			(*ent)->plane = tmp;
// 	}
// 	else
// 		id_check2(str, ent);
// }

// void	id_check(char **str, t_entire **ent)
// { 
// 	if (!ft_strcmp(str[0], "A"))
// 	{
// 		if ((*ent)->amlight)
// 			error_with_free(*ent);
// 		(*ent)->amlight = to_struct_a(str);
// 	}
// 	else if (!ft_strcmp(str[0], "C"))
// 	{
// 		if ((*ent)->scene->camera)
// 			error_with_free(*ent);
// 		(*ent)->scene->camera = to_struct_c(str, (*ent)->scene);
// 		printf("camera after function %f\n", (*ent)->scene->camera_point.z);
// 	}
// 	else
// 		id_check1(str, ent);
// }
