/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:30:44 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/20 06:48:17 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minirt.h"

static void	free_spheres(t_objects *obj)
{
	t_sphere	*tmp;
	t_sphere	*tmp_prev;

	tmp = obj->spheres;
	while (tmp != NULL)
	{
		tmp_prev = tmp;
		tmp = tmp->next;
		free (tmp_prev);
	}
	obj->spheres = 0;
}

static void	free_planes(t_objects *obj)
{
	t_plane	*tmp;
	t_plane	*tmp_prev;

	tmp = obj->planes;
	while (tmp != NULL)
	{
		tmp_prev = tmp;
		tmp = tmp->next;
		free (tmp_prev);
	}
	obj->planes = 0;
}

static void	free_cyliners(t_objects *obj)
{
	t_cylinder	*tmp;
	t_cylinder	*tmp_prev;

	tmp = obj->cylinders;
	while (tmp != NULL)
	{
		tmp_prev = tmp;
		tmp = tmp->next;
		free (tmp_prev);
	}
	obj->cylinders = 0;
}

static void	free_lights(t_objects *obj)
{
	t_light	*tmp;
	t_light	*tmp_prev;

	tmp = obj->lights;
	while (tmp != NULL)
	{
		tmp_prev = tmp;
		tmp = tmp->next;
		free (tmp_prev);
	}
	obj->lights = 0;
}

void	free_scene(t_scene *scene)
{
	if (!scene)
		return ;
	if (scene->obj)
	{
		free_cyliners(scene->obj);
		free_lights(scene->obj);
		free_spheres(scene->obj);
		free_planes(scene->obj);
		free (scene->obj);
		scene->obj = 0;
	}
	free (scene);
	return ;
}
