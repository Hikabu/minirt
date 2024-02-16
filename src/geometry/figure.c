/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <armgevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:40:07 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/02/16 17:22:08 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*init_sphere(t_vector *center, float radius)
{
    t_sphere *sphere;
    
    sphere = malloc(sizeof(t_sphere));
    if (!sphere)
        error(1);
	printf("merged?");
    sphere->center = center;
    sphere->radius = radius;
    return(sphere);
}