/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:40:07 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/02/01 15:46:07 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*init_sphere(t_vector *center, float radius)
{
    t_sphere *sphere;
    
    sphere = malloc(sizeof(t_sphere));
    if (!sphere)
        error(1);
    sphere->center = center;
    sphere->radius = radius;
    return(sphere);
}