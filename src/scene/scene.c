/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:57:45 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/02/01 15:59:48 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

t_scene	*init_scene(t_camera *camera, t_sphere *sphere, float width, float height)
{
    t_scene *scene;

    scene = malloc(sizeof(t_scene));
    if (!scene)
		error("no scene\n");
    scene->cameras = camera;
	scene->sphere = sphere;
	scene->width = width;
	scene->height = height;
	return (scene);
}