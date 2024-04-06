/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_cilinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:37:34 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/05 14:35:42 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_params(t_entire *ent, char *line)
{
	t_objj *objj;

	if (ft_strncmp(line, "A", 1) == 0) 
		return (parse_ambient(ent, line));
	if (ft_strncmp(line, "C", 1) == 0)
		return (parse_camera(ent, line));
	if (ft_strncmp(line, "L", 1) == 0)
		return (parse_light(ent, line));
	if (ft_strncmp(line, "sp", 2) == 0)
	{
		objj = create_object(ent, id_sphere);
		return(parse_sphere(ent, line, objj));
	}
	if (ft_strncmp(line, "pl", 2) == 0)
	{
		objj = create_object(ent, id_plane);
		return(parse_plane(ent, line, objj));
	}
	if (ft_strncmp(line, "cy", 2) == 0)
	{
		objj = create_object(ent, id_plane);
		return(parse_cylinder(ent, line, objj));
	}
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
	i = 1;
	while (params && params[i])
	{
		if (i == 1 && parse_float(params[i], &amlight->ratio))
			return (show_parsing_error(ent, params, ERR_NOT_A_FLOAT));
		if (i == 2 && parse_color(params[i], &amlight->rgb))
			return (show_parsing_error(ent, params, ERR_INVALID_NB_COLORS));
		i++;
	}
	amlight->color = rgb_to_int(amlight->rgb);
	ent->amlight = amlight;
	free_array(params);
	(void)mem;
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
	light->color = rgb_to_int(light->rgb);
	ent->light = light;	
	free_array(params);
	return (0);
}

int	parse_sphere(t_entire *ent, char *line, t_objj *objj)
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
	sphere->color = rgb_to_int(sphere->rgb);
	sphere->color_ambient = parser_return_color_ambient(sphere->color,
			 ent->amlight->color, ent->amlight->ratio);
	objj->object.sphere = *sphere;
	free_array(params);
	
	return (0);
}

int	parse_plane(t_entire *ent, char *line, t_objj *objj)
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
	plane->color = rgb_to_int(plane->rgb);
	norm_vector(&plane->norm_vec);
	objj->object.plane = *plane;
	free_array(params);
	return (0);
}

int parse_cylinder(t_entire *ent, char *line, t_objj *objj)
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
	cylinder->color = rgb_to_int(cylinder->rgb);
	norm_vector(&cylinder->norm_vec);
	// ent->cyl = cylinder;
	objj->object.cylinder = *cylinder;
	free_array(params);
	return (0);
}
void	initial_scene(t_entire *ent)
{
	ent->scene->camera_fov = 90; // default
	ent->scene->ambient_light_intensiv = 1;
	ent->scene->ambient_light_rgb = 0xffffff;
	ent->light = 0;
	ent->cyl = 0;
	ent->sphere = 0;
	ent->plane = 0;
}

void	push_object(t_objj *obj, t_objj **objs)
{
	t_objj	*tmp;

	if (!(*objs))
		*objs = obj;
	else
	{
		tmp = *objs;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = obj;
	}
}

t_objj	*create_object(t_entire *ent, t_object_id id)
{
	t_objj	*objj;

	objj = ft_calloc(sizeof(t_objj), 1);
	objj->id = id;
	push_object(objj, &ent->objj);
	ent->num_objs++;
	return (objj);
}