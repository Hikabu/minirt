/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_readscene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:30:59 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/23 12:21:52 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parser_readambient(t_parser *p)
{
	if ((p->readelem) & 1)
		parser_error(1, p);
	p->readelem |= 1;
	(p->i)++;
	parser_error_space(p);
	p->scene->ambient_light_intensity = parser_readfloat(p);
	parser_error_space(p);
	if (p->scene->ambient_light_intensity > 1
		|| p->scene->ambient_light_intensity < 0 || !ft_isdigit(p->str[p->i]))
		parser_error(1, p);
	p->scene->ambient_light_rgb = parser_readcolor(p);
	parser_skipspaces(p->str, &(p->i));
	if (p->str[p->i])
		parser_error(1, p);
}

void	parser_readcamera(t_parser *p)
{
	if ((p->readelem) & 2)
		parser_error(1, p);
	p->readelem |= 2;
	(p->i)++;
	parser_error_space(p);
	p->scene->camera_point = parser_readcoord(p);
	parser_error_space(p);
	p->scene->camera_orientation = parser_readcoord(p);
	parser_is_norm(p, p->scene->camera_orientation);
	normalizing_vector(&p->scene->camera_orientation,
		&p->scene->camera_orientation);
	parser_error_space(p);
	p->scene->camera_fov = parser_readfloat(p);
	parser_skipspaces(p->str, &(p->i));
	if (p->str[p->i] || p->scene->camera_fov > 180 || p->scene->camera_fov < 0)
		parser_error(1, p);
}

static t_light	*parser_addlight(t_parser *p)
{
	t_light	*light;

	if (!p->scene->obj->lights)
	{
		p->scene->obj->lights = (t_light *) malloc (sizeof(t_light));
		if (!(p->scene->obj->lights))
			parser_error (12, p);
		p->scene->obj->lights->next = 0;
		return (p->scene->obj->lights);
	}
	light = p->scene->obj->lights;
	while (!light && !light->next)
		light = light->next;
	light->next = (t_light *) malloc (sizeof(t_light));
	if (!(light->next))
		parser_error (12, p);
	light->next->next = 0;
	return (light->next);
}

void	parser_readlight(t_parser *p)
{
	t_light	*light;

	if ((p->readelem) & 4)
		parser_error(1, p);
	p->readelem |= 4;
	light = parser_addlight(p);
	(p->i)++;
	parser_error_space(p);
	light->point = parser_readcoord (p);
	parser_error_space(p);
	light->lighting_ratio = parser_readfloat(p);
	parser_error_space(p);
	if (light->lighting_ratio > 1 || light->lighting_ratio < 0)
		parser_error(1, p);
	if (!p->str[p->i])
		return ;
	if (!ft_isdigit(p->str[p->i]))
		parser_error(1, p);
	light->color = parser_readcolor(p);
	parser_skipspaces(p->str, &(p->i));
	if (p->str[p->i])
		parser_error(1, p);
}

void	get_fov_angles(t_scene *scene)
{
	scene->camera_angles[0] = tan(scene->camera_fov * M_PI / 360);
	scene->camera_angles[1] = (scene->camera_angles[0]
			* (((float) HEIGHT) / ((float) WIDTH)));
}
