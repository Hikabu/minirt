/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:18:57 by timelkon          #+#    #+#             */
/*   Updated: 2024/02/27 14:19:00 by timelkon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	sphere_intersect(t_camera *camera, t_vector *ray, t_sphere *sphere)
{
	float	b;
	float	c;
	float	discrim;
	float	dist_1;
	float	dist_2;
	t_vector	*cam_sphere;

	dist_1 = 0;
	dist_2 = 0;
	cam_sphere = vecsubtraction(camera->origin, sphere->center);
	b = 2 * (vec_product(cam_sphere, ray));
	c = vec_product(cam_sphere, cam_sphere) - (sphere->radius * sphere->radius);
	discrim = (b * b) - (4 * c);
	free(cam_sphere);
	if (discrim < 0)
		return (0);
	dist_1 = ((b * (-1)) - sqrt(discrim)) / 2;
	dist_2 = ((b * (-1)) + sqrt(discrim)) / 2;
	if (dist_1 > 0)
		return (1);
	return (0);
}