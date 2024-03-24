/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_cilinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:37:34 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/03/24 13:24:58 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_params(t_entire *ent, char *line)
{
	if (ft_strncmp(line, "A", 1) == 0) 
		return (parse_ambient(ent, line));
	if (ft_strncmp(line, "C", 1) == 0)
		return (parse_camera(ent, line));
	if (ft_strncmp(line, "L", 1) == 0)
		return(parse_light(ent, line));
	if (ft_strncmp(line, "sp", 2) == 0)
		return(parse_sphere(ent, line));
	if (ft_strncmp(line, "pl", 2) == 0)
		return(parse_plane(ent, line));
	if (ft_strncmp(line, "cy", 2) == 0)
		return(parse_cylinder(ent, line));
	return (0);
}

int parse_camera(t_entire *ent, char *line)
{
	char **params;
	int i;
	t_camera *camera = malloc(sizeof(t_camera));
	if (!camera)
		return 1;
	params = ft_split(line, ' ');
	// if (ent->camera && ent->camera->id)
	// 	return (show_parsing_error(ent, params, ERR_TOO_MANY_CAMERAS));
	if (array_length(params) != 4)
		return (show_parsing_error(ent, params, ERR_INVALID_NB_PARAMS));
	ft_bzero(camera, sizeof(t_camera));
	camera->id = id_camera;
	i = 1;
	while (params && params[i])
	{
		if (i == 1 && parse_vector(params[i], &camera->xyz))
			return (show_parsing_error(ent, params, ERR_INVALID_NB_COORDS));
		if (i == 2 && parse_vector(params[i], &camera->norm_vec))
			return (show_parsing_error(ent, params, ERR_INVALID_NB_ORIENT));
		if (i == 3 && parse_ulong(params[i], &camera->fov))
			return (show_parsing_error(ent, params, ERR_NOT_A_ULONG));
		i++;
	}
	norm_vector(&camera->norm_vec);
	ent->camera = camera;
	// if (camera)
	// 	free(camera);    //no free
	free_array(params);
	return (0);
}

void float_range_checker(float *key, float value, int flag_range)
{
	if ((flag_range == 1 && (value >= 0 && value <= 1)) || (flag_range == 2 && (value >= -1 && value <= 1)))
		*key = value;
	else
		error(1);
}
int parse_ambient(t_entire *ent, char *line)
{
	char **params;
	t_amlight *amlight = malloc(sizeof(t_amlight));
	if (!amlight)
		return 1;
	int i;
	ent->amlight = 0;
	char **mem;
	params = ft_split(line, ' ');
	mem = ft_split(params[2], ',');
	if (ent->amlight && ent->amlight->id)
		return (show_parsing_error(ent, params, ERR_TOO_MANY_AMBIENTS));
	if (array_length(params) != 3)
		return (show_parsing_error(ent, params, ERR_INVALID_NB_PARAMS));
	ft_bzero(amlight, sizeof(t_amlight));
	// amlight->id = id_ambient;
	i = 1;
	while (params && params[i])
	{
		if (i == 1 && parse_float(params[i], &amlight->ratio))
			return (show_parsing_error(ent, params, ERR_NOT_A_FLOAT));
		if (i == 2 && parse_color(params[i], &amlight->rgb))
			return (show_parsing_error(ent, params, ERR_INVALID_NB_COLORS));
		i++;
	}
	ent->amlight = amlight;
	if (amlight)
		free(amlight);
	free_array(params);
	(void)mem;
	// free_array(mem);
	return (0);
}

int	parse_light(t_entire *ent, char *line)
{
	char **params;
	t_light *light = malloc(sizeof(t_light));
	if (!light)
		return 1;
	int i;

	params = ft_split(line, ' ');
	if (array_length(params) != 4)
		return (show_parsing_error(ent, params, ERR_INVALID_NB_PARAMS));
	ft_bzero(light, sizeof(t_light));
	light->id = id_light;
	i = 1;

	while (params && params[i])
	{
		if (i == 1 && parse_vector(params[i], &light->xyz))
			return (show_parsing_error(ent, params, ERR_INVALID_NB_COORDS));
		if (i == 2 && parse_float(params[i], &light->ratio))
			return (show_parsing_error(ent, params, ERR_NOT_A_FLOAT));
		if (i == 3 && parse_color(params[i], &light->rgb))
			return (show_parsing_error(ent, params, ERR_INVALID_NB_COLORS));
		i++;
	}
	ent->light = light;	
	if (light)
		free(light);
	free_array(params);
	return (0);
}

