/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_pixel_plane.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:31:37 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/20 07:00:19 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	pixel_computing_plane_diffusal_recflect_ratio(t_global *global,
	t_pixel *pixel)
{
	t_coord	light_direction;
	t_coord	normal;
	float	light_intensity;

	normal = pixel->plane->orientation;
	vector_subtraction(&light_direction, &global->scene->obj->lights->point,
		&pixel->intersection);
	normalizing_vector(&light_direction, &light_direction);
	light_intensity = angle_between_2_vectors(&light_direction, &normal)
		* global->scene->obj->lights->lighting_ratio;
	if (light_intensity > 0)
		return (light_intensity);
	return (-light_intensity);
}

void	pixel_computing_plane(t_global *global, t_pixel *pixel)
{
	int		light;
	float	lightning_ratio;

	ft_mlx_pixel_put_img(&global->img, pixel->x, pixel->y,
		pixel->plane->color_ambient);
	if (!global->scene->obj->lights || check_for_shadow(global, pixel))
		return ;
	lightning_ratio = pixel_computing_plane_diffusal_recflect_ratio
		(global, pixel);
	if (lightning_ratio <= 0)
		return ;
	light = color_diffusal(pixel->plane->color_ambient, pixel->plane->color,
			global->scene->obj->lights->color, lightning_ratio);
	ft_mlx_pixel_put_img(&global->img, pixel->x, pixel->y, light);
	return ;
}
