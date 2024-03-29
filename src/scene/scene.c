/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:57:45 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/02/01 15:59:48 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

t_scene	*init_scene(t_camera *camera, t_sphere *sphere)
{
    t_scene *scene;

    scene  = malloc(sizeof(t_scene));
    if (!scene)
        error(1);
    scene->cameras = camera; 
}