int	parse_sphere(t_entire *ent, char *line)
{
	char **params;
	t_sphere *sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return 1;
	int i;
	params = ft_split(line, ' ');
	if (array_length(params) != 4)
		return (show_parsing_error(ent, params, ERR_INVALID_NB_PARAMS));
	ft_bzero(sphere, sizeof(t_sphere));
	sphere->id = id_sphere;
	i = 1;
	while (params && params[i])
	{
		if (i == 1 && parse_vector(params[i], &sphere->xyz))
			return (show_parsing_error(ent, params, ERR_INVALID_NB_COORDS));
		if (i == 2 && parse_float(params[i], &sphere->diametr))
			return (show_parsing_error(ent, params, ERR_NOT_A_FLOAT));
		if (i == 3 && parse_color(params[i], &sphere->rgb))
			return (show_parsing_error(ent, params, ERR_INVALID_NB_COLORS));
		i++;
	}
	ent->sphere = sphere;
	if (sphere)
		free(sphere);
	free_array(params);
	return (0);
}

int	parse_plane(t_entire *ent, char *line)
{
	char **params;
	t_plane *plane = malloc(sizeof(t_plane));
	if (!plane)
		return 1;
	int i;
	params = ft_split(line, ' ');
	if (array_length(params) != 4)
		return (show_parsing_error(ent, params, ERR_INVALID_NB_PARAMS));
	ft_bzero(plane, sizeof(t_plane));
	plane->id = id_plane;
	i = 1;
	while (params && params[i])
	{
		if (i == 1 && parse_vector(params[i], &plane->xyz))
			return (show_parsing_error(ent, params, ERR_INVALID_NB_COORDS));
		if (i == 2 && parse_vector(params[i], &plane->norm_vec))
			return (show_parsing_error(ent, params, ERR_INVALID_NB_ORIENT));
		if (i == 3 && parse_color(params[i], &plane->rgb))
			return (show_parsing_error(ent, params, ERR_INVALID_NB_COLORS));
		i++;
	}
	norm_vector(&plane->norm_vec);
	ent->plane = plane;
	if (plane)
		free(plane);
	free_array(params);
	return (0);
}

int parse_cylinder(t_entire *ent, char *line)
{
	char **params;
	t_cyl *cylinder = malloc(sizeof(t_cyl));
	if (!cylinder)
		return 1;
	int i;

	params = ft_split(line, ' ');
	if (array_length(params) != 6)
		return (show_parsing_error(ent, params, ERR_INVALID_NB_PARAMS));
	ft_bzero(cylinder, sizeof(t_cyl));
	cylinder->id = id_cyl;
	i = 1;

	while (params && params[i])
	{
		if (i == 1 && parse_vector(params[i], &cylinder->xyz))
			return (show_parsing_error(ent, params, ERR_INVALID_NB_COORDS));
		if (i == 2 && parse_vector(params[i], &cylinder->norm_vec))
			return (show_parsing_error(ent, params, ERR_INVALID_NB_ORIENT));
		if (i == 3 && parse_float(params[i], &cylinder->diam))
			return (show_parsing_error(ent, params, ERR_NOT_A_FLOAT));
		if (i == 4 && parse_float(params[i], &cylinder->heig))
			return (show_parsing_error(ent, params, ERR_NOT_A_FLOAT));
		if (i == 5 && parse_color(params[i], &cylinder->rgb))
			return (show_parsing_error(ent, params, ERR_INVALID_NB_COLORS));
		i++;
	}

	norm_vector(&cylinder->norm_vec);
	ent->cyl = cylinder;
	if (cylinder)
		free(cylinder);
	free_array(params);
	return (0);
}
void	initial_scene(t_entire *ent, t_scene *scene)
{
	// printf("camera fow is %f\n", scene->camera_fov);
	fill_new_vector(&scene->camera_point, 0, 0, 0);
	fill_new_vector(&scene->camera_orientation, 0, 0, 1);
	scene->camera_fov = 90; // default
	scene->ambient_light_intensiv = 1;
	scene->ambient_light_rgb = 0xffffff;
	scene->obj->light = 0;
	scene->obj->cyl = 0;
	scene->obj->sphere = 0;
	scene->obj->plane = 0;
	//  if (ent->camera) 
    //     scene->camera_fov = ent->camera->fov;
	ent->scene = scene;
	// scene->camera_fov = ent->camera->fov;
	// scene->obj = ent->
	// printf("address of scene %p\n", scene);x
	// printf ("what is in the road %f\n", scene->camera_point.z);
}
